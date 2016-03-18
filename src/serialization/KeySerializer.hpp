#pragma once 

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

#include "../key/SecuredKey.hpp"
#include "../key/Address.hpp"
#include "../key/PublicKeyFactory.hpp"


#include "PrivateKeySerializer.hpp"


namespace Ethereum{


template<class Cipher>
class KeySerializer
{
    public:

        Json::Value serializeToJson(const SecuredKey<Cipher> &) const;
        std::string serialize(const SecuredKey<Cipher> &) const;

        SecuredKey<Cipher> unserialize(const std::string &) const;
        SecuredKey<Cipher> unserialize(const Json::Value &) const;

    private:
        PrivateKeySerializer<Cipher> _secretSerializer;
};


}

#include "KeySerializer.ipp"
