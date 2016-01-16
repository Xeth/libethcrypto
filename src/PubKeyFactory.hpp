#pragma once 

#include "bitcrypto/detail/Secp256k1Handler.hpp"
#include "bitcrypto/PubKey.hpp"
#include "bitcrypto/CompressedPoint.hpp"
#include "bitcrypto/UncompressedPoint.hpp"
#include "bitcrypto/Secret.hpp"
#include "bitcrypto/Data.hpp"

namespace BitCrypto{


class PubKeyFactory : public Secp256k1Handler
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

};


}
