#pragma once 

#include "PublicKey.hpp"
#include "SecuredPrivateKey.hpp"
#include "PrivateKeyGenerator.hpp"
#include "PublicKeyFactory.hpp"
#include "detail/Secp256k1ContextPtr.hpp"


namespace Ethereum{


template<class Cipher>
class SecuredKeyPair
{

    public:

        template<class CipherKey>
        SecuredKeyPair(const PrivateKey &, const PublicKey &, const Cipher &, const CipherKey &);

        SecuredKeyPair(const EncryptedData &, const PublicKey &, const Cipher &);

        SecuredPrivateKey<Cipher> & getPrivateKey();
        const SecuredPrivateKey<Cipher> & getPrivateKey() const;
        PublicKey & getPublicKey();
        const PublicKey & getPublicKey() const;

    private:
        SecuredPrivateKey<Cipher>  _privateKey;
        PublicKey _publicKey;
};


}

#include "SecuredKeyPair.ipp"
