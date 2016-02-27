#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/AesCipher.hpp"
#include "ethkey/cipher/Scrypt.hpp"
#include "ethkey/serialization/KeySerializer.hpp"
#include "ethkey/KeyGenerator.hpp"
#include "ethkey/Literal.hpp"

#include <iostream>

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

BOOST_AUTO_TEST_CASE(fromSecret)
{
    Ethereum::PrivateKey secret = Literal<Ethereum::PrivateKey>("6264896b11f6987100129a2667c28e29acca23863ba9dae0c67fa25296f95f24");
    ScryptParams params(DecodeHex("75c30010577093a7b14a39eb61f5ac661801f5803980376020da155d5d7e4f15"), 8, 1, 32, 262144);
    Ethereum::SecuredKey<Cipher> key(secret, Cipher(DecodeHex("260ee6aa324d301af36a7b6b4986a0e1"), params), "asdasd123");
    KeySerializer<Cipher> serializer;
    std::string serialized = serializer.serialize(key);
    Ethereum::SecuredKey<Cipher> key2 = serializer.unserialize(serialized);
    BOOST_REQUIRE(key.getPrivateKey().unlock("asdasd123")==key2.getPrivateKey().unlock("asdasd123"));
    BOOST_REQUIRE_EQUAL(key.getAddress().toString(), key2.getAddress().toString());
}



BOOST_AUTO_TEST_CASE(fromString)
{
    KeySerializer<Cipher> serializer;
    std::string serialized = "{\"address\":\"4463fd4dd1993fc5beeb51554fdefa97abede8cc\",\"Crypto\":{\"cipher\":\"aes-128-ctr\",\"ciphertext\":\"6c7055dcc7d7634db6c65ce1e4754313d812860144de698f1b8a335bd7511529\",\"cipherparams\":{\"iv\":\"260ee6aa324d301af36a7b6b4986a0e1\"},\"kdf\":\"scrypt\",\"kdfparams\":{\"dklen\":32,\"n\":262144,\"p\":1,\"r\":8,\"salt\":\"75c30010577093a7b14a39eb61f5ac661801f5803980376020da155d5d7e4f15\"},\"mac\":\"b5caf622f11b7d25aee49f9b560c6a38b1925ce00ebf06312c657eb0491cfcfd\"},\"id\":\"f65f7b94-f762-40e8-ad52-a8329becb277\",\"version\":3}";
    
    SecuredKey<Cipher> key = serializer.unserialize(serialized);

    BOOST_REQUIRE_EQUAL(key.getAddress().toString(), "4463fd4dd1993fc5beeb51554fdefa97abede8cc");

    PrivateKey secret = key.getPrivateKey().unlock("asdasd123");
    SecuredKey<Cipher> key2(secret, Cipher(MakeRandomIV(), MakeRandomScryptParams()), "asdasd123");
    BOOST_REQUIRE(key.getPrivateKey().unlock("asdasd123")==key2.getPrivateKey().unlock("asdasd123"));
    BOOST_REQUIRE_EQUAL(key2.getAddress().toString(), key.getAddress().toString());
}




BOOST_AUTO_TEST_SUITE_END()
