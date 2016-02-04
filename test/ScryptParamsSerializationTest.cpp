#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/AesCipher.hpp"
#include "ethkey/cipher/Scrypt.hpp"
#include "ethkey/serialization/KdfSerializer.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(KdfSerializerTest)



BOOST_AUTO_TEST_CASE(serialization)
{
    std::string plain("hello world !!!");

    AesCipher<Scrypt> cipher(MakeRandomIV(), MakeRandomScryptParams());
    EncryptedData encrypted;

    BOOST_REQUIRE(cipher.encrypt(plain, encrypted, "asdads123"));

    KdfSerializer<ScryptParams> serializer;
    std::string serializedKDF = serializer.serialize(cipher.getParams());

    AesCipher<Scrypt> cipher2(cipher.getIV(), serializer.unserialize(serializedKDF));


    std::string decrypted;

    BOOST_REQUIRE(cipher2.decrypt(encrypted, decrypted, "asdads123"));

    BOOST_REQUIRE_EQUAL(plain, decrypted);

}




BOOST_AUTO_TEST_SUITE_END()
