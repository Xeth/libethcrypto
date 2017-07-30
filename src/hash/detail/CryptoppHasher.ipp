
namespace Ethereum{


template<class Handler, size_t HashSize>
template<class Iterator>
void CryptoppHasher<Handler, HashSize>::update(Iterator begin, Iterator end)
{
    _handler.Update((const unsigned char *)&*begin, end-begin);
}

template<class Handler, size_t HashSize>
inline void CryptoppHasher<Handler, HashSize>::finalize(unsigned char *out, size_t size)
{
    _handler.TruncatedFinal(out, size);
}

template<class Handler, size_t HashSize>
inline void CryptoppHasher<Handler, HashSize>::finalize(Data &data)
{
    data.resize(Size, 0);
    finalize(&data, data.size());
}

template<class Handler, size_t HashSize>
inline Data CryptoppHasher<Handler, HashSize>::finalize()
{
    Data data;
    finalize(data);
    return data;
}

template<class Handler, size_t HashSize>
template<class Iterator, class OutIterator>
void CryptoppHasher<Handler, HashSize>::hashUnsafe(Iterator begin, Iterator end, OutIterator out)
{
    update(begin, end);
    finalize(&*out, _handler.DigestSize());
}


template<class Handler, size_t HashSize>
template<class Output, class Iterator>
Output CryptoppHasher<Handler, HashSize>::hash(Iterator begin, Iterator end)
{
    Output output;
    output.resize(Size, 0);
    hashUnsafe(begin, end, output.begin());
    return output;
}

template<class Handler, size_t HashSize>
template<class Iterator>
Data CryptoppHasher<Handler, HashSize>::hash(Iterator begin, Iterator end)
{
    return hash<Data>(begin, end);
}


template<class Handler, size_t HashSize>
inline Data CryptoppHasher<Handler, HashSize>::hash(const std::string &input)
{
    return hash(input.begin(), input.end());
}

template<class Handler, size_t HashSize>
inline Data CryptoppHasher<Handler, HashSize>::hash(const Data &input)
{
    return hash(input.begin(), input.end());
}

}
