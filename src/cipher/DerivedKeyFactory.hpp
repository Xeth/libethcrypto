#pragma once 

#include <stdexcept>

#include "ethcrypto/libscrypt.h"

#include "../detail/Data.hpp"
#include "ScryptParams.hpp"


namespace Ethereum{


class DerivedKeyFactory
{
    public:

        bool makeDerived(const std::string &password, const ScryptParams &, Data &) const;
        Data makeDerived(const std::string &password, const ScryptParams &) const;

};


}

