#pragma once 

#include "detail/GenericHashSerializer.hpp"
#include "../encoding/Base58Encoder.hpp"

namespace Ethereum{

typedef GenericHashSerializer<Base58Encoder> Base58HashSerializer;

}
