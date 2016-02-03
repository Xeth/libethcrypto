#pragma once 

#include "../Data.hpp"
#include "../hash/Sha3.hpp"

namespace Ethereum{


class CipherMacFactory
{
    public:
        Data createMac(const Data &encrypted, const Data &key) const;
        void createMac(const Data &encrypted, const Data &key, Data &mac) const;

};


}
