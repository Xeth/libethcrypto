#pragma once 

#include "bitcrypto/serialization/detail/GenericHashSerializer.hpp"
#include "bitcrypto/encoding/Base58Encoder.hpp"

namespace BitCrypto{

typedef GenericHashSerializer<Base58Encoder> Base58HashSerializer;

}
