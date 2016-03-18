#pragma once 

#include "KeyPair.hpp"
#include "SecuredKeyPair.hpp"
#include "../detail/Secp256k1Handler.hpp"


namespace Ethereum{


class KeyGenerator : public Secp256k1Handler
{
    public:
        KeyGenerator();
        KeyGenerator(const Secp256k1ContextPtr &);

        KeyPair generate();
        KeyPair generate(const Data &entropy);
        KeyPair generate(const unsigned char *entropy, size_t entropySize);

        template<class Cipher, class CipherKey>
        SecuredKeyPair<Cipher> generate(const Cipher &, const CipherKey &);

        template<class Cipher, class CipherKey>
        SecuredKeyPair<Cipher> generate(const Data &, const Cipher &, const CipherKey &);

        template<class Cipher, class CipherKey>
        SecuredKeyPair<Cipher> generate(const unsigned char *entropy, size_t entropySize, const Cipher &, const CipherKey &);

        PublicKeyFactory & getPublicKeyFactory();
        PrivateKeyGenerator &getPrivateKeyGenerator();

    private:
        PrivateKeyGenerator _privateKeyGenerator;
        PublicKeyFactory _publicKeyGenerator;
};


}

#include "KeyGenerator.ipp"
