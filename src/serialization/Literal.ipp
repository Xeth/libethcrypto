namespace Ethereum{

template<class Data>
Data Literal(const std::string &serialized)
{
    HexEncoder encoder;
    Data result;
    encoder.decode(serialized.begin(), serialized.end(), result);
    return result;
}




}
