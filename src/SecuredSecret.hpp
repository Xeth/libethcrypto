#pragma once 

#include "Secret.hpp"


namespace BitCrypto{


template<class Cipher>
class SecuredSecret
{
    public:
        template<class CipherKey>
        SecuredSecret(const Secret &, const CipherKey &);

        SecuredSecret(const Data &secret);

        template<class CipherKey>
        Secret unlock(const CipherKey &);

    private:
        Cipher _cipher;
        Data  _secret;
};


}

#include "SecuredSecret.ipp"
