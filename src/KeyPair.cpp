#include "bitcrypto/KeyPair.hpp"


namespace BitCrypto{


KeyPair::KeyPair()
{}


KeyPair::KeyPair(const Secp256k1ContextPtr &context) : 
    _publicKey(context)
{}


KeyPair::KeyPair(const PrivateKey &privateKey, const PublicKey &PublicKey) :
    _privateKey(privateKey),
    _publicKey(PublicKey)
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
