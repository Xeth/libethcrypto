#pragma once 

#include "Base16Encoder.hpp"

namespace Ethereum{


typedef Base16Encoder HexEncoder;


inline std::string EncodeHex(const Data &data)
{
    HexEncoder encoder;
    return encoder.encode(data);
}

template<class Iterator>
std::string EncodeHex(Iterator begin, Iterator end)
{
    HexEncoder encoder;
    return encoder.encode(begin, end);
}


inline Data DecodeHex(const std::string &hex)
{
    HexEncoder encoder;
    return encoder.decode(hex);
}




}
