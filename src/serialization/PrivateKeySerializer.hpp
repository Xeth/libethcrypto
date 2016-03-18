#pragma once 

#include <json/value.h>
#include <json/writer.h>

#include "../encoding/HexEncoder.hpp"

#include "../key/PrivateKey.hpp"
#include "../key/SecuredPrivateKey.hpp"
#include "../cipher/ScryptParams.hpp"
#include "../cipher/AesCipher.hpp"
#include "../cipher/DummyCipher.hpp"

#include "KdfSerializer.hpp"


namespace Ethereum{


template<class Cipher>
class PrivateKeySerializer
{
    public:

        std::string serialize(const SecuredPrivateKey<Cipher> &) const;
        Json::Value serializeToJson(const SecuredPrivateKey<Cipher> &) const;
        SecuredPrivateKey<Cipher> unserialize(const std::string &) const;
        SecuredPrivateKey<Cipher> unserialize(const Json::Value &) const;

    private:
        Json::Value serializeCipherParams(const Cipher &) const;
        Json::Value serializeKDF(const ScryptParams &) const;
        ScryptParams unserializeKDF(const Json::Value &) const;
};


template<class KDF>
std::string CipherName(const AesCipher<KDF> &);

std::string CipherName(const DummyCipher &);

}


#include "PrivateKeySerializer.ipp"
