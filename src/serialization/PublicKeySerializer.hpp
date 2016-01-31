#pragma once 

#include "detail/BinaryPublicKeySerializer.hpp"
#include "detail/Base16PublicKeySerializer.hpp"
#include "detail/Base16PointSerializer.hpp"


namespace Ethereum{


class PublicKeySerializer
{
    public:
        PublicKeySerializer();
        PublicKeySerializer(const Secp256k1ContextPtr &);

        std::string serialize(const PublicKey &, bool compress = true) const;
        std::string serialize(const CompressedPoint &) const;
        std::string serialize(const UncompressedPoint &) const;

        PublicKey unserialize(const std::string &) const;
        PublicKey unserialize(const CompressedPoint &) const;
        PublicKey unserialize(const UncompressedPoint &) const;


        std::string toHex(const PublicKey &, bool compress = true) const;
        std::string toHex(const CompressedPoint &) const;
        std::string toHex(const UncompressedPoint &) const;

        CompressedPoint toCompressedPoint(const PublicKey &) const;
        UncompressedPoint toUncompressedPoint(const PublicKey &) const;

        CompressedPoint toCompressedPoint(const std::string &) const;
        UncompressedPoint toUncompressedPoint(const std::string &) const;

        PublicKey fromHex(const std::string &) const;
        PublicKey fromPoint(const CompressedPoint &) const;
        PublicKey fromPoint(const UncompressedPoint &) const;


    private:
        BinaryPublicKeySerializer _binarySerializer;
        Base16PublicKeySerializer _hexSerializer;
        Base16PointSerializer _hexPointSerializer;

};


}
