#pragma once 


#include "detail/BinarySignatureSerializer.hpp"
#include "detail/Base16SignatureSerializer.hpp"


namespace Ethereum{


class SignatureSerializer
{

    public:

        SignatureSerializer();
        SignatureSerializer(const Secp256k1ContextPtr &);

        std::string serialize(const Signature &, bool compact=false) const;
        Signature unserialize(const std::string &) const;
        Signature unserialize(const Data &) const;

        Data toBytes(const Signature &, bool compact = false) const;
        Signature fromBytes(const Data &) const;


    private:
        BinarySignatureSerializer _binSerializer;
        Base16SignatureSerializer _hexSerializer;

};


}
