#pragma once 

#include "detail/GenericPublicKeySerializer.hpp"
#include "bitcrypto/encoding/Base16Encoder.hpp"

namespace BitCrypto{


typedef GenericPublicKeySerializer<Base16Encoder> Base16PublicKeySerializer;


}
