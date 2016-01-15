#pragma once 

#include "Secp256k1ContextFactory.hpp"
#include "PubKey.hpp"
#include "CompressedPoint.hpp"
#include "UncompressedPoint.hpp"
#include "Secret.hpp"
#include "Data.hpp"

namespace BitCrypto{


class PubKeyFactory
{
    public:
        PubKeyFactory();
        PubKeyFactory(const Secp256k1ContextPtr &);

        PubKey createFromSecret(const Secret &secret);
        PubKey createFromPoint(const CompressedPoint &);
        PubKey createFromPoint(const UncompressedPoint &);
        PubKey createFromPoint(const Data &);

    private:
        PubKey createFromPointData(const unsigned char *ptr, size_t size);

    private:
        Secp256k1ContextPtr _context;
};


}
