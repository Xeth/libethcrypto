#pragma once 

#include "detail/GenericPrivateKeySerializer.hpp"
#include "bitcrypto/encoding/Base58Encoder.hpp"


namespace BitCrypto{


typedef GenericPrivateKeySerializer<Base58Encoder> Base58PrivateKeySerializer;


}
