#include <boost/test/unit_test.hpp>

#include "ethkey/DoubleSha256CheckSum.hpp"


using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(CheckSumTest)



BOOST_AUTO_TEST_CASE(doubleSha256CheckSum)
{
    unsigned char data[] = { 0, 0, 0, 0, 0 };
    DoubleSha256CheckSum checksum;
    uint32_t result = checksum(data, data+5);
    BOOST_REQUIRE_EQUAL(result, 0x93af0179u);
}




BOOST_AUTO_TEST_SUITE_END()
