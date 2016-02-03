#pragma once 

#include "PrivateKey.hpp"


namespace Ethereum{


template<class Cipher>
class SecuredPrivateKey
{
    public:
        template<class CipherKey>
        SecuredPrivateKey(const PrivateKey &, const Cipher &, const CipherKey &);

        SecuredPrivateKey(const Data &, const Cipher &);

        template<class CipherKey>
        PrivateKey unlock(const CipherKey &) const;

        const Data & getData() const;
        Data & getData();

    private:
        Cipher _cipher;
        Data   _privateKey;
};


}

#include "SecuredPrivateKey.ipp"
