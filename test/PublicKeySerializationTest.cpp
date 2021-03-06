#include <boost/test/unit_test.hpp>

#include "ethcrypto/serialization/PublicKeySerializer.hpp"
#include <iostream>

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(PublicKeySerializerTest)



BOOST_AUTO_TEST_CASE(fromCompressedPoint)
{
    PublicKeySerializer serializer;
    PublicKey key = serializer.unserialize("0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");

    BOOST_REQUIRE_EQUAL(serializer.serialize(key), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");

    BOOST_REQUIRE_EQUAL(serializer.serialize(key, false), "0409ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc7327318c3a6ec6acd33c36328b8fb4349b31671bcd3a192316ea4f6236ee1ae4a7d8c9");

}

BOOST_AUTO_TEST_CASE(fromBuffer)
{
    PublicKeySerializer serializer;
    PublicKey key = serializer.unserialize("0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731", 66);
    BOOST_REQUIRE_EQUAL(serializer.serialize(key), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");
}

BOOST_AUTO_TEST_CASE(fromUncompressedPoint)
{
    PublicKeySerializer serializer;
    PublicKey key = serializer.unserialize("0409ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc7327318c3a6ec6acd33c36328b8fb4349b31671bcd3a192316ea4f6236ee1ae4a7d8c9");

    BOOST_REQUIRE_EQUAL(serializer.serialize(key), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");

    BOOST_REQUIRE_EQUAL(serializer.serialize(key, false), "0409ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc7327318c3a6ec6acd33c36328b8fb4349b31671bcd3a192316ea4f6236ee1ae4a7d8c9");
}


BOOST_AUTO_TEST_CASE(invalidCompressedPoint)
{
    PublicKeySerializer serializer;
    BOOST_CHECK_THROW(serializer.unserialize("0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc73"), std::runtime_error);
}


BOOST_AUTO_TEST_CASE(invalidUncompressedPoint)
{
    PublicKeySerializer serializer;
    BOOST_CHECK_THROW(serializer.unserialize("0409ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc7327318c3a6ec6acd33c36328b8fb4349b31671bcd3a192316ea4f6236ee1ae4a7"), std::runtime_error);
}




BOOST_AUTO_TEST_SUITE_END()
