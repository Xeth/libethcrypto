#include "Literal.hpp"


namespace Ethereum{


std::string Literal(const Data &hash)
{
    Base16HashSerializer serializer;
    return serializer.serialize(hash);
}


std::string Literal(const PrivateKey &key)
{
    Base16PrivateKeySerializer serializer;
    return serializer.serialize(key);
}


template<>
PrivateKey Literal<PrivateKey>(const std::string &serialized)
{
    Base16PrivateKeySerializer serializer;
    return serializer.unserialize(serialized);
}


std::string Literal(const PublicKey &key)
{
    Base16PublicKeySerializer serializer;
    return serializer.serialize(key);
}

std::string Literal(const UncompressedPoint &point)
{
    Base16PublicKeySerializer serializer;
    return serializer.serialize(point);
}

std::string Literal(const CompressedPoint &point)
{
    Base16PublicKeySerializer serializer;
    return serializer.serialize(point);
}


template<>
PublicKey Literal<PublicKey>(const std::string &serialized)
{
    Base16PublicKeySerializer serializer;
    return serializer.unserialize(serialized);
}


template<>
UncompressedPoint Literal<UncompressedPoint>(const std::string &serialized)
{
    Base16PublicKeySerializer serializer;
    UncompressedPoint point;
    serializer.unserialize(serialized, point);
    return point;
}


template<>
CompressedPoint Literal<CompressedPoint>(const std::string &serialized)
{
    Base16PublicKeySerializer serializer;
    CompressedPoint point;
    serializer.unserialize(serialized, point);
    return point;
}


std::string Literal(const Signature &signature)
{
    Base16SignatureSerializer serializer;
    return serializer.serialize(signature);
}


template<>
Signature Literal<Signature>(const std::string &serialized)
{
    Base16SignatureSerializer serializer;
    return serializer.unserialize(serialized);
}

}
