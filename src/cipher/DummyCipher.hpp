#pragma once 

#include <algorithm>
#include <stdexcept>

#include "ethkey/Data.hpp"
#include "ethkey/PrivateKey.hpp"


namespace Ethereum{


class DummyKey
{};


class DummyCipher
{
    public:
        PrivateKey decrypt(const Data &, const DummyKey &) const;
        Data encrypt(const PrivateKey &, const DummyKey &) const;
};


}
