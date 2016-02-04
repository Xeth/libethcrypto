#pragma once

#include "../../PrivateKey.hpp"
#include "../../SecuredPrivateKey.hpp"

#include "../../detail/Secp256k1ContextPtr.hpp"

namespace Ethereum{


template<class Encoder>
class GenericPrivateKeySerializer
{
    public:
    
        GenericPrivateKeySerializer();
        GenericPrivateKeySerializer(const Secp256k1ContextPtr &);


        Json::Value serializeToJson(const PrivateKey &);

        std::string serialize(const PrivateKey &) const;
        PrivateKey unserialize(const std::string &) const;

        template<class Cipher>
        std::string serialize(const SecuredPrivateKey<Cipher> &) const;

        template<class Cipher>
        SecuredPrivateKey<Cipher> unserialize(const std::string &, const Cipher &) const;


    private:
       Secp256k1ContextPtr _context;

};





}

#include "GenericPrivateKeySerializer.ipp"
