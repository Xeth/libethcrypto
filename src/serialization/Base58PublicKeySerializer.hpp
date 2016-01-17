#pragma once 

#include "detail/GenericPublicKeySerializer.hpp"
#include "bitcrypto/encoding/Base58Encoder.hpp"

namespace BitCrypto{


typedef GenericPublicKeySerializer<Base58Encoder> Base58PublicKeySerializer;


}
