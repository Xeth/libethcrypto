#pragma once 

#include "bitcrypto/detail/GenericSecretSerializer.hpp"
#include "bitcrypto/Base58Encoder.hpp"


namespace BitCrypto{


typedef GenericSecretSerializer<Base58Encoder> Base58SecretSerializer;


}
