#pragma once 

#include "bitcrypto/serialization/detail/GenericHashSerializer.hpp"
#include "bitcrypto/encoding/Base16Encoder.hpp"

namespace BitCrypto{

typedef GenericHashSerializer<Base16Encoder> Base16HashSerializer;

}
