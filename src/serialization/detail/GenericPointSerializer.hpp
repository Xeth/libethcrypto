#pragma once

#include "../../key/CompressedPoint.hpp"
#include "../../key/UncompressedPoint.hpp"


namespace Ethereum{


template<class Encoder>
class GenericPointSerializer
{
    public:
        void unserialize(const std::string &encoded, CompressedPoint &) const;
        void unserialize(const std::string &encoded, UncompressedPoint &) const;

        std::string serialize(const CompressedPoint &) const;
        std::string serialize(const UncompressedPoint &) const;
};


}

#include "GenericPointSerializer.ipp"
