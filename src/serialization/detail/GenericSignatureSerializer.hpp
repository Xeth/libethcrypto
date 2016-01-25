#pragma once 

#include "ethkey/serialization/BinarySignatureSerializer.hpp"
#include "ethkey/Data.hpp"
#include "ethkey/Signature.hpp"

namespace Ethereum{


template<class Encoder>
class GenericSignatureSerializer
{
    public:

        std::string serialize(const Signature &, bool compact = false) const;
        Signature unserialize(const std::string &) const;


    private:
        BinarySignatureSerializer _serializer;

};


}

#include "GenericSignatureSerializer.ipp"
