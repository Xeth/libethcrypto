#pragma once 


#include <boost/shared_ptr.hpp>
#include "bitcrypto/secp256k1/secp256k1.h"


namespace BitCrypto{


typedef boost::shared_ptr<secp256k1_context> Secp256k1ContextPtr;


}
