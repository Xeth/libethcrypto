#pragma once 

#include "bitcrypto/Secret.hpp"
#include "bitcrypto/CipherAdapter.hpp"


namespace BitCrypto{

template<class Cipher>
class SecuredSecret
{
    public:
        template<class CipherKey>
        SecuredSecret(const Secret &, const Cipher &, const CipherKey &);

        SecuredSecret(const Data &secret, const Cipher &);

        template<class CipherKey>
        Secret unlock(const CipherKey &);

        const Data & getData() const;
        Data & getData();

    private:
        Cipher _cipher;
        Data  _secret;
};


}

#include "bitcrypto/SecuredSecret.ipp"
