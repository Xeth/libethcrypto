
namespace Ethereum{


template<class Iterator, class Data>
bool HexEncoder::decode(Iterator begin, Iterator end, Data &result) const
{
    size_t size = end - begin;
    if(size>=2)
    {
        Iterator it = begin + 1;
        if(*it=='x'||*it=='X')
        {
            begin+=2;
            size-=2;
        }
    }
    size_t rest = size&1;
    size>>=1;
    try
    {
        Resize(result, size+rest);
        int i;
        if(rest)
        {
            result[0] = decodeChar(*begin);
            ++begin;
            i = 1;
            ++size;
        }
        else
        {
            i = 0;
        }

        for(; i<size; ++i)
        {
            result[i] = decodeChar(*begin)<<4|decodeChar(*(++begin));
            ++begin;
        }

    }
    catch(...)
    {
        return false;
    }
    return true;
}


inline unsigned char HexEncoder::decodeChar(char c) const
{
    switch(c)
    {
        case '0': return 0x0;
        case '1': return 0x1;
        case '2': return 0x2;
        case '3': return 0x3;
        case '4': return 0x4;
        case '5': return 0x5;
        case '6': return 0x6;
        case '7': return 0x7;
        case '8': return 0x8;
        case '9': return 0x9;
        case 'A': return 0xA;
        case 'B': return 0xB;
        case 'C': return 0xC;
        case 'D': return 0xD;
        case 'E': return 0xE;
        case 'F': return 0xF;
        case 'a': return 0xA;
        case 'b': return 0xB;
        case 'c': return 0xC;
        case 'd': return 0xD;
        case 'e': return 0xE;
        case 'f': return 0xF;
    }

    throw std::runtime_error("invalid hex character");
}


template<class Iterator, class Data>
void HexEncoder::encode(Iterator begin, Iterator end, Data &result) const
{
    const char *alphabet = "0123456789abcdef";
    size_t size = end-begin;
    size<<=1;
    {
        Resize(result, size);
        for(int i=0;begin!=end;++begin)
        {
            unsigned char value = *begin;
            result[i] = alphabet[value>>4];
            result[++i] = alphabet[0x0F&value];
            ++i;
        }
    }
}



template<class Data>
std::string EncodeHex(const Data &data)
{
    HexEncoder encoder;
    return encoder.encode(data.begin(), data.end());
}


template<class Iterator>
std::string EncodeHex(Iterator begin, Iterator end)
{
    HexEncoder encoder;
    return encoder.encode(begin, end);
}

template<class Data>
Data DecodeHex(const std::string &hex)
{
    HexEncoder encoder;
    return encoder.decode<Data>(hex.begin(), hex.end());
}

inline Data DecodeHex(const std::string &hex)
{
    HexEncoder encoder;
    return encoder.decode(hex);
}

}
