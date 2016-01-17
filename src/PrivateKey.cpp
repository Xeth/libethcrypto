#include "bitcrypto/PrivateKey.hpp"

namespace BitCrypto{

PrivateKey::PrivateKey()
{}

PrivateKey::PrivateKey(const Secp256k1ContextPtr &context ) : 
    LazySecp256k1Handler(context)
{}


PrivateKey::PrivateKey(const Data &data)
{
    if(data.size() != 32)
    {
        throw std::runtime_error("invalid PrivateKey data");
    }
    std::copy(data.begin(), data.end(), begin());
}


unsigned char * PrivateKey::operator & ()
{
    return data();
}

const unsigned char * PrivateKey::operator & () const
{
    return data();
}


PrivateKey PrivateKey::operator + (const PrivateKey &privateKey) const
{
    PrivateKey result(*this);
    if(!secp256k1_ec_privkey_tweak_add(getContext().get(), result.data(), privateKey.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}

PrivateKey PrivateKey::operator * (const PrivateKey &privateKey) const
{
    PrivateKey result(*this);
    if(!secp256k1_ec_privkey_tweak_mul(getContext().get(), result.data(), privateKey.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}

PrivateKey & PrivateKey::operator += (const PrivateKey &privateKey)
{
    if(!secp256k1_ec_privkey_tweak_add(getContext().get(), data(), privateKey.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return *this;
}

PrivateKey & PrivateKey::operator *= (const PrivateKey &privateKey)
{
    if(!secp256k1_ec_privkey_tweak_mul(getContext().get(), data(), privateKey.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return *this;
}


bool PrivateKey::sign(const unsigned char *hash, Signature &result)
{
    if(!secp256k1_ecdsa_sign(getContext().get(), &result, hash, data(), NULL, NULL))
    {
        return false;
    }
    return true;
}


bool PrivateKey::sign(const Data &data, Signature &result)
{
    if(data.size()!=32)
    {
        return false;
    }
    return sign(&*data.begin(), result);
}


Signature PrivateKey::sign(const unsigned char *hash)
{
    Signature result;
    if(!sign(hash, result))
    {
        throw std::runtime_error("signature failed");
    }
    return result;
}


Signature PrivateKey::sign(const Data &hash)
{
    Signature result;
    if(!sign(hash, result))
    {
        throw std::runtime_error("signature failed");
    }
    return result;
}

}
