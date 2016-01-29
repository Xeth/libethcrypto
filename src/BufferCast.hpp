#pragma once 

#include <string>

#include "Data.hpp"

namespace Ethereum{


template<class Data>
unsigned char * BufferCast(Data &);


template<class Data>
const unsigned char * BufferCast(const Data &);


unsigned char * BufferCast(Data &);


const unsigned char * BufferCast(const Data &);


}


#include "BufferCast.ipp"
