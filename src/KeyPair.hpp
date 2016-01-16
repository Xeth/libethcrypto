#pragma once 

#include "bitcrypto/PubKey.hpp"
#include "bitcrypto/Secret.hpp"

#include "bitcrypto/detail/Secp256k1ContextPtr.hpp"


namespace BitCrypto{


class KeyPair
{
    public:
        KeyPair();
        KeyPair(const Secp256k1ContextPtr &);
        KeyPair(const Secret &, const PubKey &);

        PubKey & getPubKey();
        Secret & getSecret();

        const PubKey & getPubKey() const;
        const Secret & getSecret() const;

    private:
        Secret _secret;
        PubKey _pubKey;
};



}
