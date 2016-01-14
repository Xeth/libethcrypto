#pragma once 

#include "KeyPair.hpp"
#include "SecuredKeyPair.hpp"
#include "Secp256k1ContextPtr.hpp"
#include "Secp256k1ContextFactory.hpp"


namespace BitCrypto{


class KeyGenerator
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
        Secp256k1ContextPtr createContext();

    private:
        Secp256k1ContextPtr _context;
        SecretGenerator _secretGenerator;
        PubKeyFactory _pubKeyGenerator;
};


}

#include "KeyGenerator.ipp"
