#pragma once 

#include "Base16Encoder.hpp"

namespace Ethereum{


typedef Base16Encoder HexEncoder;


template<class Data>
std::string EncodeHex(const Data &data)
{
    HexEncoder encoder;
    return encoder.encode(data.begin(), data.end());
}


template<class Iterator>
std::string EncodeHex(Iterator begin, Iterator end)
{
    HexEncoder encoder;
    return encoder.encode(begin, end);
}

template<class Data>
Data DecodeHex(const std::string &hex)
{
    HexEncoder encoder;
    return encoder.decode<Data>(hex.begin(), hex.end());
}

inline Data DecodeHex(const std::string &hex)
{
    HexEncoder encoder;
    return encoder.decode(hex);
}




}
