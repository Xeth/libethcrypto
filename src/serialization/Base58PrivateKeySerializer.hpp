#pragma once 

#include "detail/GenericPrivateKeySerializer.hpp"
#include "ethkey/encoding/Base58Encoder.hpp"


namespace Ethereum{


typedef GenericPrivateKeySerializer<Base58Encoder> Base58PrivateKeySerializer;


}
