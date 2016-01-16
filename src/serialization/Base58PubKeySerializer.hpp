#pragma once 

#include "detail/GenericPubKeySerializer.hpp"
#include "bitcrypto/encoding/Base58Encoder.hpp"

namespace BitCrypto{


typedef GenericPubKeySerializer<Base58Encoder> Base58PubKeySerializer;


}
