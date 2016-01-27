#pragma once 

#include <algorithm>
#include <stdexcept>

#include "../Data.hpp"
#include "../PrivateKey.hpp"


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
