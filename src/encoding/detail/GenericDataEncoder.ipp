namespace Ethereum{


template<class Alphabet>
template<class Iterator>
size_t GenericDataEncoder<Alphabet>::strip(Iterator &begin, Iterator end, unsigned char c)
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
void GenericDataEncoder<Alphabet>::encode(Iterator begin, Iterator end, Data &result)
{
    size_t zeroes;
    if(Alphabet::strip)
    {
        zeroes = strip(begin, end, 0);
//        result.assign(zeroes+ceil((end - begin) * log(256) / log(Alphabet::base)), 0);
        assign(result, 0, zeroes+ceil((end - begin) * log(256) / log(Alphabet::base)));
    }
    else
    {
//        result.assign(ceil((end - begin) * log(256) / log(Alphabet::base)), 0);
        assign(result, 0, ceil((end - begin) * log(256) / log(Alphabet::base)));
    }

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

    if(Alphabet::strip)
    {
        size_t totalZeroes = 0;
        for(typename Data::iterator it=result.begin(); it!=result.end(); ++it)
        {
            if(*it!=0) break;
            totalZeroes++;
        }

        if(totalZeroes>zeroes)
        {
            trim(result, totalZeroes-zeroes);
//            result.erase(0, totalZeroes-zeroes);
        }
    }

    for(typename Data::iterator it=result.begin(); it!=result.end(); ++it)
    {
        *it=Alphabet::map[(int)*it];
    }

}


template<class Alphabet>
template<class Data>
void GenericDataEncoder<Alphabet>::assign(Data &result,  unsigned char value, size_t size)
{
    result.assign(size, value);
}


template<class Alphabet>
template<class Data>
void GenericDataEncoder<Alphabet>::trim(Data &result, size_t size)
{
//    result.erase(0, size);
    result.erase(result.begin(), result.begin()+size);
}


template<class Alphabet>
template<class T, size_t capacity>
void GenericDataEncoder<Alphabet>::assign(boost::array<T, capacity> &result, unsigned char value, size_t size)
{
    if(size > capacity)
    {
        throw std::runtime_error("container overflow");
    }

    std::fill_n(result.begin(),size, value);
}


template<class Alphabet>
template<class T, size_t capacity>
void GenericDataEncoder<Alphabet>::trim(boost::array<T, capacity> &, size_t)
{}

template<class Alphabet>
template<class Data, class Iterator>
Data GenericDataEncoder<Alphabet>::encode(Iterator begin, Iterator end)
{
    Data result;
    encode(begin, end, result);
    return result;
}


template<class Alphabet>
template<class Iterator>
std::string GenericDataEncoder<Alphabet>::encode(Iterator begin, Iterator end)
{
    return encode<std::string>(begin, end);
}


template<class Alphabet>
template<class Iterator, class Data>
bool GenericDataEncoder<Alphabet>::decode(Iterator begin, Iterator end, Data &result)
{
    size_t zeroes;
    if(Alphabet::strip)
    {
        zeroes = strip(begin, end, Alphabet::map[0]);
        assign(result, 0,  zeroes + ceil((end-begin) *log(Alphabet::base)/log(256)));
//        result.assign(zeroes + ceil((end-begin) *log(Alphabet::base)/log(256)), 0);
    }
    else
    {
        assign(result, 0, ceil((end-begin) *log(Alphabet::base)/log(256)));
//        result.assign(ceil((end-begin) *log(Alphabet::base)/log(256)), 0);
    }

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

    if(Alphabet::strip)
    {
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
            trim(result, totalZeroes-zeroes);
//            result.erase(result.begin(), result.begin()+(totalZeroes-zeroes));
        }
    }
    return true;
}


template<class Alphabet>
template<class Data, class Iterator>
Data GenericDataEncoder<Alphabet>::decode(Iterator begin, Iterator end)
{
    Data result;
    if(!decode(begin, end, result))
    {
        throw std::runtime_error("failed to decode");
    }
    return result;
}


template<class Alphabet>
template<class Iterator>
Data GenericDataEncoder<Alphabet>::decode(Iterator begin, Iterator end)
{
    return decode<Data>(begin, end);
}


template<class Alphabet>
Data GenericDataEncoder<Alphabet>::decode(const std::string &input)
{
    return decode<Data>(input.begin(), input.end());
}


template<class Alphabet>
std::string GenericDataEncoder<Alphabet>::encode(const Data &input)
{
    return encode(input.begin(), input.end());
}

}
