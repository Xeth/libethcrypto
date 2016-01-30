
#include "DerivedKeyFactory.hpp"


namespace Ethereum{


bool DerivedKeyFactory::makeDerived(const ScryptKey &key, Data &result) const
{
    result.resize(key.getDKlen());
    return libscrypt_scrypt
    (
        (uint8_t const*)key.getPassword().data(), 
        key.getPassword().size(), 
        &key.getSalt(), 
        key.getSalt().size(), 
        key.getIterations(), 
        key.getR(), 
        key.getP(), 
        &result,
        key.getDKlen()
     ) == 0;
}



Data DerivedKeyFactory::makeDerived(const ScryptKey &key) const
{
    Data derived;
    if(!makeDerived(key, derived))
    {
        throw std::runtime_error("failed to derive key");
    }
    return derived;
}



}
