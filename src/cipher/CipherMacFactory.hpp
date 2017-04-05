#pragma once 

#include "../detail/Data.hpp"
#include "../hash/Keccak256.hpp"

namespace Ethereum{


class CipherMacFactory
{
    public:
        Data createMac(const Data &encrypted, const Data &key) const;
        void createMac(const Data &encrypted, const Data &key, Data &mac) const;

};


}
