#pragma once 

#include "Secp256k1ContextFactory.hpp"
#include "PubKey.hpp"
#include "CompressedPoint.hpp"
#include "UncompressedPoint.hpp"
#include "Secret.hpp"

namespace BitCrypto{


class PubKeyFactory
{
    public:
        PubKeyFactory();
        PubKeyFactory(const Secp256k1ContextPtr &);

        PubKey createFromSecret(const Secret &secret);
        PubKey createFromPoint(const CompressedPoint &);
        PubKey createFromPoint(const UncompressedPoint &);

    private:
        template<class Point>
        PubKey createFromPointData(const Point &);

    private:
        Secp256k1ContextPtr _context;
};


}
