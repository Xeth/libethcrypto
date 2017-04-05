#include "HexCaseCheckSum.hpp"
#include "../encoding/HexEncoder.hpp"

#include <iostream>

namespace Ethereum{


std::string HexCaseCheckSum::compute(const std::string &hex) const
{
    if(!checkAddressLen(hex))
    {
        throw std::runtime_error("invalid address");
    }

    std::string result = toLowerCase(hex);
    Data data = hash(result);


    for(size_t i=0, j=0; i<20; ++i, j+=2)
    {
        unsigned char value = data[i];
        if((value>>4) > 7)
        {
            result[j] = ::toupper(result[j]);
        }
        
        if((0x0F&value) > 7)
        {
            result[j+1] = ::toupper(result[j+1]);
        }
    }

    result.insert(0, "0x");
    return result;
}



bool HexCaseCheckSum::validate(const std::string &hex) const
{
    if(!checkAddressLen(hex))
    {
        return false;
    }

    std::string normalized = toLowerCase(hex);
    size_t offset = hex.size() - normalized.size();
    Data data = hash(normalized);

    for(size_t i=0, j=offset; i<20; ++i, j+=2)
    {
        unsigned char value = data[i];
        char high = hex[j];
        if(!::isdigit(high))
        {
            if(((value>>4) > 7))
            {
                if(!::isupper(high))
                {
                    return false;
                }
            }
            else
            {
                if(!::islower(high))
                {
                    return false;
                }
            }
        }


        char low = hex[j+1];
        if(!::isdigit(low))
        {
            if(((0x0F&value) > 7))
            {
                if(!::isupper(low))
                {
                    return false;
                }
            }
            else
            {
                if(!::islower(low))
                {
                    return false;
                }
            }
        }
    }

    return true;
}


bool HexCaseCheckSum::checkAddressLen(const std::string &hex) const
{
    size_t hexSize = hex.size();
    return (hexSize==42||hexSize==40);
}


Data HexCaseCheckSum::hash(const std::string &hex) const
{
    Keccak256 hasher;
    return hasher.hash(hex);
}


std::string HexCaseCheckSum::toLowerCase(const std::string &hex) const
{
    size_t resultSize;
    char delimiter = hex[1];
    std::string::const_iterator begin;
    if(delimiter=='x'||delimiter=='X')
    {
        begin = hex.begin()+2;
        resultSize = hex.size() - 2;
    }
    else
    {
        begin = hex.begin();
        resultSize = hex.size();
    }
    std::string result;
    result.resize(resultSize);
    std::transform(begin, hex.end(), result.begin(), ::tolower);
    return result;
}


}
