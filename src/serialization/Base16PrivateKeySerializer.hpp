#pragma once 

#include "detail/GenericPrivateKeySerializer.hpp"
#include "bitcrypto/encoding/Base16Encoder.hpp"


namespace BitCrypto{


typedef GenericPrivateKeySerializer<Base16Encoder> Base16PrivateKeySerializer;


}
