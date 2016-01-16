#include "bitcrypto/Secret.hpp"

namespace BitCrypto{

Secret::Secret()
{}

Secret::Secret(const Secp256k1ContextPtr &context ) : 
    LazySecp256k1Handler(context)
{}


Secret::Secret(const Data &data)
{
    if(data.size() != 32)
    {
        throw std::runtime_error("invalid secret data");
    }
    std::copy(data.begin(), data.end(), begin());
}


unsigned char * Secret::operator & ()
{
    return data();
}

const unsigned char * Secret::operator & () const
{
    return data();
}


Secret Secret::operator + (const Secret &secret) const
{
    Secret result(*this);
    if(!secp256k1_ec_privkey_tweak_add(getContext().get(), result.data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}

Secret Secret::operator * (const Secret &secret) const
{
    Secret result(*this);
    if(!secp256k1_ec_privkey_tweak_mul(getContext().get(), result.data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}

Secret & Secret::operator += (const Secret &secret)
{
    if(!secp256k1_ec_privkey_tweak_add(getContext().get(), data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return *this;
}

Secret & Secret::operator *= (const Secret &secret)
{
    if(!secp256k1_ec_privkey_tweak_mul(getContext().get(), data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return *this;
}


}
