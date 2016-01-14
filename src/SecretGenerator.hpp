#pragma once 

#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "Secret"
#include "Sha256.hpp"


namespace BitCrypto{


class SecretGenerator
{
    public:

        Secret generate() const; 
        Secret generate(const Data &seed) const;
        Secret generate(const char *seed) const;

};


}
