#pragma once

#include <cstring>
#include <cmath>

#include "BufferAdapter.hpp"
#include "EncoderFacade.hpp"

namespace Ethereum{



template<class Alphabet>
class GenericDataEncoder : public EncoderFacade<GenericDataEncoder<Alphabet> >
{

    public:
        typedef EncoderFacade<GenericDataEncoder<Alphabet> > Base;

    public:

        using Base::encode;
        using Base::decode;

        template<class Iterator, class Data>
        bool decode(Iterator, Iterator, Data &) const;

        template<class Iterator, class Data>
        void encode(Iterator, Iterator, Data &) const;


    protected:
        template<class Iterator>
        size_t strip(Iterator &begin, Iterator end, unsigned char c) const;

};



}

#include "GenericDataEncoder.ipp"
