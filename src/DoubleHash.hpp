#pragma once 

#include "Data.hpp"

namespace Ethereum{


template<class Hash>
class DoubleHash
{
    public:

        template<class Iterator, class OutIterator>
        void hash(Iterator begin, Iterator end, OutIterator out) const;

        template<class Output, class Iterator>
        Output hash(Iterator begin, Iterator end) const;


        template<class Iterator>
        Data hash(Iterator begin, Iterator end) const;


        template<class Input>
        Data hash(const Input &input) const;

};


}

#include "DoubleHash.ipp"
