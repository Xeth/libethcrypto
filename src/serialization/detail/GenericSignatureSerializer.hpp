#pragma once 

#include "BinarySignatureSerializer.hpp"
#include "../../detail/Data.hpp"
#include "../../signature/Signature.hpp"

namespace Ethereum{


template<class Encoder>
class GenericSignatureSerializer
{
    public:

        GenericSignatureSerializer();
        GenericSignatureSerializer(const BinarySignatureSerializer &);

        std::string serialize(const Signature &, bool compact = false) const;
        Signature unserialize(const std::string &) const;


    private:
        BinarySignatureSerializer _serializer;

};


}

#include "GenericSignatureSerializer.ipp"
