#pragma once 

#include "bitcrypto/serialization/detail/GenericSignatureSerializer.hpp"
#include "bitcrypto/encoding/Base58Encoder.hpp"


namespace BitCrypto{


typedef GenericSignatureSerializer<Base58Encoder> Base58SignatureSerializer;


}
