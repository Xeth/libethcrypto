namespace BitCrypto{


template<class Encoder>
std::string GenericHashSerializer<Encoder>::serialize(const Data &data)
{
    Data reversed;
    reversed.resize(data.size());
    std::reverse_copy(data.begin(), data.end(), reversed.begin());
    return _encoder.encode(reversed.begin(), reversed.end());
}


template<class Encoder>
Data GenericHashSerializer<Encoder>::unserialize(const std::string &encoded)
{
    Data result = _encoder.decode(encoded);
    std::reverse(result.begin(), result.end());
    return result;
}


}
