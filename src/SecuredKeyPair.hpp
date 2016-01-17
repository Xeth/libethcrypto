#pragma once 

#include "bitcrypto/PublicKey.hpp"
#include "bitcrypto/SecuredPrivateKey.hpp"
#include "bitcrypto/PrivateKeyGenerator.hpp"
#include "bitcrypto/PublicKeyFactory.hpp"
#include "bitcrypto/detail/Secp256k1ContextPtr.hpp"


namespace BitCrypto{


template<class Cipher>
class SecuredKeyPair
{
    public:
        typedef BitCrypto::SecuredPrivateKey<Cipher> PrivateKey;

    public:

        template<class CipherKey>
        SecuredKeyPair(const PrivateKey &, const PublicKey &, const Cipher &, const CipherKey &);

        SecuredKeyPair(const Data &, const PublicKey &, const Cipher &);

        PrivateKey & getPrivateKey();
        const PrivateKey & getPrivateKey() const;
        PublicKey & getPublicKey();
        const PublicKey & getPublicKey() const;

    private:
        SecuredPrivateKey<Cipher>  _privateKey;
        PublicKey _publicKey;
};


}
