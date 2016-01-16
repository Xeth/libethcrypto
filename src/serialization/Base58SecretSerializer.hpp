#pragma once 

#include "detail/GenericSecretSerializer.hpp"
#include "bitcrypto/encoding/Base58Encoder.hpp"


namespace BitCrypto{


typedef GenericSecretSerializer<Base58Encoder> Base58SecretSerializer;


}
