
#include <crypto++/sha3.h>

namespace Ethereum{



template<class Iterator, class OutIterator>
void Sha3::hash(Iterator begin, Iterator end, OutIterator out) const
{
    CryptoPP::SHA3_256 hash;
    hash.Update((const byte *)&*begin, end-begin);
    hash.TruncatedFinal(&*out, hash.DigestSize());
}


template<class Output, class Iterator>
Output Sha3::hash(Iterator begin, Iterator end) const
{
    Output output;
    output.resize(32);
    hash(begin, end, output.begin());
    return output;
}


template<class Iterator>
Data Sha3::hash(Iterator begin, Iterator end) const
{
    return hash<Data>(begin, end);
}


inline Data Sha3::hash(const std::string &input) const
{
    return hash(input.begin(), input.end());
}


inline Data Sha3::hash(const Data &input) const
{
    return hash(input.begin(), input.end());
}


}
