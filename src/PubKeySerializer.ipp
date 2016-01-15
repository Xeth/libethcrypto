namespace BitCrypto{


template<class Encoder>
PubKeySerializer<Encoder>::PubKeySerializer()
{}


template<class Encoder>
PubKeySerializer<Encoder>::PubKeySerializer(const Secp256k1ContextPtr &context) :
    Secp256k1Handler(context)
{}


template<class Encoder>
std::string PubKeySerializer<Encoder>::serialize(const PubKey &key, bool compress) const
{
    Encoder encoder;
    if(compress)
    {
        CompressedPoint point;
        size_t pointSize = point.size();

        if(!secp256k1_ec_pubkey_serialize(getContext().get(), point.data(), &pointSize, &key, SECP256K1_EC_COMPRESSED))
        {
            throw std::runtime_error("failed to compress pubkey");
        }

        if(pointSize!=point.size())
        {
            throw std::runtime_error("invalid compressed point");
        }

        return encoder.encode(point.begin(), point.end());
    }
    else
    {
        UncompressedPoint point;
        size_t pointSize = point.size();

        if(!secp256k1_ec_pubkey_serialize(getContext().get(), point.data(), &pointSize, &key, SECP256K1_EC_UNCOMPRESSED))
        {
            throw std::runtime_error("failed to compress pubkey");
        }
        
        return encoder.encode(point.begin(), point.end());
    }
}

template<class Encoder>
std::string PubKeySerializer<Encoder>::serialize(const CompressedPoint &point) const
{
    Encoder encoder;
    return encoder.encode(point.begin(), point.end());
}

template<class Encoder>
std::string PubKeySerializer<Encoder>::serialize(const UncompressedPoint &point) const
{
    Encoder encoder;
    return encoder.encode(point.begin(), point.end());
}

template<class Encoder>
void PubKeySerializer<Encoder>::unserialize(const std::string &encoded, CompressedPoint &point) const
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
void PubKeySerializer<Encoder>::unserialize(const std::string &encoded, UncompressedPoint &point) const
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
PubKey PubKeySerializer<Encoder>::unserialize(const std::string &encoded) const
{
    PubKeyFactory factory(getContext());
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());
    return factory.createFromPoint(data);
}




}
