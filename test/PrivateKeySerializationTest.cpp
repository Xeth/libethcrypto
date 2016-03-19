#include <boost/test/unit_test.hpp>

#include "ethcrypto/cipher/AesCipher.hpp"
#include "ethcrypto/cipher/Scrypt.hpp"
#include "ethcrypto/serialization/PrivateKeySerializer.hpp"
#include "ethcrypto/key/KeyGenerator.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(PrivateKeySerializerTest)

typedef AesCipher<Scrypt> Cipher;

BOOST_AUTO_TEST_CASE(serialization)
{
    KeyGenerator generator;
    PrivateKeySerializer<Cipher> serializer;

    SecuredKeyPair<Cipher> key = generator.generate(Cipher(MakeRandomIV(), MakeRandomScryptParams()), "asdasd123");

    std::string serialized = serializer.serialize(key.getPrivateKey());

    SecuredPrivateKey<Cipher> key2 = serializer.unserialize(serialized);

    BOOST_REQUIRE(key.getPrivateKey().unlock("asdasd123") == key2.unlock("asdasd123"));
    BOOST_REQUIRE(key.getPrivateKey().getData().data == key2.getData().data);
    BOOST_REQUIRE(key.getPrivateKey().getData().mac == key2.getData().mac);
}




BOOST_AUTO_TEST_SUITE_END()
