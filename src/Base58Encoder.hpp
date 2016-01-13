#pragma once

#include "Data.hpp"
#include "GenericDataEncoder.hpp"


namespace BitCrypto{


struct Base58Alphabet
{
    static const size_t base;
    static const char *map;
    static const bool strip; //dirty hack, needed to be changed with a more generic approach
};



typedef GenericDataEncoder<Base58Alphabet> Base58Encoder;





}

