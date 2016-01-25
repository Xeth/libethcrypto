#include "KeyPair.hpp"

#include <iostream>

namespace Ethereum{


KeyPair::KeyPair()
{}


KeyPair::KeyPair(const Secp256k1ContextPtr &context) : 
    _privateKey(context),
    _publicKey(context)
{}


KeyPair::KeyPair(const PrivateKey &privateKey, const PublicKey &publicKey) :
    _privateKey(privateKey),
    _publicKey(publicKey)
{}


PrivateKey & KeyPair::getPrivateKey()
{
    return _privateKey;
}

const PrivateKey & KeyPair::getPrivateKey() const
{
    return _privateKey;
}


PublicKey & KeyPair::getPublicKey()
{
    return _publicKey;
}


const PublicKey & KeyPair::getPublicKey() const
{
    return _publicKey;
}


}
