#include "CipherMacFactory.hpp"


namespace Ethereum{


Data CipherMacFactory::createMac(const Data &encrypted, const Data &key) const
{
    Data result;
    createMac(encrypted, key, result);
    return result;
}


void CipherMacFactory::createMac(const Data &encrypted, const Data &key, Data &result) const
{
    Sha3 hasher;
    hasher.update(key.begin()+16, key.end());
    hasher.update(encrypted.begin(), encrypted.end());
    hasher.finalize(result);
}


}
