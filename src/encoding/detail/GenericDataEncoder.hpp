#pragma once

#include <string>
#include <cstring>
#include <cmath>
#include <stdexcept>

#include "bitcrypto/Data.hpp"


namespace BitCrypto{



template<class Alphabet>
class GenericDataEncoder
{

    public:

        template<class Iterator, class Data>
        bool decode(Iterator, Iterator, Data &);

        template<class Data, class Iterator>
        Data decode(Iterator, Iterator);

        template<class Iterator>
        Data decode(Iterator, Iterator);

        template<class Iterator, class Data>
        void encode(Iterator, Iterator, Data &);

        template<class Data, class Iterator>
        Data encode(Iterator, Iterator);

        template<class Iterator>
        std::string encode(Iterator, Iterator);

        Data decode(const std::string &);

        std::string encode(const Data &);

    protected:
        template<class Iterator>
        size_t strip(Iterator &begin, Iterator end, unsigned char c);

};



}

#include "GenericDataEncoder.ipp"
