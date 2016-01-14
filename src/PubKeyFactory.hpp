#pragma once 

#include "Secp256k1ContextFactory.hpp"
#include "PubKey.hpp"
#include "CompressedPoint.hpp"
#include "Secret.hpp"
#include "PubKeyArchiver.hpp"

namespace BitCrypto{


class PubKeyFactory
{
    public:
        PubKeyFactory();
        PubKeyFactory(const Secp256k1ContextPtr &);

        PubKey createFromSecret(const Secret &secret);
        PubKey createFromCompressed(const Data &);
        PubKey createFromCompressed(const CompressedPoint &);

    private:
        Secp256k1ContextPtr _context;
};


}
