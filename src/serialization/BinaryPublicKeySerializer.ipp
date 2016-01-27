

namespace Ethereum{


inline BinaryPublicKeySerializer::BinaryPublicKeySerializer()
{}


inline BinaryPublicKeySerializer::BinaryPublicKeySerializer(const Secp256k1ContextPtr &context) :
    Secp256k1Handler(context)
{}


template<class Iterator>
bool BinaryPublicKeySerializer::unserializeNoCheck(Iterator begin, size_t size, PublicKey &key) const
{
    if(!secp256k1_ec_pubkey_parse(getContext().get(), &key, (const unsigned char *)(&*begin), size))
    {
        return false;
    }

    return true;
}


template<class Iterator>
bool BinaryPublicKeySerializer::unserialize(Iterator begin, Iterator end, PublicKey &key) const
{
    size_t size = end - begin;
    
    if(size!=33&&size!=65)
    {
        return false;
    }

    return unserializeNoCheck(begin, size, key);
}


template<class Iterator>
PublicKey BinaryPublicKeySerializer::unserialize(Iterator begin, Iterator end) const
{
    PublicKey key(getContext());
    if(!unserialize(begin, end, key))
    {
        throw std::runtime_error("failed to unserialize point");
    }
    return key;
}


template<class Point>
bool BinaryPublicKeySerializer::unserialize(const Point &point, PublicKey &key) const
{
    if(!validatePointSize(point))
    {
        return false;
    }
    return unserializeNoCheck(point.begin(), point.size(), key);
}


template<class Point>
PublicKey BinaryPublicKeySerializer::unserialize(const Point &point)  const
{
    PublicKey key(getContext());
    if(!unserialize(point, key))
    {
        throw std::runtime_error("invalid serialized point");
    }
    return key;
}


template<class Point>
bool BinaryPublicKeySerializer::serialize(const PublicKey &key, Point &point) const
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
Point BinaryPublicKeySerializer::serialize(const PublicKey &key) const
{
    Point point;
    if(!serialize(key, point))
    {
        throw std::runtime_error("point serialization failed");
    }
    return point;
}


inline int BinaryPublicKeySerializer::getPointFlag(PointTag<CompressedPoint>) const
{
    return SECP256K1_EC_COMPRESSED;
}


inline int BinaryPublicKeySerializer::getPointFlag(PointTag<UncompressedPoint>) const
{
    return SECP256K1_EC_UNCOMPRESSED;
}


inline bool BinaryPublicKeySerializer::validatePointSize(const UncompressedPoint &point) const
{
    return true;
}


inline bool BinaryPublicKeySerializer::validatePointSize(const CompressedPoint &point) const
{
    return true;
}


template<class Point>
bool BinaryPublicKeySerializer::validatePointSize(const Point &point) const
{
    size_t size = point.size();
    return size==33||size==65;
}


}
