#pragma once 

#include "GenericPublicKeySerializer.hpp"
#include "../../encoding/Base16Encoder.hpp"

namespace Ethereum{


typedef GenericPublicKeySerializer<Base16Encoder> Base16PublicKeySerializer;


}
