

namespace BitCrypto{


template<class Encoder>
GenericPrivateKeySerializer<Encoder>::GenericPrivateKeySerializer()
{}


template<class Encoder>
GenericPrivateKeySerializer<Encoder>::GenericPrivateKeySerializer(const Secp256k1ContextPtr &context) : 
    _context(context)
{}


template<class Encoder>
std::string GenericPrivateKeySerializer<Encoder>::serialize(const PrivateKey &secret) const 
{
    Encoder encoder;
    return encoder.encode(secret.begin(), secret.end());
}


template<class Encoder>
template<class Cipher>
std::string GenericPrivateKeySerializer<Encoder>::serialize(const SecuredPrivateKey<Cipher> &secret) const
{
    Encoder encoder;
    const Data & secretData = secret.getData();
    return encoder.encode(secretData.begin(), secretData.end());
}


template<class Encoder>
template<class Cipher>
SecuredPrivateKey<Cipher> GenericPrivateKeySerializer<Encoder>::unserialize(const std::string &serialized, const Cipher &cipher) const
{
    SecuredPrivateKey<Cipher> secret(_context, cipher);
    Encoder encoder;
    encoder.decode(serialized.begin(), serialized.end(), secret.getData());
    return secret;
}


template<class Encoder>
PrivateKey GenericPrivateKeySerializer<Encoder>::unserialize(const std::string &serialized) const
{
    Encoder encoder;
    Data data = encoder.decode(serialized.begin(), serialized.end());
    if(data.size() != 32)
    {
        throw std::runtime_error("Invalid serialized secret");
    }
    PrivateKey secret(_context);
    std::copy(data.begin(), data.end(), secret.begin());
    return secret;
}

}
