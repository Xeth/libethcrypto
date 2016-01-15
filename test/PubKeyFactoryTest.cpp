#include <boost/test/unit_test.hpp>

#include "SecretSerializer.hpp"
#include "PubKeyFactory.hpp"
#include "PubKeySerializer.hpp"


using namespace BitCrypto;

BOOST_AUTO_TEST_SUITE(PubKeyFactoryTest)



BOOST_AUTO_TEST_CASE(fromSecret)
{
    Base16SecretSerializer secretSerializer;
    Secret secret = secretSerializer.unserialize("8010b1bb119ad37d4b65a1022a314897b1b3614b345974332cb1b9582cf03536");
    PubKeyFactory factory;
    PubKey pub = factory.createFromSecret(secret);
    Base16PubKeySerializer pubSerializer;
    BOOST_REQUIRE_EQUAL(pubSerializer.serialize(pub), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");
}

BOOST_AUTO_TEST_CASE(fromCompressedPoint)
{
    Base16PubKeySerializer serializer;
    PubKeyFactory factory;
    CompressedPoint point;
    serializer.unserialize("0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731", point);
    PubKey pub = factory.createFromPoint(point);
    BOOST_REQUIRE_EQUAL(serializer.serialize(pub), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");

}

BOOST_AUTO_TEST_CASE(fromUncompressedPoint)
{
    Base16PubKeySerializer serializer;
    PubKeyFactory factory;
    UncompressedPoint point;
    serializer.unserialize("0409ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc7327318c3a6ec6acd33c36328b8fb4349b31671bcd3a192316ea4f6236ee1ae4a7d8c9", point);
    PubKey pub = factory.createFromPoint(point);
    BOOST_REQUIRE_EQUAL(serializer.serialize(pub), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");
}





BOOST_AUTO_TEST_SUITE_END()
