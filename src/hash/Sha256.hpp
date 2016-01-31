#pragma once 

#include "../Data.hpp"


namespace Ethereum{



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


        Data hash(const Data &) const;

        Data hash(const std::string &) const;

};



}

#include "Sha256.ipp"
