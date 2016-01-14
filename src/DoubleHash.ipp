namespace Stealth{


template<class Hash>
template<class Iterator, class OutIterator>
void DoubleHash<Hash>::hash(Iterator begin, Iterator end, OutIterator out) const
{
    Hash hasher;
    Data firstHash = hasher.hash(begin, end);
    hasher.hash(firstHash.begin(), firstHash.end(), out);
}


template<class Hash>
template<class Output, class Iterator>
Output DoubleHash<Hash>::hash(Iterator begin, Iterator end) const
{
    Output result;
    result.resize(Hash::Size);
    hash(begin, end, result.begin());
    return result;
}


template<class Hash>
template<class Iterator>
Data DoubleHash<Hash>::hash(Iterator begin, Iterator end) const
{
    return hash<Data>(begin, end);
}


template<class Hash>
template<class Input>
Data DoubleHash<Hash>::hash(const Input &input) const
{
    return hash(input.begin(), input.end());
}


}
