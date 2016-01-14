
#include "external/hash_impl.h"

namespace Stealth{



template<class Iterator, class OutIterator>
void Sha256::hash(Iterator begin, Iterator end, OutIterator out) const
{
    secp256k1_sha256_t hash;
    secp256k1_sha256_initialize(&hash);
    secp256k1_sha256_write(&hash, &*begin, end-begin);
    secp256k1_sha256_finalize(&hash, &*out);
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


template<class Input>
Data Sha256::hash(const Input &input) const
{
    return hash(input.begin(), input.end());
}


}
