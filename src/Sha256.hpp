#pragma once 

#include "external/hash.h"
#include "Data.hpp"


namespace Stealth{



class Sha256
{
    public:
        static const size_t Size = 32;

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

#include "Sha256.ipp"
