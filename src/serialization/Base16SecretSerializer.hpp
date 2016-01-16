#pragma once 

#include "detail/GenericSecretSerializer.hpp"
#include "bitcrypto/encoding/Base16Encoder.hpp"


namespace BitCrypto{


typedef GenericSecretSerializer<Base16Encoder> Base16SecretSerializer;


}
