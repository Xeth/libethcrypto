#pragma once 

#include "KeyPair.hpp"
#include "SecuredKeyPair.hpp"
#include "detail/Secp256k1Handler.hpp"


namespace BitCrypto{


class KeyGenerator : public Secp256k1Handler
{
    public:
        KeyGenerator();
        KeyGenerator(const Secp256k1ContextPtr &);

        KeyPair generate();
        KeyPair generate(const Data &);
        KeyPair generate(const char *);

        template<class Cipher, class CipherKey>
        SecuredKeyPair<Cipher> generate(const Cipher &, const CipherKey &);

        template<class Cipher, class CipherKey>
        SecuredKeyPair<Cipher> generate(const Data &, const Cipher &, const CipherKey &);

        template<class Cipher, class CipherKey>
        SecuredKeyPair<Cipher> generate(const char *, const Cipher &, const CipherKey &);


    private:
        SecretGenerator _secretGenerator;
        PubKeyFactory _pubKeyGenerator;
};


}

#include "KeyGenerator.ipp"
