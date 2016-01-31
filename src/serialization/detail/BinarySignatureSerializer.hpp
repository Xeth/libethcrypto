#pragma once 

#include "../../detail/Secp256k1Handler.hpp"
#include "../../Data.hpp"
#include "../../Signature.hpp"

namespace Ethereum{



class BinarySignatureSerializer : public Secp256k1Handler
{
    public:
        BinarySignatureSerializer();
        BinarySignatureSerializer(const Secp256k1ContextPtr &);

        bool serialize(const Signature &, Data &result, bool compact=false) const;
        bool unserialize(const Data &, Signature &) const;
        Signature unserialize(const Data &) const;
        Data serialize(const Signature &, bool compact=false) const;
};


}
