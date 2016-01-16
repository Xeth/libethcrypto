namespace BitCrypto{




template<class Encoder>
GenericPubKeySerializer<Encoder>::GenericPubKeySerializer()
{}


template<class Encoder>
GenericPubKeySerializer<Encoder>::GenericPubKeySerializer(const Secp256k1ContextPtr &context) :
    Secp256k1Handler(context)
{}


template<class Encoder>
std::string GenericPubKeySerializer<Encoder>::serialize(const PubKey &key, bool compress) const
{
    Encoder encoder;
    BinaryPubKeySerializer serializer;
    if(compress)
    {
        CompressedPoint point = serializer.serialize<CompressedPoint>(key);
        return encoder.encode(point.begin(), point.end());
    }
    else
    {
        UncompressedPoint point = serializer.serialize<UncompressedPoint>(key);
        return encoder.encode(point.begin(), point.end());
    }
}

template<class Encoder>
std::string GenericPubKeySerializer<Encoder>::serialize(const CompressedPoint &point) const
{
    Encoder encoder;
    return encoder.encode(point.begin(), point.end());
}

template<class Encoder>
std::string GenericPubKeySerializer<Encoder>::serialize(const UncompressedPoint &point) const
{
    Encoder encoder;
    return encoder.encode(point.begin(), point.end());
}

template<class Encoder>
void GenericPubKeySerializer<Encoder>::unserialize(const std::string &encoded, CompressedPoint &point) const
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
void GenericPubKeySerializer<Encoder>::unserialize(const std::string &encoded, UncompressedPoint &point) const
{
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());

    if(data.size() != 65)
    {
        throw std::runtime_error("Invalid serialized compressed point");
    }
    std::copy(data.begin(), data.end(), point.begin());
}



template<class Encoder>
PubKey GenericPubKeySerializer<Encoder>::unserialize(const std::string &encoded) const
{
    BinaryPubKeySerializer serializer(getContext());
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());
    return serializer.unserialize(data);
}







}
