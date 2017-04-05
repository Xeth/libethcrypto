
#include <boost/test/unit_test.hpp>

#include "ethcrypto/encoding/HexEncoder.hpp"
#include "ethcrypto/hash/Sha256.hpp"
#include "ethcrypto/hash/Sha3.hpp"
#include "ethcrypto/hash/Keccak256.hpp"
#include "ethcrypto/serialization/Literal.hpp"

#include <iostream>

using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(HashTest)


BOOST_AUTO_TEST_CASE(sha256Test)
{
    Sha256 hasher;
    HexEncoder encoder;

    BOOST_REQUIRE_EQUAL(encoder.encode(hasher.hash("data")), "3a6eb0790f39ac87c94f3856b2dd2c5d110e6811602261a9a923d3bb23adc8b7");
    BOOST_REQUIRE_EQUAL(encoder.encode(hasher.hash("")), "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
    BOOST_REQUIRE_EQUAL(encoder.encode(hasher.hash(encoder.decode("f0d5e1ba902e341a58320a08078af4311e1291dcffd97f00c06988e0e26a071832"))), "1f23e6ce087e16c4f3585fbe89a4be22961b413076eea1621a81fefaf0c33ecc");
}


BOOST_AUTO_TEST_CASE(sha3Test)
{
    Sha3 hasher;
    HexEncoder encoder;
    BOOST_REQUIRE_EQUAL(encoder.encode(hasher.hash("data")), "efda893aa850b0c0e61f33325615b9d93bcf6b42d60d8f5d37ebc720fd4e3daf");
    BOOST_REQUIRE_EQUAL(encoder.encode(hasher.hash("")), "a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a");
}




BOOST_AUTO_TEST_SUITE_END()
