#pragma once 

#include <libscrypt.h>

#include "../Data.hpp"
#include "ScryptKey.hpp"


namespace Ethereum{


class DerivedKeyFactory
{
    public:

        bool makeDerived(const ScryptKey &, Data &) const;
        Data makeDerived(const ScryptKey &) const;

};


}

