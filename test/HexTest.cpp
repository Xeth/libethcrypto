
#include <boost/test/unit_test.hpp>

#include "ethkey/encoding/HexEncoder.hpp"
#include "ethkey/encoding/Base58Encoder.hpp"

#include <iostream>

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(HexText)


BOOST_AUTO_TEST_CASE(fromString)
{

    std::string hex = "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc";
    HexEncoder encoder;
    Data data = encoder.decode(hex);

    BOOST_REQUIRE_EQUAL(data.size(), 33);

    BOOST_REQUIRE_EQUAL(data[0], 0x03);
    BOOST_REQUIRE_EQUAL(data[1], 0xd9);
    BOOST_REQUIRE_EQUAL(data[2], 0xe8);
    BOOST_REQUIRE_EQUAL(data[3], 0x76);
    BOOST_REQUIRE_EQUAL(data[4], 0x02);

    BOOST_REQUIRE_EQUAL(encoder.encode(data.begin(), data.end()), "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");

}

BOOST_AUTO_TEST_CASE(fromIncompleteString)
{

    std::string hex = "3d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc";
    HexEncoder encoder;
    Data data = encoder.decode(hex);

    BOOST_REQUIRE_EQUAL(data.size(), 33);

    BOOST_REQUIRE_EQUAL(data[0], 0x03);
    BOOST_REQUIRE_EQUAL(data[1], 0xd9);
    BOOST_REQUIRE_EQUAL(data[2], 0xe8);
    BOOST_REQUIRE_EQUAL(data[3], 0x76);
    BOOST_REQUIRE_EQUAL(data[4], 0x02);

    BOOST_REQUIRE_EQUAL(encoder.encode(data.begin(), data.end()), "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");

}

BOOST_AUTO_TEST_CASE(usingPrefix)
{

    std::string hex = "0x3d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc";
    HexEncoder encoder;
    Data data = encoder.decode(hex);

    BOOST_REQUIRE_EQUAL(data.size(), 33);

    BOOST_REQUIRE_EQUAL(data[0], 0x03);
    BOOST_REQUIRE_EQUAL(data[1], 0xd9);
    BOOST_REQUIRE_EQUAL(data[2], 0xe8);
    BOOST_REQUIRE_EQUAL(data[3], 0x76);
    BOOST_REQUIRE_EQUAL(data[4], 0x02);

    BOOST_REQUIRE_EQUAL(encoder.encode(data.begin(), data.end()), "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");

}

BOOST_AUTO_TEST_CASE(fromUpperCase)
{

    std::string hex = "03D9E876028F4FC062C19F7097762E4AFFC2CE4EDFFFA7D42E3C17CD157EC6D1BC";
    HexEncoder encoder;
    Data data = encoder.decode(hex);

    BOOST_REQUIRE_EQUAL(data.size(), 33);

    BOOST_REQUIRE_EQUAL(data[0], 0x03);
    BOOST_REQUIRE_EQUAL(data[1], 0xd9);
    BOOST_REQUIRE_EQUAL(data[2], 0xe8);
    BOOST_REQUIRE_EQUAL(data[3], 0x76);
    BOOST_REQUIRE_EQUAL(data[4], 0x02);

    BOOST_REQUIRE_EQUAL(encoder.encode(data.begin(), data.end()), "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");

}

BOOST_AUTO_TEST_CASE(fromInvalidHex)
{

    std::string hex = "03D9E876028F4FC062KC19F7097762E4AffC2CE4EdFFFA7D42E3C17CD157EC6D1BC";
    HexEncoder encoder;
    Data data;
    BOOST_REQUIRE(!encoder.decode(hex.begin(), hex.end(), data));
}




BOOST_AUTO_TEST_SUITE_END()
