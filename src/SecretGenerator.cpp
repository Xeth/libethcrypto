
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



Secret SecretGenerator::generate(const Data &seed) const
{
    Sha256 hasher;
    Secret secret(_context);
    hasher.hash(seed.begin(), seed.end(), secret.begin());
    return secret;
}



Secret SecretGenerator::generate(const char *seed) const
{
    Sha256 hasher;
    Secret secret(_context);
    const unsigned char *ptr = (const unsigned char *)seed;
    hasher.hash(ptr, ptr + strlen(seed), secret.begin());
    return secret;
}



}
