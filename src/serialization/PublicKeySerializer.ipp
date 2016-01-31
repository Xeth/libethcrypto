namespace Ethereum{


template<class Iterator>
PublicKey PublicKeySerializer::fromPoint(Iterator begin, Iterator end) const
{
    return _binarySerializer.unserialize(begin, end);
}


}
