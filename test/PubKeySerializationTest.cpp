#include <boost/test/unit_test.hpp>

#include "PubKeySerializer.hpp"


using namespace BitCrypto;

BOOST_AUTO_TEST_SUITE(PubKeySerializerTest)



BOOST_AUTO_TEST_CASE(serializationTest)
{
    Base16Encoder encoder;
    Base16PubKeySerializer serializer;
    PubKey key = serializer.unserialize("0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");

    BOOST_REQUIRE_EQUAL(serializer.serialize(key), "0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc732731");

}


BOOST_AUTO_TEST_CASE(deserializationError)
{
    Base16PubKeySerializer serializer;
    BOOST_CHECK_THROW(serializer.unserialize("0309ba8621aefd3b6ba4ca6d11a4746e8df8d35d9b51b383338f627ba7fc73"), std::runtime_error);
}





BOOST_AUTO_TEST_SUITE_END()
