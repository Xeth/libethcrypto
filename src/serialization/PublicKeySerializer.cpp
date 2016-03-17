#include "PublicKeySerializer.hpp"

namespace Ethereum{


PublicKeySerializer::PublicKeySerializer() : 
    _hexSerializer(_binarySerializer)
{}


PublicKeySerializer::PublicKeySerializer(const Secp256k1ContextPtr &context) : 
    _binarySerializer(context),
    _hexSerializer(_binarySerializer)
{}


std::string PublicKeySerializer::serialize(const PublicKey &key, bool compress) const
{
    return toHex(key, compress);
}


std::string PublicKeySerializer::serialize(const CompressedPoint &point) const
{
    return toHex(point);
}


std::string PublicKeySerializer::serialize(const UncompressedPoint &point) const
{
    return toHex(point);
}


PublicKey PublicKeySerializer::unserialize(const std::string &serialized) const
{
    return fromHex(serialized);
}

PublicKey PublicKeySerializer::unserialize(const char *buffer, size_t size) const
{
    return fromHex(buffer, size);
}


PublicKey PublicKeySerializer::unserialize(const CompressedPoint &point) const
{
    return fromPoint(point);
}


PublicKey PublicKeySerializer::unserialize(const UncompressedPoint &point) const
{
    return fromPoint(point);
}


std::string PublicKeySerializer::toHex(const PublicKey &key, bool compress) const
{
    return _hexSerializer.serialize(key, compress);
}


std::string PublicKeySerializer::toHex(const CompressedPoint &point) const
{
    return _hexPointSerializer.serialize(point);
}

std::string PublicKeySerializer::toHex(const UncompressedPoint &point) const
{
    return _hexPointSerializer.serialize(point);
}


CompressedPoint PublicKeySerializer::toCompressedPoint(const PublicKey &key) const
{
    return _binarySerializer.serialize<CompressedPoint>(key);
}


UncompressedPoint PublicKeySerializer::toUncompressedPoint(const PublicKey &key) const
{
    return _binarySerializer.serialize<UncompressedPoint>(key);
}


CompressedPoint PublicKeySerializer::toCompressedPoint(const std::string &hex) const
{
    CompressedPoint point;
    _hexPointSerializer.unserialize(hex, point);
    return point;
}


UncompressedPoint PublicKeySerializer::toUncompressedPoint(const std::string &hex) const
{
    UncompressedPoint point;
    _hexPointSerializer.unserialize(hex, point);
    return point;
}


PublicKey PublicKeySerializer::fromHex(const std::string &hex) const
{
    return _hexSerializer.unserialize(hex);
}

PublicKey PublicKeySerializer::fromHex(const char *buffer, size_t size) const
{
    return _hexSerializer.unserialize(buffer, size);
}

PublicKey PublicKeySerializer::fromPoint(const CompressedPoint &point) const
{
    return _binarySerializer.unserialize(point);
}


PublicKey PublicKeySerializer::fromPoint(const UncompressedPoint &point) const
{
    return _binarySerializer.unserialize(point);
}

}
