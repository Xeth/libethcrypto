#pragma once 

#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "bitcrypto/detail/Secp256k1ContextPtr.hpp"
#include "bitcrypto/PrivateKey.hpp"
#include "bitcrypto/Sha256.hpp"


namespace BitCrypto{


class PrivateKeyGenerator
{
    public:

        PrivateKeyGenerator();
        PrivateKeyGenerator(const Secp256k1ContextPtr &);

        PrivateKey generate() const; 
        PrivateKey generate(const Data &entropy) const;
        PrivateKey generate(const unsigned char *entropy, size_t entropySize) const;

    private:
        Secp256k1ContextPtr _context;
};


}
