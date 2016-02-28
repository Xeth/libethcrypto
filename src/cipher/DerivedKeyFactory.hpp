#pragma once 

#include "ethkey/libscrypt.h"

#include "../Data.hpp"
#include "ScryptParams.hpp"


namespace Ethereum{


class DerivedKeyFactory
{
    public:

        bool makeDerived(const std::string &password, const ScryptParams &, Data &) const;
        Data makeDerived(const std::string &password, const ScryptParams &) const;

};


}

