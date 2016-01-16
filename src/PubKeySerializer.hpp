#pragma once

#include "bitcrypto/PubKey.hpp"
#include "bitcrypto/CompressedPoint.hpp"
#include "bitcrypto/UncompressedPoint.hpp"
#include "bitcrypto/detail/Secp256k1Handler.hpp"
#include "bitcrypto/Base58Encoder.hpp"
#include "bitcrypto/Base16Encoder.hpp"
#include "bitcrypto/PubKeyFactory.hpp"

namespace BitCrypto{


template<class Encoder>
class PubKeySerializer : public Secp256k1Handler
{

    public:

        PubKeySerializer();
        PubKeySerializer(const Secp256k1ContextPtr &);


        void unserialize(const std::string &, CompressedPoint &) const;
        void unserialize(const std::string &, UncompressedPoint &) const;
        PubKey unserialize(const std::string &) const;

        std::string serialize(const CompressedPoint &) const;
        std::string serialize(const UncompressedPoint &) const;
        std::string serialize(const PubKey &, bool compress=true) const;
        void serialize(const PubKey &, CompressedPoint &) const;
        void serialize(const PubKey &, UncompressedPoint &) const;

};




typedef PubKeySerializer<Base58Encoder> Base58PubKeySerializer;
typedef PubKeySerializer<Base16Encoder> Base16PubKeySerializer;



}

#include "PubKeySerializer.ipp"
