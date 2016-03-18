#include "KeyGenerator.hpp"


namespace Ethereum{


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
    return generate(&*entropy.begin(), entropy.size());
}


KeyPair KeyGenerator::generate(const unsigned char *entropy, size_t entropySize)
{

    if(entropySize<32)
    {
        throw std::runtime_error("not enough entropy");
    }

    for(int i=0; i<100; i++)
    {
        try
        {
            PrivateKey privateKey = _privateKeyGenerator.generate(entropy, entropySize);
            return KeyPair(privateKey, _publicKeyGenerator.createFromSecret(privateKey));
        }
        catch(const std::runtime_error &)
        {}
        entropy++;
        entropySize--;

        if(entropySize<32)
        {
            break;
        }
    }
    throw std::runtime_error("key generation failed");
}


PublicKeyFactory & KeyGenerator::getPublicKeyFactory()
{
    return _publicKeyGenerator;
}


PrivateKeyGenerator & KeyGenerator::getPrivateKeyGenerator()
{
    return _privateKeyGenerator;
}

}
