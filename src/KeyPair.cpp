#include "KeyPair.hpp"


namespace BitCrypto{


KeyPair::KeyPair()
{}


KeyPair::KeyPair(const Secp256k1ContextPtr &context) : 
    _pubKey(context)
{}


KeyPair::KeyPair(const Secret &secret, const PubKey &pubKey) :
    _secret(secret),
    _pubKey(pubKey)
{}


Secret & KeyPair::getSecret()
{
    return _secret;
}

const Secret & KeyPair::getSecret() const
{
    return _secret;
}


PubKey & KeyPair::getPubKey()
{
    return _pubKey;
}


const PubKey & KeyPair::getPubKey() const
{
    return _pubKey;
}


}
