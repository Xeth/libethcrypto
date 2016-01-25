namespace Ethereum{

template<class Data>
Data Literal(const std::string &serialized)
{
    Base16HashSerializer serializer;
    return serializer.unserialize(serialized);
}


template<class Cipher>
SecuredPrivateKey<Cipher> Literal(const std::string &serialized, const Cipher &cipher)
{
    Base16PrivateKeySerializer serializer;
    return serializer.unserialize(serialized, cipher);
}


template<class Cipher>
std::string Literal(const SecuredPrivateKey<Cipher> &key)
{
    Base16PrivateKeySerializer serializer;
    return serializer.serialize(key);
}

}
