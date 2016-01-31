namespace Ethereum{

template<class Data>
Data Literal(const std::string &serialized)
{
    Base16Encoder encoder;
    Data result;
    encoder.decode(serialized.begin(), serialized.end(), result);
    return result;
}


template<class Cipher>
SecuredPrivateKey<Cipher> Literal(const std::string &serialized, const Cipher &cipher)
{
    PrivateKeySerializer serializer;
    return serializer.unserialize(serialized, cipher);
}


template<class Cipher>
std::string Literal(const SecuredPrivateKey<Cipher> &key)
{
    PrivateKeySerializer serializer;
    return serializer.serialize(key);
}

}
