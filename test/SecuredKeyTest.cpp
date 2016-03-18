#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/AesCipher.hpp"
#include "ethkey/cipher/Scrypt.hpp"


#include "ethkey/key/Address.hpp"
#include "ethkey/serialization/Literal.hpp"
#include "ethkey/key/PublicKeyFactory.hpp"
#include "ethkey/key/SecuredKey.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(SecuredKeyPairTest)

typedef AesCipher<Scrypt> Cipher;

BOOST_AUTO_TEST_CASE(fromSecret)
{
    Ethereum::PrivateKey secret = Literal<Ethereum::PrivateKey>("6264896b11f6987100129a2667c28e29acca23863ba9dae0c67fa25296f95f24");
    Ethereum::SecuredKey<Cipher> key(secret, Cipher(MakeRandomIV(), MakeRandomScryptParams()), "asdasd123");
    BOOST_REQUIRE_EQUAL(key.getAddress().toString(), "4463fd4dd1993fc5beeb51554fdefa97abede8cc");
    Ethereum::PrivateKey secret2 = key.getPrivateKey().unlock("asdasd123");
    BOOST_REQUIRE(secret2==secret);
    BOOST_REQUIRE_EQUAL(Literal(secret2), "6264896b11f6987100129a2667c28e29acca23863ba9dae0c67fa25296f95f24");
}

BOOST_AUTO_TEST_CASE(keyUnlock)
{
    Ethereum::PrivateKey secret = Literal<Ethereum::PrivateKey>("6264896b11f6987100129a2667c28e29acca23863ba9dae0c67fa25296f95f24");
    Ethereum::SecuredKey<Cipher> key(secret, Cipher(MakeRandomIV(), MakeRandomScryptParams()), "asdasd123");
    BOOST_REQUIRE_EQUAL(key.getAddress().toString(), "4463fd4dd1993fc5beeb51554fdefa97abede8cc");

    Ethereum::SecuredKey<Cipher> key2(key.getPrivateKey().unlock("asdasd123"), Cipher(MakeRandomIV(), MakeRandomScryptParams()), "asdasd123");
    BOOST_REQUIRE_EQUAL(key2.getAddress().toString(), "4463fd4dd1993fc5beeb51554fdefa97abede8cc");

}


BOOST_AUTO_TEST_SUITE_END()
