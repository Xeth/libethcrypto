#pragma once 

#include <algorithm>
#include <stdexcept>

#include "bitcrypto/Data.hpp"
#include "bitcrypto/PrivateKey.hpp"


namespace BitCrypto{


class DummyKey
{};


class DummyCipher
{
    public:
        PrivateKey decrypt(const Data &, const DummyKey &) const;
        Data encrypt(const PrivateKey &, const DummyKey &) const;
};


}
