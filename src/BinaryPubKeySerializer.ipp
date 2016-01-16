

namespace BitCrypto{


inline BinaryPubKeySerializer::BinaryPubKeySerializer()
{}


inline BinaryPubKeySerializer::BinaryPubKeySerializer(const Secp256k1ContextPtr &context) :
    Secp256k1Handler(context)
{}


template<class Iterator>
bool BinaryPubKeySerializer::unserializeNoCheck(Iterator begin, size_t size, PubKey &key) const
{
    if(!secp256k1_ec_pubkey_parse(getContext().get(), &key, (const unsigned char *)(&*begin), size))
    {
        return false;
    }

    return true;
}


template<class Iterator>
bool BinaryPubKeySerializer::unserialize(Iterator begin, Iterator end, PubKey &key) const
{
    size_t size = end - begin;
    
    if(size!=33&&size!=65)
    {
        return false;
    }

    return unserializeNoCheck(begin, size, key);
}


template<class Iterator>
PubKey BinaryPubKeySerializer::unserialize(Iterator begin, Iterator end) const
{
    PubKey key(getContext());
    if(!unserialize(begin, end, key))
    {
        throw std::runtime_error("failed to unserialize point");
    }
    return key;
}


template<class Point>
bool BinaryPubKeySerializer::unserialize(const Point &point, PubKey &key) const
{
    if(!validatePointSize(point))
    {
        return false;
    }
    return unserializeNoCheck(point.begin(), point.size(), key);
}


template<class Point>
PubKey BinaryPubKeySerializer::unserialize(const Point &point)  const
{
    PubKey key(getContext());
    if(!unserialize(point, key))
    {
        throw std::runtime_error("invalid compressed point");
    }
    return key;
}


template<class Point>
bool BinaryPubKeySerializer::serialize(const PubKey &key, Point &point) const
{
    size_t pointSize = point.size();

    if(!secp256k1_ec_pubkey_serialize(getContext().get(), point.data(), &pointSize, &key, getPointFlag(PointTag<Point>())))
    {
        return false;
    }

    if(pointSize!=point.size())
    {
        return false;
    }
    return true;
}


template<class Point>
Point BinaryPubKeySerializer::serialize(const PubKey &key) const
{
    Point point;
    if(!serialize(key, point))
    {
        throw std::runtime_error("point serialization failed");
    }
    return point;
}


inline int BinaryPubKeySerializer::getPointFlag(PointTag<CompressedPoint>) const
{
    return SECP256K1_EC_COMPRESSED;
}


inline int BinaryPubKeySerializer::getPointFlag(PointTag<UncompressedPoint>) const
{
    return SECP256K1_EC_UNCOMPRESSED;
}


inline bool BinaryPubKeySerializer::validatePointSize(const UncompressedPoint &point) const
{
    return true;
}


inline bool BinaryPubKeySerializer::validatePointSize(const CompressedPoint &point) const
{
    return true;
}


template<class Point>
bool BinaryPubKeySerializer::validatePointSize(const Point &point) const
{
    size_t size = point.size();
    return size==33||size==65;
}


}
