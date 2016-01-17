#pragma once

#include "bitcrypto/PublicKey.hpp"
#include "bitcrypto/CompressedPoint.hpp"
#include "bitcrypto/UncompressedPoint.hpp"
#include "bitcrypto/detail/Secp256k1Handler.hpp"
#include "bitcrypto/serialization/BinaryPublicKeySerializer.hpp"



namespace BitCrypto{


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
