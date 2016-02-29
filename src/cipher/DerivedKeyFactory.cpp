
#include "DerivedKeyFactory.hpp"


namespace Ethereum{


bool DerivedKeyFactory::makeDerived(const std::string &password, const ScryptParams &params, Data &result) const
{
    result.resize(params.getDKlen());
    return libscrypt_scrypt
    (
        (unsigned char const*)password.data(), 
        password.size(), 
        &params.getSalt(), 
        params.getSalt().size(), 
        params.getIterations(), 
        params.getR(), 
        params.getP(), 
        &result,
        params.getDKlen()
     ) == 0;
}



Data DerivedKeyFactory::makeDerived(const std::string &password, const ScryptParams &params) const
{
    Data derived;
    if(!makeDerived(password, params, derived))
    {
        throw std::runtime_error("failed to derive key");
    }
    return derived;
}



}
