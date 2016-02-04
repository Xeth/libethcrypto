
namespace Ethereum{

template<class KDF>
std::string CipherName(const AesCipher<KDF> &)
{
    return "aes-128-ctr";
}

inline std::string CipherName(const DummyCipher &)
{
    return "dummy";
}

template<class Cipher>
Json::Value PrivateKeySerializer<Cipher>::serializeToJson(const SecuredPrivateKey<Cipher> &key) const
{
    const Cipher & cipher = key.getCipher();
    const typename Cipher::KdfParams & kdfParams = cipher.getParams();

    Json::Value json;
    json["cipher"] = CipherName(cipher);
    json["ciphertext"] = EncodeHex(key.getData().data);
    json["cipherparams"] = serializeCipherParams(cipher);
    json["kdfparams"] = serializeKDF(kdfParams);
    json["kdf"] = KdfName(kdfParams);
    json["mac"] = EncodeHex(key.getData().mac);
    return json;
}


template<class Cipher>
Json::Value PrivateKeySerializer<Cipher>::serializeCipherParams(const Cipher &cipher) const
{
    Json::Value result;
    result["iv"] = EncodeHex(cipher.getIV());
    return result;
}


template<class Cipher>
SecuredPrivateKey<Cipher> PrivateKeySerializer<Cipher>::unserialize(const std::string &serialized) const
{
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(serialized, json, false))
    {
        throw std::runtime_error("invalid json");
    }

    return unserialize(json);
}

template<class Cipher>
SecuredPrivateKey<Cipher> PrivateKeySerializer<Cipher>::unserialize(const Json::Value &serialized) const
{
    return SecuredPrivateKey<Cipher>
    (
        EncryptedData(DecodeHex(serialized["ciphertext"].asString()), DecodeHex(serialized["mac"].asString())),
        Cipher(DecodeHex(serialized["cipherparams"]["iv"].asString()), unserializeKDF(serialized["kdfparams"]))
    );
}



template<class Cipher>
std::string PrivateKeySerializer<Cipher>::serialize(const SecuredPrivateKey<Cipher> &key) const
{
    Json::FastWriter writer;
    return writer.write(serializeToJson(key));
}

template<class Cipher>
ScryptParams PrivateKeySerializer<Cipher>::unserializeKDF(const Json::Value &params) const
{
    KdfSerializer<typename Cipher::KdfParams> kdfSerializer;
    return kdfSerializer.unserialize(params);
}


template<class Cipher>
Json::Value PrivateKeySerializer<Cipher>::serializeKDF(const ScryptParams &params) const
{
    KdfSerializer<typename Cipher::KdfParams> kdfSerializer;
    return kdfSerializer.serializeToJson(params);
}







}
