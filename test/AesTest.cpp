#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/AesCipher.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(AesCipherTest)



BOOST_AUTO_TEST_CASE(encrypt)
{
    ScryptKey key("asdasd123");
    std::string plain("hello world !!!");

    AesCipher cipher;
    Data encrypted;

    BOOST_REQUIRE(cipher.encrypt(plain, encrypted, key));

    std::string decrypted;

    BOOST_REQUIRE(cipher.decrypt(encrypted, decrypted, key));

    BOOST_REQUIRE_EQUAL(plain, decrypted);

}




BOOST_AUTO_TEST_SUITE_END()
