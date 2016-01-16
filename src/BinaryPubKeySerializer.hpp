#pragma once

#include "bitcrypto/CompressedPoint.hpp"
#include "bitcrypto/UncompressedPoint.hpp"
#include "bitcrypto/PubKey.hpp"
#include "bitcrypto/detail/Secp256k1Handler.hpp"


namespace BitCrypto{


template<class Point>
class PointTag
{};


class BinaryPubKeySerializer : public Secp256k1Handler
{

    public:

        BinaryPubKeySerializer();
        BinaryPubKeySerializer(const Secp256k1ContextPtr &);

        template<class Point>
        bool serialize(const PubKey &, Point &) const;

        template<class Point>
        Point serialize(const PubKey &) const;

        template<class Iterator>
        bool unserialize(Iterator begin, Iterator end, PubKey &) const;

        template<class Iterator>
        PubKey unserialize(Iterator begin, Iterator end) const;

        template<class Point>
        bool unserialize(const Point &, PubKey &) const;

        template<class Point>
        PubKey unserialize(const Point &) const;

    private:

        template<class Iterator>
        bool unserializeNoCheck(Iterator, size_t, PubKey &) const;

        int getPointFlag(PointTag<UncompressedPoint>) const;
        int getPointFlag(PointTag<CompressedPoint>) const;

        template<class Point>
        bool validatePointSize(const Point &) const;

        bool validatePointSize(const CompressedPoint &) const;
        bool validatePointSize(const UncompressedPoint &) const;

};


}


#include "BinaryPubKeySerializer.ipp"
