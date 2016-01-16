
#include "DummyCipher.hpp"


namespace BitCrypto{


Secret DummyCipher::decrypt(const Data &data, const DummyKey &)
{
    if(data.size() != 32)
    {
        throw std::runtime_error("invalid data");
    }
    Secret secret;
    std::copy(data.begin(), data.end(), secret.begin());
    return secret;
}


Data DummyCipher::encrypt(const Secret &secret, const DummyKey &)
{
    Data data;
    data.resize(32);
    std::copy(secret.begin(), secret.end(), data.begin());
    return data;
}

}
