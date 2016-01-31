#pragma once 

#include "../../encoding/Base16Encoder.hpp"
#include "GenericPointSerializer.hpp"


namespace Ethereum{


typedef GenericPointSerializer<Base16Encoder> Base16PointSerializer;


}
