namespace Ethereum{


template<class Encoder>
template<class Data, class Iterator>
Data EncoderFacade<Encoder>::encode(Iterator begin, Iterator end) const
{
    Data result;
    static_cast<const Encoder*>(this)->encode(begin, end, result);
    return result;
}


template<class Encoder>
template<class Iterator>
std::string EncoderFacade<Encoder>::encode(Iterator begin, Iterator end) const
{
    return encode<std::string>(begin, end);
}


template<class Encoder>
template<class Data, class Iterator>
Data EncoderFacade<Encoder>::decode(Iterator begin, Iterator end) const 
{
    Data result;
    if(!static_cast<const Encoder*>(this)->decode(begin, end, result))
    {
        throw std::runtime_error("failed to decode");
    }
    return result;
}


template<class Encoder>
template<class Iterator>
Data EncoderFacade<Encoder>::decode(Iterator begin, Iterator end) const
{
    return decode<Data>(begin, end);
}


template<class Encoder>
Data EncoderFacade<Encoder>::decode(const std::string &input) const
{
    return decode<Data>(reinterpret_cast<const unsigned char *>(input.data()), reinterpret_cast<const unsigned char *>(input.data()+input.size()));
}


template<class Encoder>
std::string EncoderFacade<Encoder>::encode(const Data &input) const
{
    return encode(input.begin(), input.end());
}

}
