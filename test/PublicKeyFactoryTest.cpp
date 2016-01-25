#include <boost/test/unit_test.hpp>

#include "ethkey/serialization/Base16PrivateKeySerializer.hpp"
#include "ethkey/serialization/Base16PublicKeySerializer.hpp"

#include "ethkey/PublicKeyFactory.hpp"
#include "ethkey/Literal.hpp"


using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(PublicKeyFactoryTest)



BOOST_AUTO_TEST_CASE(fromPrivateKey)
{
    PrivateKey privateKey = Literal<PrivateKey>("8010b1bb119ad37d4b65a1022a314897b1b3614b345974332cb1b9582cf03536");
    PublicKeyFactory factory;
    PublicKey pub = factory.createFromSecret(privateKey);
    BOOST_REQUIRE_EQUAL(Literal(pub), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");
}

BOOST_AUTO_TEST_CASE(fromCompressedPoint)
{
    Base16PublicKeySerializer serializer;
    PublicKeyFactory factory;
    CompressedPoint point;
    serializer.unserialize("0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731", point);
    PublicKey pub = factory.createFromPoint(point);
    BOOST_REQUIRE_EQUAL(serializer.serialize(pub), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");

}

BOOST_AUTO_TEST_CASE(fromUncompressedPoint)
{
    Base16PublicKeySerializer serializer;
    PublicKeyFactory factory;
    UncompressedPoint point;
    serializer.unserialize("0409ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc7327318c3a6ec6acd33c36328b8fb4349b31671bcd3a192316ea4f6236ee1ae4a7d8c9", point);
    PublicKey pub = factory.createFromPoint(point);
    BOOST_REQUIRE_EQUAL(serializer.serialize(pub), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");
}





BOOST_AUTO_TEST_SUITE_END()
