#pragma once 

#include "bitcrypto/serialization/BinarySignatureSerializer.hpp"
#include "bitcrypto/Data.hpp"
#include "bitcrypto/Signature.hpp"

namespace BitCrypto{


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
