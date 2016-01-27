#pragma once

#include "../CompressedPoint.hpp"
#include "../UncompressedPoint.hpp"
#include "../PublicKey.hpp"
#include "../detail/Secp256k1Handler.hpp"


namespace Ethereum{


template<class Point>
class PointTag
{};


class BinaryPublicKeySerializer : public Secp256k1Handler
{

    public:

        BinaryPublicKeySerializer();
        BinaryPublicKeySerializer(const Secp256k1ContextPtr &);

        template<class Point>
        bool serialize(const PublicKey &, Point &) const;

        template<class Point>
        Point serialize(const PublicKey &) const;

        template<class Iterator>
        bool unserialize(Iterator begin, Iterator end, PublicKey &) const;

        template<class Iterator>
        PublicKey unserialize(Iterator begin, Iterator end) const;

        template<class Point>
        bool unserialize(const Point &, PublicKey &) const;

        template<class Point>
        PublicKey unserialize(const Point &) const;

    private:

        template<class Iterator>
        bool unserializeNoCheck(Iterator, size_t, PublicKey &) const;

        int getPointFlag(PointTag<UncompressedPoint>) const;
        int getPointFlag(PointTag<CompressedPoint>) const;

        template<class Point>
        bool validatePointSize(const Point &) const;

        bool validatePointSize(const CompressedPoint &) const;
        bool validatePointSize(const UncompressedPoint &) const;

};


}


#include "BinaryPublicKeySerializer.ipp"
