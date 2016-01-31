#pragma once 

#include "detail/Secp256k1Handler.hpp"
#include "PublicKey.hpp"
#include "CompressedPoint.hpp"
#include "UncompressedPoint.hpp"
#include "PrivateKey.hpp"
#include "Data.hpp"

#include "serialization/detail/BinaryPublicKeySerializer.hpp"


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

        template<class Secret>
        PublicKey createFromSecret(const Secret &secret);

    private:

        template<class Secret>
        PublicKey createFromSecretData(const Secret &);

        bool validateSecretSize(const PrivateKey &);

        template<class Secret>
        bool validateSecretSize(const Secret &);

        template<class Point>
        PublicKey createFromPointData(const Point &);
};


}

#include "PublicKeyFactory.ipp"
