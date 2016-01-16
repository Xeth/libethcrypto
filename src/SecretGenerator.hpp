#pragma once 

#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "bitcrypto/detail/Secp256k1ContextPtr.hpp"
#include "bitcrypto/Secret.hpp"
#include "bitcrypto/Sha256.hpp"


namespace BitCrypto{


class SecretGenerator
{
    public:

        SecretGenerator();
        SecretGenerator(const Secp256k1ContextPtr &);

        Secret generate() const; 
        Secret generate(const Data &seed) const;
        Secret generate(const char *seed) const;

    private:
        Secp256k1ContextPtr _context;
};


}
