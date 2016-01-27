#pragma once 

#include "detail/GenericPublicKeySerializer.hpp"
#include "../encoding/Base16Encoder.hpp"

namespace Ethereum{


typedef GenericPublicKeySerializer<Base16Encoder> Base16PublicKeySerializer;


}
