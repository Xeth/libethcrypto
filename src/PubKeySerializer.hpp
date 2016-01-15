#pragma once

#include "PubKey.hpp"
#include "CompressedPoint.hpp"
#include "UncompressedPoint.hpp"
#include "Secp256k1ContextPtr.hpp"
#include "Base58Encoder.hpp"
#include "Base16Encoder.hpp"
#include "PubKeyFactory.hpp"

namespace BitCrypto{


template<class Encoder>
class PubKeySerializer
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

    private:
        Secp256k1ContextPtr createContext();

    private:
        mutable Secp256k1ContextPtr _context;
};




typedef PubKeySerializer<Base58Encoder> Base58PubKeySerializer;
typedef PubKeySerializer<Base16Encoder> Base16PubKeySerializer;



}

#include "PubKeySerializer.ipp"
