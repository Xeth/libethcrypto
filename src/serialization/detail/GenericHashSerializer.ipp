namespace Ethereum{


template<class Encoder>
std::string GenericHashSerializer<Encoder>::serialize(const Data &data) const
{
    Encoder encoder;
    Data reversed;
    reversed.resize(data.size());
    std::reverse_copy(data.begin(), data.end(), reversed.begin());
    return encoder.encode(reversed.begin(), reversed.end());
}


template<class Encoder>
Data GenericHashSerializer<Encoder>::unserialize(const std::string &encoded) const
{
    Encoder encoder;
    Data result = encoder.decode(encoded);
    std::reverse(result.begin(), result.end());
    return result;
}


}
