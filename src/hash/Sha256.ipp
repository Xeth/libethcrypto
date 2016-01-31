

#include <crypto++/sha.h>

namespace Ethereum{



template<class Iterator, class OutIterator>
void Sha256::hash(Iterator begin, Iterator end, OutIterator out) const
{
    CryptoPP::SHA256 hash;
    hash.Update((const byte *)&*begin, end-begin);
    hash.TruncatedFinal(&*out, hash.DigestSize());
}


template<class Output, class Iterator>
Output Sha256::hash(Iterator begin, Iterator end) const
{
    Output output;
    output.resize(32);
    hash(begin, end, output.begin());
    return output;
}


template<class Iterator>
Data Sha256::hash(Iterator begin, Iterator end) const
{
    return hash<Data>(begin, end);
}




inline Data Sha256::hash(const std::string &input) const
{
    return hash(input.begin(), input.end());
}


inline Data Sha256::hash(const Data &input) const
{
    return hash(input.begin(), input.end());
}

}
