
namespace Ethereum{


template<class Iterator>
void Sha256::update(Iterator begin, Iterator end)
{
    _handler.Update((const byte *)&*begin, end-begin);
}

inline void Sha256::finalize(unsigned char *out, size_t size)
{
    _handler.TruncatedFinal(out, size);
}

inline void Sha256::finalize(Data &data)
{
    data.resize(32);
    finalize(&data, data.size());
}

inline Data Sha256::finalize()
{
    Data data;
    finalize(data);
    return data;
}

template<class Iterator, class OutIterator>
void Sha256::hashUnsafe(Iterator begin, Iterator end, OutIterator out)
{
    update(begin, end);
    finalize(&*out, _handler.DigestSize());
}


template<class Output, class Iterator>
Output Sha256::hash(Iterator begin, Iterator end)
{
    Output output;
    output.resize(32);
    hashUnsafe(begin, end, output.begin());
    return output;
}


template<class Iterator>
Data Sha256::hash(Iterator begin, Iterator end)
{
    return hash<Data>(begin, end);
}


inline Data Sha256::hash(const std::string &input)
{
    return hash(input.begin(), input.end());
}


inline Data Sha256::hash(const Data &input)
{
    return hash(input.begin(), input.end());
}

}
