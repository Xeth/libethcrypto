#pragma once

#include "../../key/PublicKey.hpp"
#include "../../key/CompressedPoint.hpp"
#include "../../key/UncompressedPoint.hpp"
#include "../../detail/Secp256k1Handler.hpp"
#include "BinaryPublicKeySerializer.hpp"



namespace Ethereum{


template<class Encoder>
class GenericPublicKeySerializer
{

    public:

        GenericPublicKeySerializer();
        GenericPublicKeySerializer(const Secp256k1ContextPtr &);
        GenericPublicKeySerializer(const BinaryPublicKeySerializer &);

        PublicKey unserialize(const std::string &) const;
        PublicKey unserialize(const char *, size_t) const;
        std::string serialize(const PublicKey &, bool compress=true) const;

    private:
        BinaryPublicKeySerializer _binarySerializer;

};



}

#include "GenericPublicKeySerializer.ipp"
