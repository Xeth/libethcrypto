#include "bitcrypto/KeyGenerator.hpp"


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
    for(int i=0; i<100; i++)
    {
        try
        {
            Secret secret = _secretGenerator.generate();
            return KeyPair(secret, _pubKeyGenerator.createFromSecret(secret));
        }
        catch(const std::runtime_error &)
        {}
    }
    throw std::runtime_error("failed to generate keypair");
}


KeyPair KeyGenerator::generate(const Data &entropy)
{
    Secret secret = _secretGenerator.generate(entropy);
    return KeyPair(secret, _pubKeyGenerator.createFromSecret(secret));
}


KeyPair KeyGenerator::generate(const unsigned char *entropy, size_t entropySize)
{
    Secret secret = _secretGenerator.generate(entropy, entropySize);
    return KeyPair(secret, _pubKeyGenerator.createFromSecret(secret));
}


}
