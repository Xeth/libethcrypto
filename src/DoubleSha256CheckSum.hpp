#pragma once

#include <stdint.h>

#include "hash/Sha256.hpp"
#include "DoubleHash.hpp"


namespace Ethereum{


class DoubleSha256CheckSum
{
    public:

        template<class Iterator>
        uint32_t operator()(Iterator begin, Iterator end) const;

        template<class Data>
        uint32_t operator()(const Data &) const;

        template<class Iterator>
        uint32_t checksum(Iterator begin, Iterator end) const;

        template<class Data>
        uint32_t checksum(const Data &) const;

};



}

#include "DoubleSha256CheckSum.ipp"
