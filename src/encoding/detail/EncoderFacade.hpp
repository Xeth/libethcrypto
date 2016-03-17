#pragma once

#include <string>
#include <stdexcept>
#include <sstream>

#include "../../Data.hpp"

namespace Ethereum{


template<class Encoder>
class EncoderFacade 
{
    public:

        template<class Data, class Iterator>
        Data decode(Iterator, Iterator) const;

        template<class Iterator>
        Data decode(Iterator, Iterator) const;

        template<class Data, class Iterator>
        Data encode(Iterator, Iterator) const;

        template<class Iterator>
        std::string encode(Iterator, Iterator) const;

        Data decode(const std::string &) const;

        std::string encode(const Data &) const;

};


}

#include "EncoderFacade.ipp"
