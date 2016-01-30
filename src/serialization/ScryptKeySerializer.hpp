#pragma once

#include <string>

#include <json/value.h>
#include <json/writer.h>
#include <json/reader.h>

#include "../cipher/ScryptKey.hpp"
#include "../encoding/Base16Encoder.hpp"

namespace Ethereum{


class ScryptKeySerializer
{
    public:

        Json::Value serializeToJson(const ScryptKey &) const;
        std::string serializeToString(const ScryptKey &) const;

        ScryptKey unserialize(const std::string &, const std::string &password) const;
        ScryptKey unserialize(const Json::Value &, const std::string &password) const;

};



}

