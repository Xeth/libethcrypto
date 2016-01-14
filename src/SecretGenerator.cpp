
#include "SecretGenerator.hpp"
#include <cstring>


namespace BitCrypto{


Secret SecretGenerator::generate() const
{
    boost::random_device engine;
    boost::random::uniform_int_distribution<unsigned char> generator;
    Secret secret;

    for(int i=0; i<secret.size(); i++)
    {
        secret[i] = generator(engine);
    }

    return secret;
}



Secret SecretGenerator::generate(const Data &seed) const
{
    Sha256 hasher;
    Secret secret;
    hasher(seed.begin(), seed.end(), secret.begin());
    return secret;
}



Secret SecretGenerator::generate(const char *seed) const
{
    Sha256 hasher;
    Secret secret;
    hasher(seed, seed + strlen(seed), secret.begin());
    return secret;
}



}
