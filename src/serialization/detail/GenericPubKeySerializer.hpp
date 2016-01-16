#pragma once

#include "bitcrypto/PubKey.hpp"
#include "bitcrypto/CompressedPoint.hpp"
#include "bitcrypto/UncompressedPoint.hpp"
#include "bitcrypto/detail/Secp256k1Handler.hpp"
#include "bitcrypto/serialization/BinaryPubKeySerializer.hpp"



namespace BitCrypto{


template<class Encoder>
class GenericPubKeySerializer : public Secp256k1Handler
{

    public:

        GenericPubKeySerializer();
        GenericPubKeySerializer(const Secp256k1ContextPtr &);

        PubKey unserialize(const std::string &) const;

        void unserialize(const std::string &encoded, CompressedPoint &) const;
        void unserialize(const std::string &encoded, UncompressedPoint &) const;

        std::string serialize(const CompressedPoint &) const;
        std::string serialize(const UncompressedPoint &) const;

        std::string serialize(const PubKey &, bool compress=true) const;

};



}

#include "GenericPubKeySerializer.ipp"
