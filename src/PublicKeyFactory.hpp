#pragma once 

#include "detail/Secp256k1Handler.hpp"
#include "PublicKey.hpp"
#include "CompressedPoint.hpp"
#include "UncompressedPoint.hpp"
#include "PrivateKey.hpp"
#include "Data.hpp"
#include "serialization/BinaryPublicKeySerializer.hpp"


namespace Ethereum{


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
