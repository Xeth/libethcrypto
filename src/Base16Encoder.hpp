#pragma once

#include "bitcrypto/Data.hpp"
#include "bitcrypto/detail/GenericDataEncoder.hpp"


namespace BitCrypto{


struct Base16Alphabet
{
    static const size_t base;
    static const char *map;
    static const bool strip; //dirty hack
};



typedef GenericDataEncoder<Base16Alphabet> Base16Encoder;





}

