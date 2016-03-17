#pragma once 

#include "../../encoding/HexEncoder.hpp"
#include "GenericPointSerializer.hpp"


namespace Ethereum{


typedef GenericPointSerializer<HexEncoder> Base16PointSerializer;


}
