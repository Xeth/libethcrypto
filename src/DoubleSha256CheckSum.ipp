
#include <iostream>

namespace Ethereum{



template<class Iterator>
uint32_t DoubleSha256CheckSum::checksum(Iterator begin, Iterator end) const
{
    DoubleHash<Sha256> hasher;
    Data result = hasher.hash(begin, end);
    return (result[0]|result[1]<<8|result[2]<<16|result[3]<<24);
}


template<class Data>
uint32_t DoubleSha256CheckSum::checksum(const Data &data) const
{
    return checksum(data.begin(), data.end());
}


template<class Iterator>
uint32_t DoubleSha256CheckSum::operator()(Iterator begin, Iterator end) const
{
    return checksum(begin, end);
}


template<class Data>
uint32_t DoubleSha256CheckSum::operator()(const Data &data) const
{
    return checksum(data);
}


}
