#pragma once 

#include "detail/GenericHashSerializer.hpp"
#include "../encoding/HexEncoder.hpp"

namespace Ethereum{

typedef GenericHashSerializer<HexEncoder> HashSerializer;

}
