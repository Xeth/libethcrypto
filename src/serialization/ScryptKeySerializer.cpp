#include "ScryptKeySerializer.hpp"

namespace Ethereum{

Json::Value ScryptKeySerializer::serializeToJson(const ScryptKey &key) const
{
    Json::Value json;
    Json::Value params;

    params["n"] = key.getIterations();
    params["r"] = key.getR();
    params["p"] = key.getP();
    params["dklen"] = key.getDKlen();

    const Data & salt = key.getSalt();

    Base16Encoder hex;
    params["salt"] = hex.encode(key.getSalt());
    json["iv"] = hex.encode(key.getIV());

    json["kdf"] = "scrypt";
    json["kdfparams"] = params;

    return json;
}



ScryptKey ScryptKeySerializer::unserialize(const Json::Value &json, const std::string &password) const
{
    Base16Encoder hex;
    Json::Value params = json["kdfparams"];
    int iterations = params["n"].asInt();
    int r = params["r"].asInt();
    int p = params["p"].asInt();
    int dkLen = params["dklen"].asInt();

    Data salt = hex.decode(params["salt"].asString());
    Data iv = hex.decode(json["iv"].asString());

    return ScryptKey(password, r, p, dkLen, iterations, salt, iv);
}


std::string ScryptKeySerializer::serializeToString(const ScryptKey &key) const
{
    Json::FastWriter writer;
    return writer.write(serializeToJson(key));
}


ScryptKey ScryptKeySerializer::unserialize(const std::string &serialized, const std::string &password) const
{
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(serialized, json, false))
    {
        throw std::runtime_error("invalid json");
    }

    return unserialize(json, password);
}


}
