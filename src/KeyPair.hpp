#pragma once 

#include "bitcrypto/PublicKey.hpp"
#include "bitcrypto/PrivateKey.hpp"

#include "bitcrypto/detail/Secp256k1ContextPtr.hpp"


namespace BitCrypto{


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
