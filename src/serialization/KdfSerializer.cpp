#include "KdfSerializer.hpp"


namespace Ethereum{


Json::Value KdfSerializer<ScryptParams>::serializeToJson(const ScryptParams &params) const
{
    Json::Value result;
    result["n"] = params.getIterations();
    result["r"] = params.getR();
    result["p"] = params.getP();
    result["dklen"] = params.getDKlen();
    result["salt"] = EncodeHex(params.getSalt());
    return result;
}


std::string KdfSerializer<ScryptParams>::serialize(const ScryptParams &params) const
{
    Json::Value json = serializeToJson(params);
    Json::FastWriter writer;
    return writer.write(json);
}


ScryptParams KdfSerializer<ScryptParams>::unserialize(const Json::Value &params) const
{
    int iterations = params["n"].asInt();
    int r = params["r"].asInt();
    int p = params["p"].asInt();
    int dkLen = params["dklen"].asInt();
    Data salt = DecodeHex(params["salt"].asString());
    return ScryptParams(salt, r, p, dkLen, iterations);
}


ScryptParams KdfSerializer<ScryptParams>::unserialize(const std::string &params) const
{
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(params, json))
    {
        throw std::runtime_error("invalid json");
    }
    return unserialize(json);
}

std::string KdfName(const ScryptParams &)
{
    return "scrypt";
}

}
