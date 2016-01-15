namespace BitCrypto{


template<class Encoder>
PubKeySerializer<Encoder>::PubKeySerializer()
{}


template<class Encoder>
PubKeySerializer<Encoder>::PubKeySerializer(const Secp256k1ContextPtr &context) :
    _context(context)
{}


template<class Encoder>
std::string PubKeySerializer<Encoder>::serialize(const PubKey &key) const
{
    Encoder encoder;
    PubKeyArchiver archiver(_context);
    CompressedPoint point = archiver.compress(key);

    return encoder.encode(point.begin(), point.end());
}

template<class Encoder>
std::string PubKeySerializer<Encoder>::serialize(const CompressedPoint &point) const
{
    Encoder encoder;
    return encoder.encode(point.begin(), point.end());
}


template<class Encoder>
CompressedPoint PubKeySerializer<Encoder>::unserializeCompressed(const std::string &encoded) const
{
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());

    if(data.size() != 33)
    {
        throw std::runtime_error("Invalid serialized compressed point");
    }

    CompressedPoint point;
    std::copy(data.begin(), data.end(), point.begin());
    return point;
}

template<class Encoder>
PubKey PubKeySerializer<Encoder>::unserialize(const std::string &encoded) const
{
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());
    PubKeyArchiver archiver(_context);
    return archiver.decompress(data);
}


}
