namespace Ethereum{


template<class Alphabet>
template<class Iterator>
size_t GenericDataEncoder<Alphabet>::strip(Iterator &begin, Iterator end, unsigned char c) const
{
    size_t sz = 0;
    while(begin!=end)
    {
        if(*begin!=c) break;
        begin++;
        sz++;
    }
    return sz;
}


template<class Alphabet>
template<class Iterator, class Data>
void GenericDataEncoder<Alphabet>::encode(Iterator begin, Iterator end, Data &result) const
{
    size_t zeroes = strip(begin, end, 0);
    Fill(result, 0, zeroes+ceil((end - begin) * log(256) / log(Alphabet::base)));

    typename Data::reverse_iterator rBegin = result.rbegin(), rEnd = result.rend();

    while(begin!=end)
    {
        size_t carry = *begin;
        for(typename Data::reverse_iterator it=rBegin; it!=rEnd; ++it)
        {
            carry += 256 * (*it);
            *it = carry % Alphabet::base;
            carry /= Alphabet::base;
        }
        ++begin;
    }

    size_t totalZeroes = 0;
    for(typename Data::iterator it=result.begin(); it!=result.end(); ++it)
    {
        if(*it!=0) break;
        totalZeroes++;
    }

    if(totalZeroes>zeroes)
    {
        Trim(result, totalZeroes-zeroes);
    }

    for(typename Data::iterator it=result.begin(); it!=result.end(); ++it)
    {
        *it=Alphabet::map[(int)*it];
    }

}



template<class Alphabet>
template<class Iterator, class Data>
bool GenericDataEncoder<Alphabet>::decode(Iterator begin, Iterator end, Data &result) const
{
    size_t zeroes = strip(begin, end, Alphabet::map[0]);
    Fill(result, 0,  zeroes + ceil((end-begin) *log(Alphabet::base)/log(256)));

    typename Data::reverse_iterator rBegin=result.rbegin(), rEnd=result.rend();

    while (begin!=end)
    {
        const char* c = strchr(Alphabet::map, *begin);
        if (c == NULL)
        {
            return false;
        }
        size_t carry = c - Alphabet::map;
        for(typename Data::reverse_iterator it=rBegin; it!=rEnd; ++it)
        {
            carry += Alphabet::base * (*it);
            *it = (char ) carry % 256;
            carry /= 256;
        }
        begin++;
    }

    //strip extra zeroes
    size_t totalZeroes = 0;
    for(typename Data::iterator it=result.begin(); it!=result.end(); ++it)
    {
        if(*it!=0)
        {
            break;
        }
        totalZeroes++;
    }

    if(totalZeroes>zeroes)
    {
        Trim(result, totalZeroes-zeroes);
    }
    return true;
}



}
