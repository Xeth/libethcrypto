#pragma once

#include "detail/EncoderFacade.hpp"
#include "detail/BufferAdapter.hpp"

namespace Ethereum{




class HexEncoder : public EncoderFacade<HexEncoder>
{
    public:
        typedef EncoderFacade<HexEncoder> Base;

    public:

        using Base::encode;
        using Base::decode;

        template<class Iterator, class Data>
        bool decode(Iterator, Iterator, Data &) const;

        template<class Iterator, class Data>
        void encode(Iterator, Iterator, Data &) const;

        

    private:
        unsigned char decodeChar(char) const;

};



template<class Data>
std::string EncodeHex(const Data &data);

template<class Iterator>
std::string EncodeHex(Iterator begin, Iterator end);

template<class Data>
Data DecodeHex(const std::string &hex);

Data DecodeHex(const std::string &hex);


}

#include "HexEncoder.ipp"


