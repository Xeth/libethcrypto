#pragma once 

#include "cryptopp/sha.h"

#include "./detail/CryptoppHasher.hpp"


namespace Ethereum{

typedef CryptoppHasher<CryptoPP::SHA256, 32> Sha256;

}

