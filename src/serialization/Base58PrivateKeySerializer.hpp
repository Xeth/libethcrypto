#pragma once 

#include "detail/GenericPrivateKeySerializer.hpp"
#include "../encoding/Base58Encoder.hpp"


namespace Ethereum{


typedef GenericPrivateKeySerializer<Base58Encoder> Base58PrivateKeySerializer;


}
