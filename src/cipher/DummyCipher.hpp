#pragma once 

#include <algorithm>
#include <stdexcept>

#include "../Data.hpp"
#include "../PrivateKey.hpp"

#include "EncryptedData.hpp"
#include "ScryptParams.hpp"

namespace Ethereum{


class DummyKey
{};


class DummyCipher
{
    public:
        typedef ScryptParams KdfParams;

    public:
        DummyCipher();
        DummyCipher(const Data &, const ScryptParams &);

        template<class Key>
        PrivateKey decrypt(const EncryptedData &, const Key &) const;

        template<class Key>
        EncryptedData encrypt(const PrivateKey &, const Key &) const;

        const Data & getIV() const;
        const ScryptParams & getParams() const;

    private:
        Data _iv;
        ScryptParams _params;
};


}

#include "DummyCipher.ipp"
