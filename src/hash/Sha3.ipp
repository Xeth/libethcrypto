
namespace Ethereum{


template<class Iterator>
void Sha3::update(Iterator begin, Iterator end)
{
    _handler.Update((const byte *)&*begin, end-begin);
}


inline void Sha3::finalize(unsigned char *out, size_t size)
{
    _handler.TruncatedFinal(out, size);
}


inline void Sha3::finalize(Data &result)
{
    result.resize(32);
    finalize(&result, result.size());
}

inline Data Sha3::finalize()
{
    Data result;
    finalize(result);
    return result;
}


template<class Iterator, class OutIterator>
void Sha3::hashUnsafe(Iterator begin, Iterator end, OutIterator out)
{
    update(begin, end);
    finalize(&*out, _handler.DigestSize());
}


template<class Output, class Iterator>
Output Sha3::hash(Iterator begin, Iterator end)
{
    Output output;
    output.resize(32);
    hashUnsafe(begin, end, output.begin());
    return output;
}


template<class Iterator>
Data Sha3::hash(Iterator begin, Iterator end)
{
    return hash<Data>(begin, end);
}


inline Data Sha3::hash(const std::string &input)
{
    return hash(input.begin(), input.end());
}


inline Data Sha3::hash(const Data &input)
{
    return hash(input.begin(), input.end());
}


}
