#include "Base58Encoder.hpp"

namespace BitCrypto{

const size_t Base58Alphabet::base = 58;
const char * Base58Alphabet::map = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
const bool Base58Alphabet::strip = true;

}
