#pragma once 

#include "detail/GenericHashSerializer.hpp"
#include "../encoding/Base16Encoder.hpp"

namespace Ethereum{

typedef GenericHashSerializer<Base16Encoder> Base16HashSerializer;

}
