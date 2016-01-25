#pragma once 

#include "PublicKey.hpp"
#include "PrivateKey.hpp"

#include "detail/Secp256k1ContextPtr.hpp"


namespace Ethereum{


class KeyPair
{
    public:
        KeyPair();
        KeyPair(const Secp256k1ContextPtr &);
        KeyPair(const PrivateKey &, const PublicKey &);

        PublicKey & getPublicKey();
        PrivateKey & getPrivateKey();

        const PublicKey & getPublicKey() const;
        const PrivateKey & getPrivateKey() const;

    private:
        PrivateKey _privateKey;
        PublicKey _publicKey;
};



}
