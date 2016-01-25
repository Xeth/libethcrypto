
#include "PrivateKeyGenerator.hpp"
#include <cstring>


namespace Ethereum{


PrivateKeyGenerator::PrivateKeyGenerator()
{}

PrivateKeyGenerator::PrivateKeyGenerator(const Secp256k1ContextPtr &context) :
    _context(context)
{}


PrivateKey PrivateKeyGenerator::generate() const
{
    boost::random_device engine;
    boost::random::uniform_int_distribution<unsigned char> generator;
    PrivateKey PrivateKey(_context);

    for(int i=0; i<PrivateKey.size(); i++)
    {
        PrivateKey[i] = generator(engine);
    }

    return PrivateKey;
}



PrivateKey PrivateKeyGenerator::generate(const Data &entropy) const
{
    Sha256 hasher;
    PrivateKey PrivateKey(_context);
    hasher.hash(entropy.begin(), entropy.end(), PrivateKey.begin());
    return PrivateKey;
}



PrivateKey PrivateKeyGenerator::generate(const unsigned char *entropy, size_t entropySize) const
{
    Sha256 hasher;
    PrivateKey PrivateKey(_context);
    hasher.hash(entropy, entropy + entropySize, PrivateKey.begin());
    return PrivateKey;
}



}
