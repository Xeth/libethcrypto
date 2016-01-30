#include <boost/test/unit_test.hpp>

#include <iostream>

#include "ethkey/cipher/AesCipher.hpp"
#include "ethkey/serialization/ScryptKeySerializer.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(ScryptKeySerializationTest)



BOOST_AUTO_TEST_CASE(serialize)
{
    ScryptKey key("asdasd123");
    std::string plain("hello world !!!");

    AesCipher cipher;
    Data encrypted;

    BOOST_REQUIRE(cipher.encrypt(plain, encrypted, key));

    ScryptKeySerializer serializer;
    std::string serializedKey = serializer.serializeToString(key);
    ScryptKey key2 = serializer.unserialize(serializedKey, "asdasd123");


    std::string decrypted;
    BOOST_REQUIRE(cipher.decrypt(encrypted, decrypted, key2));

    BOOST_REQUIRE_EQUAL(plain, decrypted);

}




BOOST_AUTO_TEST_SUITE_END()
