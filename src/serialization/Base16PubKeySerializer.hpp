#pragma once 

#include "detail/GenericPubKeySerializer.hpp"
#include "bitcrypto/encoding/Base16Encoder.hpp"

namespace BitCrypto{


typedef GenericPubKeySerializer<Base16Encoder> Base16PubKeySerializer;


}
