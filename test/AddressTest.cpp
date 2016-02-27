#include <boost/test/unit_test.hpp>

#include "ethkey/Address.hpp"
#include "ethkey/Literal.hpp"
#include "ethkey/PublicKeyFactory.hpp"

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(AddressTest)



BOOST_AUTO_TEST_CASE(fromPublicKey)
{
    PublicKeyFactory factory;
    PrivateKey secret = Literal<PrivateKey>("187900ed539bce26777e806b63a732aac8829ccceea9ac0288ac3457cb1accd8");
    PublicKey pubKey = factory.createFromSecret(secret);
    Address address(pubKey);
    BOOST_REQUIRE_EQUAL(address.toString(), "0f3947a26863e72193756090cf5190e9ac42ce70");
}

BOOST_AUTO_TEST_CASE(fromPublicKey2)
{
    PublicKeyFactory factory;
    PrivateKey secret = Literal<PrivateKey>("6264896b11f6987100129a2667c28e29acca23863ba9dae0c67fa25296f95f24");
    PublicKey pubKey = factory.createFromSecret(secret);
    Address address(pubKey);
    BOOST_REQUIRE_EQUAL(address.toString(), "4463fd4dd1993fc5beeb51554fdefa97abede8cc");
}



BOOST_AUTO_TEST_SUITE_END()
