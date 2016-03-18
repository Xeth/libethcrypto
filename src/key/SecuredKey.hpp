#pragma once 

#include "SecuredKeyPair.hpp"
#include "SecuredPrivateKey.hpp"
#include "Address.hpp"
#include "PublicKeyFactory.hpp"

namespace Ethereum{


template<class Cipher>
class SecuredKey
{
    public:

        SecuredKey();
        SecuredKey(const SecuredPrivateKey<Cipher> &, const Address &);
        SecuredKey(const SecuredKeyPair<Cipher> &);

        template<class CipherParams>
        SecuredKey(const PrivateKey &, const Cipher &, const CipherParams &);

        SecuredKey & operator = (const SecuredKey &);
        SecuredKey & operator = (const SecuredKeyPair<Cipher> &);
        bool operator == (const SecuredKey &) const;

        const SecuredPrivateKey<Cipher> & getPrivateKey() const;
        const Address & getAddress() const;

    private:
        SecuredPrivateKey<Cipher> _secret;
        Address _address;

};


}

#include "SecuredKey.ipp"
