#pragma once 

#include "PublicKey.hpp"
#include "Address.hpp"

#include "encoding/Base16Encoder.hpp"
#include "Sha256.hpp"


namespace Ethereum{



class AddressFactory 
{
    public:

        bool createFromPublicKey(const PublicKey &, Address &) const;
        Address createFromPublicKey(const PublicKey &) const;

        bool createFromString(const std::string &, Address &) const;
        Address createFromString(const std::string &) const;

        bool createFromString(const char *, size_t, Address &) const;
        Address createFromString(const char *, size_t ) const;
};



}