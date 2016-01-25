#pragma once 

#include "ethkey/serialization/detail/GenericSignatureSerializer.hpp"
#include "ethkey/encoding/Base16Encoder.hpp"

namespace Ethereum{


typedef GenericSignatureSerializer<Base16Encoder> Base16SignatureSerializer;


}
