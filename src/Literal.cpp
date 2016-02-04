#include "Literal.hpp"


namespace Ethereum{


std::string Literal(const Data &hash)
{
    return EncodeHex(hash.begin(), hash.end());
}


std::string Literal(const PrivateKey &key)
{
    return EncodeHex(key.begin(), key.end());
}


template<>
PrivateKey Literal<PrivateKey>(const std::string &serialized)
{
    PrivateKey key = DecodeHex(serialized);
    return key;
}


std::string Literal(const PublicKey &key)
{
    PublicKeySerializer serializer;
    return serializer.serialize(key);
}

std::string Literal(const UncompressedPoint &point)
{
    PublicKeySerializer serializer;
    return serializer.serialize(point);
}

std::string Literal(const CompressedPoint &point)
{
    PublicKeySerializer serializer;
    return serializer.serialize(point);
}


template<>
PublicKey Literal<PublicKey>(const std::string &serialized)
{
    PublicKeySerializer serializer;
    return serializer.unserialize(serialized);
}


template<>
UncompressedPoint Literal<UncompressedPoint>(const std::string &serialized)
{
    PublicKeySerializer serializer;
    return serializer.toUncompressedPoint(serialized);
}


template<>
CompressedPoint Literal<CompressedPoint>(const std::string &serialized)
{
    PublicKeySerializer serializer;
    return serializer.toCompressedPoint(serialized);
}


std::string Literal(const Signature &signature)
{
    SignatureSerializer serializer;
    return serializer.serialize(signature);
}


template<>
Signature Literal<Signature>(const std::string &serialized)
{
    SignatureSerializer serializer;
    return serializer.unserialize(serialized);
}

}
