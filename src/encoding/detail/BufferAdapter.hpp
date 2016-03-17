#pragma once

#include <boost/array.hpp>
#include <sstream>
#include <stdexcept>


namespace Ethereum{


template<class Data>
class BufferAdapter
{
    public:
        BufferAdapter(Data &);

        void resize(size_t);
        void assign(unsigned char, size_t);
        void trim(size_t);

    private:
        Data &_data;
};


template<class T, size_t size>
class BufferAdapter<boost::array<T, size> >
{
    public:
        BufferAdapter(boost::array<T, size> &);

        void resize(size_t);
        void assign(unsigned char, size_t);
        void trim(size_t);

    private:
        void checkSize(size_t);

    private:
        boost::array<T, size> &_data;
};


template<class T, size_t size>
BufferAdapter<boost::array<T, size> > MakeBufferAdapter(boost::array<T, size> &);

template<class Data>
BufferAdapter<Data> MakeBufferAdapter(Data &);


/* Utils */

template<class Data>
void Trim(Data &, size_t);

template<class Data>
void Fill(Data &, unsigned char, size_t);

template<class Data>
void Resize(Data &, size_t);


template<class Data>
void Trim(BufferAdapter<Data> , size_t);

template<class Data>
void Fill(BufferAdapter<Data> , unsigned char, size_t);

template<class Data>
void Resize(BufferAdapter<Data> , size_t);




}


#include "BufferAdapter.ipp"

