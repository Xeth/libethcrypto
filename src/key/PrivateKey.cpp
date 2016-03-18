#include "PrivateKey.hpp"

namespace Ethereum{

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
    return sum(privateKey);
}


PrivateKey PrivateKey::operator * (const PrivateKey &privateKey) const
{
    return multiply(privateKey);
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




}
