#pragma once 

#include "detail/GenericSignatureSerializer.hpp"
#include "../encoding/Base58Encoder.hpp"


namespace Ethereum{


typedef GenericSignatureSerializer<Base58Encoder> Base58SignatureSerializer;


}
