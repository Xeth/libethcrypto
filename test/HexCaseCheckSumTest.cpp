
#include <boost/test/unit_test.hpp>

#include "ethkey/checksum/HexCaseCheckSum.hpp"

#include <iostream>

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(HexCaseCheckSumTest)


BOOST_AUTO_TEST_CASE(computeTest)
{
    HexCaseCheckSum checksum;

    BOOST_REQUIRE_EQUAL(checksum.compute("0xa9e4e3b1da2462752aea980698c335e70e9ab26c"), "0xa9e4E3b1DA2462752AeA980698c335E70E9AB26C");
    BOOST_REQUIRE_EQUAL(checksum.compute("0xf8b483dba2c3b7176a3da549ad41a48bb3121069"), "0xf8b483DbA2c3B7176a3Da549ad41A48BB3121069");
}

BOOST_AUTO_TEST_CASE(validateTest)
{

    HexCaseCheckSum checksum;
    BOOST_REQUIRE(checksum.validate("0xa9e4E3b1DA2462752AeA980698c335E70E9AB26C"));
    BOOST_REQUIRE(checksum.validate("0xf8b483DbA2c3B7176a3Da549ad41A48BB3121069"));
    BOOST_REQUIRE(!checksum.validate("0xA9e4E3b1DA2462752AeA980698c335E70E9AB26C"));
    BOOST_REQUIRE(!checksum.validate("0xf8b483dbA2c3B7176a3Da549ad41A48BB3121069"));

}



BOOST_AUTO_TEST_SUITE_END()
