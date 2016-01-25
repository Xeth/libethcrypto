#pragma once 

#include "ethkey/serialization/detail/GenericHashSerializer.hpp"
#include "ethkey/encoding/Base16Encoder.hpp"

namespace Ethereum{

typedef GenericHashSerializer<Base16Encoder> Base16HashSerializer;

}
