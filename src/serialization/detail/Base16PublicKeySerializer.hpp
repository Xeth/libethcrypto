#pragma once 

#include "GenericPublicKeySerializer.hpp"
#include "../../encoding/HexEncoder.hpp"

namespace Ethereum{


typedef GenericPublicKeySerializer<HexEncoder> Base16PublicKeySerializer;


}
