#include "KeyGenerator.hpp"


namespace BitCrypto{


KeyGenerator::KeyGenerator() :
    _secretGenerator(getContext()),
    _pubKeyGenerator(getContext())
{}


KeyGenerator::KeyGenerator(const Secp256k1ContextPtr &context):
    Secp256k1Handler(context),
    _secretGenerator(getContext()),
    _pubKeyGenerator(getContext())
{}


KeyPair KeyGenerator::generate()
{
    Secret secret = _secretGenerator.generate();
    return KeyPair(secret, _pubKeyGenerator.createFromSecret(secret));
}


KeyPair KeyGenerator::generate(const Data &entropy)
{
    Secret secret = _secretGenerator.generate(entropy);
    return KeyPair(secret, _pubKeyGenerator.createFromSecret(secret));
}


KeyPair KeyGenerator::generate(const char *entropy)
{
    Secret secret = _secretGenerator.generate(entropy);
    return KeyPair(secret, _pubKeyGenerator.createFromSecret(secret));
}


}
