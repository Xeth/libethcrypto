#pragma once 

#include <algorithm>

#include "bitcrypto/Data.hpp"


namespace BitCrypto{


template<class Encoder>
class GenericHashSerializer
{
    public:

        std::string serialize(const Data &) const;
        Data unserialize(const std::string &) const;

    private:
        Encoder _encoder;
};


}

#include "GenericHashSerializer.ipp"
