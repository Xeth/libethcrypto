#pragma once 

#include "bitcrypto/serialization/detail/GenericSignatureSerializer.hpp"
#include "bitcrypto/encoding/Base16Encoder.hpp"

namespace BitCrypto{


typedef GenericSignatureSerializer<Base16Encoder> Base16SignatureSerializer;


}
