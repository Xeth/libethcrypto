#pragma once 

#include "PubKey.hpp"
#include "Secret.hpp"

#include "detail/Secp256k1ContextPtr.hpp"


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
