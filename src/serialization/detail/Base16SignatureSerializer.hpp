#pragma once 

#include "GenericSignatureSerializer.hpp"
#include "../../encoding/HexEncoder.hpp"

namespace Ethereum{


typedef GenericSignatureSerializer<HexEncoder> Base16SignatureSerializer;


}
