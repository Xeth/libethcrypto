#include "KeyGenerator.hpp"


namespace BitCrypto{


KeyGenerator::KeyGenerator() :
    _context(createContext()),
    _pubKeyGenerator(_context)
{}


KeyGenerator::KeyGenerator(const Secp256k1ContextPtr &context):
    _context(context),
    _pubKeyGenerator(context)
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
