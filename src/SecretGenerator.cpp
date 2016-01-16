
#include "bitcrypto/SecretGenerator.hpp"
#include <cstring>


namespace BitCrypto{


SecretGenerator::SecretGenerator()
{}

SecretGenerator::SecretGenerator(const Secp256k1ContextPtr &context) :
    _context(context)
{}


Secret SecretGenerator::generate() const
{
    boost::random_device engine;
    boost::random::uniform_int_distribution<unsigned char> generator;
    Secret secret(_context);

    for(int i=0; i<secret.size(); i++)
    {
        secret[i] = generator(engine);
    }

    return secret;
}



Secret SecretGenerator::generate(const Data &entropy) const
{
    Sha256 hasher;
    Secret secret(_context);
    hasher.hash(entropy.begin(), entropy.end(), secret.begin());
    return secret;
}



Secret SecretGenerator::generate(const unsigned char *entropy, size_t entropySize) const
{
    Sha256 hasher;
    Secret secret(_context);
    hasher.hash(entropy, entropy + entropySize, secret.begin());
    return secret;
}



}
