#pragma once

#include "../../PublicKey.hpp"
#include "../../CompressedPoint.hpp"
#include "../../UncompressedPoint.hpp"
#include "../../detail/Secp256k1Handler.hpp"
#include "../BinaryPublicKeySerializer.hpp"



namespace Ethereum{


template<class Encoder>
class GenericPublicKeySerializer : public Secp256k1Handler
{

    public:

        GenericPublicKeySerializer();
        GenericPublicKeySerializer(const Secp256k1ContextPtr &);

        PublicKey unserialize(const std::string &) const;

        void unserialize(const std::string &encoded, CompressedPoint &) const;
        void unserialize(const std::string &encoded, UncompressedPoint &) const;

        std::string serialize(const CompressedPoint &) const;
        std::string serialize(const UncompressedPoint &) const;

        std::string serialize(const PublicKey &, bool compress=true) const;

};



}

#include "GenericPublicKeySerializer.ipp"
