#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/AesCipher.hpp"
#include "ethkey/cipher/Scrypt.hpp"
#include "ethkey/serialization/KeySerializer.hpp"
#include "ethkey/KeyGenerator.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(KeySerializerTest)

typedef AesCipher<Scrypt> Cipher;

BOOST_AUTO_TEST_CASE(serialization)
{
    KeyGenerator generator;
    KeySerializer<Cipher> serializer;

    SecuredKeyPair<Cipher> key = generator.generate(Cipher(MakeRandomIV(), MakeRandomScryptParams()), "asdasd123");

    std::string serialized = serializer.serialize(key);

    SecuredKey<Cipher> key2 = serializer.unserialize(serialized);

    BOOST_REQUIRE(key.getPrivateKey().unlock("asdasd123") == key2.getPrivateKey().unlock("asdasd123"));
    BOOST_REQUIRE(key.getPrivateKey().getData().data == key2.getPrivateKey().getData().data);
    BOOST_REQUIRE(key.getPrivateKey().getData().mac == key2.getPrivateKey().getData().mac);
    BOOST_REQUIRE(Address(key.getPublicKey()) == key2.getAddress());
}




BOOST_AUTO_TEST_SUITE_END()
