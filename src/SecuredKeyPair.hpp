#pragma once 

#include "bitcrypto/PubKey.hpp"
#include "bitcrypto/SecuredSecret.hpp"
#include "bitcrypto/SecretGenerator.hpp"
#include "bitcrypto/PubKeyFactory.hpp"
#include "bitcrypto/detail/Secp256k1ContextPtr.hpp"


namespace BitCrypto{


template<class Cipher>
class SecuredKeyPair
{
    public:
        typedef BitCrypto::SecuredSecret<Cipher> Secret;

    public:

        template<class CipherKey>
        SecuredKeyPair(const Secret &, const PubKey &, const Cipher &, const CipherKey &);

        SecuredKeyPair(const Data &, const PubKey &, const Cipher &);

        Secret & getSecret();
        const Secret & getSecret() const;
        PubKey & getPubKey();
        const PubKey & getPubKey() const;

    private:
        Secret _secret;
        PubKey _pubKey;
};


}
