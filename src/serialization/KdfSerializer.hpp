#pragma once 

#include <json/value.h>
#include <json/writer.h>
#include <json/reader.h>

#include "../cipher/ScryptParams.hpp"
#include "../encoding/HexEncoder.hpp"

namespace Ethereum{


template<class KdfParams>
class KdfSerializer
{};



template<>
class KdfSerializer<ScryptParams>
{
    public:
        Json::Value serializeToJson(const ScryptParams &) const;
        std::string serialize(const ScryptParams &) const;
        ScryptParams unserialize(const Json::Value &) const;
        ScryptParams unserialize(const std::string &) const;
};


std::string KdfName(const ScryptParams &);



}
