
#include <boost/test/unit_test.hpp>

#include "ethkey/Data.hpp"
#include "ethkey/encoding/Base16Encoder.hpp"
#include "ethkey/encoding/Base58Encoder.hpp"

#include <iostream>

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(EncodingTest)


BOOST_AUTO_TEST_CASE(base16Encoding)
{

    std::string hex = "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc";
    Base16Encoder encoder;
    Data data = encoder.decode(hex.begin(), hex.end());

    BOOST_REQUIRE_EQUAL(data.size(), 33);

    BOOST_REQUIRE_EQUAL(encoder.encode(data.begin(), data.end()), "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");
    BOOST_REQUIRE_EQUAL(data[0], 0x03);
    BOOST_REQUIRE_EQUAL(data[1], 0xd9);
    BOOST_REQUIRE_EQUAL(data[2], 0xe8);
    BOOST_REQUIRE_EQUAL(data[3], 0x76);
    BOOST_REQUIRE_EQUAL(data[4], 0x02);
}

void checkEncoding(const std::string& hex, const std::string& encoded)
{
    Base58Encoder base58;
    Base16Encoder base16;

    Data data = base16.decode(hex.begin(), hex.end());
    BOOST_REQUIRE_EQUAL(base58.encode(data.begin(), data.end()), encoded);

    data = base58.decode(encoded.begin(), encoded.end());
    BOOST_REQUIRE_EQUAL(base16.encode(data.begin(), data.end()), hex);

}

BOOST_AUTO_TEST_CASE(base16ToBase58Encoding)
{
    checkEncoding("", "");
    checkEncoding("61", "2g");
    checkEncoding("626262", "a3gV");
    checkEncoding("636363", "aPEr");
    checkEncoding("73696d706c792061206c6f6e6720737472696e67", "2cFupjhnEsSn59qHXstmK2ffpLv2");
    checkEncoding("00eb15231dfceb60925886b67d065299925915aeb172c06647", "1NS17iag9jJgTHD1VXjvLCEnZuQ3rJDE9L");
    checkEncoding("516b6fcd0f", "ABnLTmg");
    checkEncoding("bf4f89001e670274dd", "3SEo3LWLoPntC");
    checkEncoding("572e4794", "3EFU7m");
    checkEncoding("ecac89cad93923c02321", "EJDM8drfXA6uyA");
    checkEncoding("10c8511e", "Rt5zm");
    checkEncoding("00000000000000000000", "1111111111");
}


BOOST_AUTO_TEST_CASE(base58Encoding)
{
    const unsigned char data[] = 
    {
            0x00, 0x5c, 0xc8, 0x7f, 0x4a, 0x3f, 0xdf, 0xe3,
            0xa2, 0x34, 0x6b, 0x69, 0x53, 0x26, 0x7c, 0xa8,
            0x67, 0x28, 0x26, 0x30, 0xd3, 0xf9, 0xb7, 0x8e,
            0x64
    };
    

    Base58Encoder encoder;
    BOOST_REQUIRE_EQUAL(encoder.encode(data, data+25), "19TbMSWwHvnxAKy12iNm3KdbGfzfaMFViT");

    std::string encoded = "19TbMSWwHvnxAKy12iNm3KdbGfzfaMFViT";
    Data data2 = encoder.decode(encoded.begin(), encoded.end());
    
    
    for(int i=0; i<25; i++)
    {
        BOOST_REQUIRE_EQUAL((int)data[i], (int)data2[i]);
    }
    
    std::cout<<std::endl;

}


BOOST_AUTO_TEST_SUITE_END()
