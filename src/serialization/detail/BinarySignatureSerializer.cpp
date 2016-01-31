#include "BinarySignatureSerializer.hpp"

namespace Ethereum{


BinarySignatureSerializer::BinarySignatureSerializer()
{}


BinarySignatureSerializer::BinarySignatureSerializer(const Secp256k1ContextPtr &context) : 
    Secp256k1Handler(context)
{}


bool BinarySignatureSerializer::serialize(const Signature &signature, Data &result, bool compact) const
{
    if(compact)
    {
        result.resize(64);
        if(!secp256k1_ecdsa_signature_serialize_compact(getContext().get(), &*result.begin(), &signature))
        {
            return false;
        }
    }
    else
    {
        result.resize(72);
        size_t size = 72;
        if(!secp256k1_ecdsa_signature_serialize_der(getContext().get(), &*result.begin(), &size, &signature))
        {
            return false;
        }
        if(size!=72)
        {
            result.resize(size);
        }
    }
    return true;
}


bool BinarySignatureSerializer::unserialize(const Data &serialized, Signature &result) const
{
    Signature decoded;
    if(serialized.size()==64)
    {
        if(!secp256k1_ecdsa_signature_parse_compact(getContext().get(), &decoded, &*serialized.begin()))
        {
            return false;
        }
    }
    else
    {
        if(!secp256k1_ecdsa_signature_parse_der(getContext().get(), &decoded, &*serialized.begin(), serialized.size()))
        {
            return false;
        }
    }
    secp256k1_ecdsa_signature_normalize(getContext().get(), &result, &decoded);
    return true;
}


Signature BinarySignatureSerializer::unserialize(const Data &serialized) const
{
    Signature signature;
    if(!unserialize(serialized, signature))
    {
        throw std::runtime_error("invalid serialized signature");
    }
    return signature;
}


Data BinarySignatureSerializer::serialize(const Signature &signature, bool compact) const
{
    Data result;
    if(!serialize(signature, result, compact))
    {
        throw std::runtime_error("invalid signature");
    }
    return result;
}

}
