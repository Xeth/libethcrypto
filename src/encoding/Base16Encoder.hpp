#pragma once

#include "ethkey/Data.hpp"
#include "detail/GenericDataEncoder.hpp"


namespace Ethereum{


struct Base16Alphabet
{
    static const size_t base;
    static const char *map;
    static const bool strip; //dirty hack
};



typedef GenericDataEncoder<Base16Alphabet> Base16Encoder;





}

