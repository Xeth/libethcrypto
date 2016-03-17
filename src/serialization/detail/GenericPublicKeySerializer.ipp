namespace Ethereum{




template<class Encoder>
GenericPublicKeySerializer<Encoder>::GenericPublicKeySerializer()
{}


template<class Encoder>
GenericPublicKeySerializer<Encoder>::GenericPublicKeySerializer(const Secp256k1ContextPtr &context) :
    _binarySerializer(context)
{}


template<class Encoder>
GenericPublicKeySerializer<Encoder>::GenericPublicKeySerializer(const BinaryPublicKeySerializer &serializer) :
    _binarySerializer(serializer)
{}


template<class Encoder>
std::string GenericPublicKeySerializer<Encoder>::serialize(const PublicKey &key, bool compress) const
{
    Encoder encoder;
    if(compress)
    {
        CompressedPoint point = _binarySerializer.serialize<CompressedPoint>(key);
        return encoder.encode(point.begin(), point.end());
    }
    else
    {
        UncompressedPoint point = _binarySerializer.serialize<UncompressedPoint>(key);
        return encoder.encode(point.begin(), point.end());
    }
}




template<class Encoder>
PublicKey GenericPublicKeySerializer<Encoder>::unserialize(const std::string &encoded) const
{
    Encoder encoder;
    Data data = encoder.decode(encoded.begin(), encoded.end());
    return _binarySerializer.unserialize(data);
}

template<class Encoder>
PublicKey GenericPublicKeySerializer<Encoder>::unserialize(const char *buffer, size_t size) const
{
    Encoder encoder;
    Data data = encoder.decode(buffer, buffer+size);
    return _binarySerializer.unserialize(data);
}






}
