#include <boost/test/unit_test.hpp>

#include "ethkey/PublicKeyFactory.hpp"
#include "ethkey/Signer.hpp"
#include "ethkey/SignatureValidator.hpp"
#include "ethkey/hash/Sha256.hpp"
#include "ethkey/Literal.hpp"
#include <iostream>

using namespace Ethereum;


BOOST_AUTO_TEST_SUITE(SignatureTest)



BOOST_AUTO_TEST_CASE(sign)
{
    PublicKeyFactory pubKeyFactory;
    Sha256 hasher;
    Signer signer;
    SignatureValidator validator;

    PrivateKey secret = Literal<PrivateKey>("8010b1bb119ad37d4b65a1022a314897b1b3614b345974332cb1b9582cf03536");

    PublicKey pub = pubKeyFactory.createFromSecret(secret);

    const char * text = "test here";
    Data hash = hasher.hash(text, text+strlen(text));
 
    Signature signature = signer.sign(secret, hash);

    BOOST_REQUIRE(validator.verify(pub, signature, hash));
}


BOOST_AUTO_TEST_CASE(validSignature)
{
    SignatureValidator validator;
    HexEncoder encoder;
    PublicKey key = Literal<PublicKey>("03bc88a1bd6ebac38e9a9ed58eda735352ad10650e235499b7318315cc26c9b55b");
    
    Data hash = encoder.decode("ed8f9b40c2d349c8a7e58cebe79faa25c21b6bb85b874901f72a1b3f1ad0a67f");
    std::reverse(hash.begin(), hash.end());

    Signature signature = Literal<Signature>("3045022100bc494fbd09a8e77d8266e2abdea9aef08b9e71b451c7d8de9f63cda33a62437802206b93edd6af7c659db42c579eb34a3a4cb60c28b5a6bc86fd5266d42f6b8bb67d");

    BOOST_REQUIRE(validator.verify(key, signature, hash));
}


BOOST_AUTO_TEST_CASE(invalidSignature)
{
}






BOOST_AUTO_TEST_SUITE_END()
