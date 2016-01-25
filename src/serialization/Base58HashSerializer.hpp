#pragma once 

#include "ethkey/serialization/detail/GenericHashSerializer.hpp"
#include "ethkey/encoding/Base58Encoder.hpp"

namespace Ethereum{

typedef GenericHashSerializer<Base58Encoder> Base58HashSerializer;

}
