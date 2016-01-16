#pragma once

#include "bitcrypto/Secret.hpp"
#include "bitcrypto/SecuredSecret.hpp"

#include "Secp256k1ContextPtr.hpp"

namespace BitCrypto{


template<class Encoder>
class GenericSecretSerializer
{
    public:
    
        GenericSecretSerializer();
        GenericSecretSerializer(const Secp256k1ContextPtr &);
    
        std::string serialize(const Secret &) const;
        Secret unserialize(const std::string &) const;

        template<class Cipher>
        std::string serialize(const SecuredSecret<Cipher> &) const;

        template<class Cipher>
        SecuredSecret<Cipher> unserialize(const std::string &, const Cipher &) const;


    private:
       Secp256k1ContextPtr _context;

};





}

#include "GenericSecretSerializer.ipp"
