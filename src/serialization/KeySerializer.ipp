namespace Ethereum{

template<class Cipher>
Json::Value KeySerializer<Cipher>::serializeToJson(const SecuredKey<Cipher> &key) const
{
    boost::uuids::uuid uuid = boost::uuids::random_generator()();

    Json::Value result;
    result["Crypto"] = _secretSerializer.serializeToJson(key.getPrivateKey());
    result["address"] = key.getAddress().toString();
    result["id"] = boost::lexical_cast<std::string>(uuid);
    result["version"] = 3; //compatible with geth
    return result;
}


template<class Cipher>
std::string KeySerializer<Cipher>::serialize(const SecuredKey<Cipher> &key) const
{
    Json::FastWriter writer;
    return writer.write(serializeToJson(key));
}


template<class Cipher>
SecuredKey<Cipher> KeySerializer<Cipher>::unserialize(const Json::Value &json) const
{
    SecuredPrivateKey<Cipher> secret = _secretSerializer.unserialize(json.isMember("Crypto") ? json["Crypto"] : json["crypto"]);
    Address address(json["address"].asString());
    return SecuredKey<Cipher>(secret, address);
}


template<class Cipher>
SecuredKey<Cipher> KeySerializer<Cipher>::unserialize(const std::string &serialized) const
{
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(serialized, json))
    {
        throw std::runtime_error("invalid json");
    }
    return unserialize(json);
}


}
