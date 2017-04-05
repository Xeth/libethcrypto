#pragma once 

#include <string>

#include "cryptopp/keccak.h"
#include "./detail/CryptoppHasher.hpp"


namespace Ethereum{


typedef CryptoppHasher<CryptoPP::Keccak_256, 32> Keccak256;




}

