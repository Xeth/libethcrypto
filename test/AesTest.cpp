#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/AesCipher.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(AesCipherTest)



BOOST_AUTO_TEST_CASE(encrypt)
{
    std::string plain("hello world !!!");

    AesCipher cipher(MakeRandomIV(), MakeRandomScryptParams());
    EncryptedData encrypted;

    BOOST_REQUIRE(cipher.encrypt(plain, encrypted, "asdads123"));

    std::string decrypted;

    BOOST_REQUIRE(cipher.decrypt(encrypted, decrypted, "asdads123"));

    BOOST_REQUIRE_EQUAL(plain, decrypted);

}




BOOST_AUTO_TEST_SUITE_END()
