
namespace Ethereum{

template<class Encoder>
std::string GenericPointSerializer<Encoder>::serialize(const CompressedPoint &point) const
{
    Encoder encoder;
    return encoder.encode(point.begin(), point.end());
}

template<class Encoder>
std::string GenericPointSerializer<Encoder>::serialize(const UncompressedPoint &point) const
{
    Encoder encoder;
    return encoder.encode(point.begin(), point.end());
}

template<class Encoder>
void GenericPointSerializer<Encoder>::unserialize(const std::string &encoded, CompressedPoint &point) const
{
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());

    if(data.size() != 33)
    {
        throw std::runtime_error("Invalid serialized compressed point");
    }
    std::copy(data.begin(), data.end(), point.begin());
}


template<class Encoder>
void GenericPointSerializer<Encoder>::unserialize(const std::string &encoded, UncompressedPoint &point) const
{
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());

    if(data.size() != 65)
    {
        throw std::runtime_error("Invalid serialized compressed point");
    }
    std::copy(data.begin(), data.end(), point.begin());
}


}
