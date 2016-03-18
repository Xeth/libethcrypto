#pragma once

#include "../hash/Sha256.hpp"
#include "../hash/DoubleHash.hpp"


namespace Ethereum{


class DoubleSha256CheckSum
{
    public:

        template<class Iterator>
        unsigned operator()(Iterator begin, Iterator end) const;

        template<class Data>
        unsigned operator()(const Data &) const;

        template<class Iterator>
        unsigned checksum(Iterator begin, Iterator end) const;

        template<class Data>
        unsigned checksum(const Data &) const;

};



}

#include "DoubleSha256CheckSum.ipp"
