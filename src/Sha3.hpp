#pragma once 

#include <string>
#include "Data.hpp"


namespace Ethereum{



class Sha3
{
    public:

        template<class Iterator, class OutIterator>
        void hash(Iterator begin, Iterator end, OutIterator out) const;

        template<class Output, class Iterator>
        Output hash(Iterator begin, Iterator end) const;


        template<class Iterator>
        Data hash(Iterator begin, Iterator end) const;


        Data hash(const Data &) const;

        Data hash(const std::string &) const;
};



}

#include "Sha3.ipp"
