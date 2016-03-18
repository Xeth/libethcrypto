#pragma once 

#include "../detail/Secp256k1Handler.hpp"
#include "../detail/Data.hpp"

#include "PublicKey.hpp"
#include "CompressedPoint.hpp"
#include "UncompressedPoint.hpp"
#include "PrivateKey.hpp"


#include "../serialization/detail/BinaryPublicKeySerializer.hpp"


namespace Ethereum{


class PublicKeyFactory : public Secp256k1Handler
{
    public:
        PublicKeyFactory();
        PublicKeyFactory(const Secp256k1ContextPtr &);

        PublicKey createFromSecret(const PrivateKey &secret) const;
        PublicKey createFromPoint(const CompressedPoint &) const;
        PublicKey createFromPoint(const UncompressedPoint &) const;
        PublicKey createFromPoint(const Data &) const;

        template<class Secret>
        PublicKey createFromSecret(const Secret &secret) const;

    private:

        template<class Secret>
        PublicKey createFromSecretData(const Secret &) const;

        bool validateSecretSize(const PrivateKey &) const;

        template<class Secret>
        bool validateSecretSize(const Secret &) const;

        template<class Point>
        PublicKey createFromPointData(const Point &) const;
};


PublicKey MakePublicKey(const PrivateKey &);


}

#include "PublicKeyFactory.ipp"
