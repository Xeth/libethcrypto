#include "Signer.hpp"


namespace BitCrypto{


Signer::Signer()
{}


Signer::Signer(const Secp256k1ContextPtr &context) :
    Secp256k1Handler(context)
{}


bool Signer::sign(const PrivateKey &key, const unsigned char *hash, Signature &result)
{
    if(!secp256k1_ecdsa_sign(getContext().get(), &result, hash, &key, NULL, NULL))
    {
        return false;
    }
    return true;
}


bool Signer::sign(const PrivateKey &key, const Data &data, Signature &result)
{
    if(data.size()!=32)
    {
        return false;
    }
    return sign(key, &*data.begin(), result);
}


Signature Signer::sign(const PrivateKey &key, const unsigned char *hash)
{
    Signature result;
    if(!sign(key, hash, result))
    {
        throw std::runtime_error("signature failed");
    }
    return result;
}


Signature Signer::sign(const PrivateKey &key, const Data &hash)
{
    Signature result;
    if(!sign(key, hash, result))
    {
        throw std::runtime_error("signature failed");
    }
    return result;
}


}
