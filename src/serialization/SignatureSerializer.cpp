#include "SignatureSerializer.hpp"


namespace Ethereum{


SignatureSerializer::SignatureSerializer() : 
    _hexSerializer(_binSerializer)
{}


SignatureSerializer::SignatureSerializer(const Secp256k1ContextPtr &context) :
    _binSerializer(context),
    _hexSerializer(_binSerializer)
{}


std::string SignatureSerializer::serialize(const Signature &signature, bool compact) const
{
    return _hexSerializer.serialize(signature, compact);
}


Signature SignatureSerializer::unserialize(const std::string &hex) const
{
    return _hexSerializer.unserialize(hex);
}


Signature SignatureSerializer::unserialize(const Data &data) const
{
    return fromBytes(data);
}



Data SignatureSerializer::toBytes(const Signature &signature, bool compact) const
{
    return _binSerializer.serialize(signature, compact);
}


Signature SignatureSerializer::fromBytes(const Data &data) const
{
    return _binSerializer.unserialize(data);
}


}
