#pragma once 

#include "detail/GenericPublicKeySerializer.hpp"
#include "ethkey/encoding/Base16Encoder.hpp"

namespace Ethereum{


typedef GenericPublicKeySerializer<Base16Encoder> Base16PublicKeySerializer;


}
