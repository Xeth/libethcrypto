#pragma once 

#include <algorithm>
#include <stdexcept>

#include "bitcrypto/Data.hpp"
#include "bitcrypto/Secret.hpp"


namespace BitCrypto{


class DummyKey
{};


class DummyCipher
{
    public:
        Secret decrypt(const Data &, const DummyKey &);
        Data encrypt(const Secret &, const DummyKey &);
};


}
