#pragma once

#include "PubKey.hpp"
#include "CompressedPoint.hpp"
#include "Secp256k1ContextPtr.hpp"
#include "Base58Encoder.hpp"
#include "Base16Encoder.hpp"
#include "PubKeyArchiver.hpp"

namespace BitCrypto{

typedef PubKeyArchiver Archiver;

template<class Encoder>
class PubKeySerializer
{

    public:

        PubKeySerializer();
        PubKeySerializer(const Secp256k1ContextPtr &);


        CompressedPoint unserializeCompressed(const std::string &) const;
        PubKey unserialize(const std::string &) const;

        std::string serialize(const CompressedPoint &) const;
        std::string serialize(const PubKey &) const;

    private:
        Secp256k1ContextPtr _context;
};




typedef PubKeySerializer<Base58Encoder> Base58PubKeySerializer;
typedef PubKeySerializer<Base16Encoder> Base16PubKeySerializer;



}

#include "PubKeySerializer.ipp"
