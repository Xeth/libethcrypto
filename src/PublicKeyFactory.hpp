#pragma once 

#include "bitcrypto/detail/Secp256k1Handler.hpp"
#include "bitcrypto/PublicKey.hpp"
#include "bitcrypto/CompressedPoint.hpp"
#include "bitcrypto/UncompressedPoint.hpp"
#include "bitcrypto/PrivateKey.hpp"
#include "bitcrypto/Data.hpp"
#include "bitcrypto/serialization/BinaryPublicKeySerializer.hpp"


namespace BitCrypto{


class PublicKeyFactory : public Secp256k1Handler
{
    public:
        PublicKeyFactory();
        PublicKeyFactory(const Secp256k1ContextPtr &);

        PublicKey createFromSecret(const PrivateKey &secret);
        PublicKey createFromPoint(const CompressedPoint &);
        PublicKey createFromPoint(const UncompressedPoint &);
        PublicKey createFromPoint(const Data &);

    private:
        template<class Point>
        PublicKey createFromPointData(const Point &);
};


}
