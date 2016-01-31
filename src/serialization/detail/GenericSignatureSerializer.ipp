
namespace Ethereum{


template<class Encoder>
GenericSignatureSerializer<Encoder>::GenericSignatureSerializer()
{}


template<class Encoder>
GenericSignatureSerializer<Encoder>::GenericSignatureSerializer(const BinarySignatureSerializer &binSerializer) :
    _serializer(binSerializer)
{}


template<class Encoder>
std::string GenericSignatureSerializer<Encoder>::serialize(const Signature &signature, bool compact) const
{
    Data result = _serializer.serialize(signature, compact);
    Encoder encoder;
    return encoder.encode(result.begin(), result.end());
}


template<class Encoder>
Signature GenericSignatureSerializer<Encoder>::unserialize(const std::string &serialized) const
{
    Encoder encoder;
    Data bin = encoder.decode(serialized);
    return _serializer.unserialize(bin);
}


}
