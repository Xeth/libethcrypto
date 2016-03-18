#pragma once 

#include <algorithm>

#include "../../detail/Data.hpp"


namespace Ethereum{


template<class Encoder>
class GenericHashSerializer
{
    public:

        std::string serialize(const Data &) const;
        Data unserialize(const std::string &) const;

};


}

#include "GenericHashSerializer.ipp"
