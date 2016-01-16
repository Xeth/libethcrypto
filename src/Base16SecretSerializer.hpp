#pragma once 

#include "bitcrypto/detail/GenericSecretSerializer.hpp"
#include "bitcrypto/Base16Encoder.hpp"


namespace BitCrypto{


typedef GenericSecretSerializer<Base16Encoder> Base16SecretSerializer;


}
