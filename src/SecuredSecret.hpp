#pragma once 

#include "Secret.hpp"
#include "CipherAdapter.hpp"


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

    private:
        CipherAdapter _cipher;
        Data  _secret;
};


}

#include "SecuredSecret.ipp"
