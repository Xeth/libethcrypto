#pragma once 

#include "cipher/EncryptedData.hpp"
#include "PrivateKey.hpp"


namespace Ethereum{


template<class Cipher>
class SecuredPrivateKey
{
    public:
        SecuredPrivateKey();

        template<class CipherKey>
        SecuredPrivateKey(const PrivateKey &, const Cipher &, const CipherKey &);

        SecuredPrivateKey(const EncryptedData &, const Cipher &);

        template<class CipherKey>
        PrivateKey unlock(const CipherKey &) const;

        const EncryptedData & getData() const;
        EncryptedData & getData();

        const Cipher & getCipher() const;

        SecuredPrivateKey & operator = (const SecuredPrivateKey &);

    private:
        Cipher _cipher;
        EncryptedData  _privateKey;
};


}

#include "SecuredPrivateKey.ipp"
