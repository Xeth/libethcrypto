#pragma once 

#include "../../detail/Data.hpp"


namespace Ethereum{


template<class Handler, size_t HashSize>
class CryptoppHasher
{
    public:
        static const size_t Size = HashSize;

    public:

        template<class Iterator>
        void update(Iterator, Iterator);

        void finalize(unsigned char *, size_t);

        void finalize(Data &);
        Data finalize();

        template<class Iterator, class OutIterator>
        void hashUnsafe(Iterator begin, Iterator end, OutIterator out);

        template<class Output, class Iterator>
        Output hash(Iterator begin, Iterator end);


        template<class Iterator>
        Data hash(Iterator begin, Iterator end);


        Data hash(const Data &);

        Data hash(const std::string &);

    private:
        Handler _handler;

};



}

#include "CryptoppHasher.ipp"
