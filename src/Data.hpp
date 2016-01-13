#pragma once

#include <vector>
#include <ostream>

namespace Stealth{


typedef std::vector<unsigned char> Data;



unsigned char * operator & (Data &);
const unsigned char * operator & (const Data &);

unsigned char operator *(Data &);
const unsigned char operator *(const Data &);


std::ostream & operator << (std::ostream &, const Data &);





}

