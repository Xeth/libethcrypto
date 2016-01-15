
#include <boost/test/unit_test.hpp>

#include "Data.hpp"
#include "Base16Encoder.hpp"
#include "Sha256.hpp"

#include <iostream>

using namespace BitCrypto;

BOOST_AUTO_TEST_SUITE(HashTest)


BOOST_AUTO_TEST_CASE(sha256Test)
{
    std::string data = "data";
    Sha256 hasher;
    Data result = hasher.hash(data);
    Base16Encoder encoder;

    BOOST_REQUIRE_EQUAL(encoder.encode(result.begin(), result.end()), "3a6eb0790f39ac87c94f3856b2dd2c5d110e6811602261a9a923d3bb23adc8b7");
 
}



BOOST_AUTO_TEST_SUITE_END()
