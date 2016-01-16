#pragma once 

#include "bitcrypto/detail/GenericPubKeySerializer.hpp"


namespace BitCrypto{


typedef GenericPubKeySerializer<Base58Encoder> Base58PubKeySerializer;


}
