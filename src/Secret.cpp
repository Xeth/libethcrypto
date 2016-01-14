#include "Secret.hpp"

namespace BitCrypto{

Secret::Secret()
{}

Secret::Secret(const Secp256k1ContextPtr &context ) : 
    _context(context)
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
    createContextIfNeeded();

    Secret result(*this);
    if(!secp256k1_ec_privkey_tweak_add(_context.get(), result.data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}

Secret Secret::operator * (const Secret &secret) const
{
    createContextIfNeeded();

    Secret result(*this);
    if(!secp256k1_ec_privkey_tweak_mul(_context.get(), result.data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}

Secret & Secret::operator += (const Secret &secret)
{
    createContextIfNeeded();

    if(!secp256k1_ec_privkey_tweak_add(_context.get(), data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return *this;
}

Secret & Secret::operator *= (const Secret &secret)
{
    createContextIfNeeded();

    if(!secp256k1_ec_privkey_tweak_mul(_context.get(), data(), secret.data()))
    {
        throw std::runtime_error("private key operation failed");
    }
    return *this;
}

void Secret::createContextIfNeeded() const
{
    if(!_context)
    {
        Secp256k1ContextFactory factory;
        _context = factory.create();
    }
}

}
