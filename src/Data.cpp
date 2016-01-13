
#include "Data.hpp"

namespace Stealth{


unsigned char * operator & (Data &data)
{
    return &*data.begin();
}

const unsigned char * operator & (const Data &data)
{
    return &*data.begin();
}

unsigned char operator *(Data &data)
{
    return *data.begin();
}

const unsigned char operator *(const Data &data)
{
    return *data.begin();
}

std::ostream & operator << (std::ostream &os, const Data &data)
{
    for(Data::const_iterator it=data.begin(),end=data.end(); it!=end; ++it)
    {
        os<<(unsigned)*it<<' ';
    }
    return os;
}

}
