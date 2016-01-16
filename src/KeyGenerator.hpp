#pragma once 

#include "bitcrypto/KeyPair.hpp"
#include "bitcrypto/SecuredKeyPair.hpp"
#include "bitcrypto/detail/Secp256k1Handler.hpp"


namespace BitCrypto{


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


    private:
        SecretGenerator _secretGenerator;
        PubKeyFactory _pubKeyGenerator;
};


}

#include "KeyGenerator.ipp"
