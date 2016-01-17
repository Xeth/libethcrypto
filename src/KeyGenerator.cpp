#include "bitcrypto/KeyGenerator.hpp"


namespace BitCrypto{


KeyGenerator::KeyGenerator() :
    _privateKeyGenerator(getContext()),
    _publicKeyGenerator(getContext())
{}


KeyGenerator::KeyGenerator(const Secp256k1ContextPtr &context):
    Secp256k1Handler(context),
    _privateKeyGenerator(getContext()),
    _publicKeyGenerator(getContext())
{}


KeyPair KeyGenerator::generate()
{
    for(int i=0; i<100; i++)
    {
        try
        {
            PrivateKey privateKey = _privateKeyGenerator.generate();
            return KeyPair(privateKey, _publicKeyGenerator.createFromSecret(privateKey));
        }
        catch(const std::runtime_error &)
        {}
    }
    throw std::runtime_error("failed to generate keypair");
}


KeyPair KeyGenerator::generate(const Data &entropy)
{
    PrivateKey privateKey = _privateKeyGenerator.generate(entropy);
    return KeyPair(privateKey, _publicKeyGenerator.createFromSecret(privateKey));
}


KeyPair KeyGenerator::generate(const unsigned char *entropy, size_t entropySize)
{
    PrivateKey privateKey = _privateKeyGenerator.generate(entropy, entropySize);
    return KeyPair(privateKey, _publicKeyGenerator.createFromSecret(privateKey));
}


}
