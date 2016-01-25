#pragma once 

#include "ethkey/serialization/detail/GenericSignatureSerializer.hpp"
#include "ethkey/encoding/Base58Encoder.hpp"


namespace Ethereum{


typedef GenericSignatureSerializer<Base58Encoder> Base58SignatureSerializer;


}
