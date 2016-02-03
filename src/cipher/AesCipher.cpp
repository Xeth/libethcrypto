#include "AesCipher.hpp"

namespace Ethereum{

AesCipher::AesCipher(const Data &iv, const ScryptParams &params) : 
    _iv(iv),
    _params(params)
{}

const ScryptParams & AesCipher::getParams() const
{
    return _params;
}

const Data & AesCipher::getIV() const
{
    return _iv;
}


Data MakeRandomIV()
{
    return MakeRandomData(16);
}

Data AesCipher::decrypt(const EncryptedData &input, const std::string &password)
{
    return decrypt<Data>(input, password);
}

Data AesCipher::makeDerived(const std::string &password)
{
    DerivedKeyFactory keyFactory;
    return keyFactory.makeDerived(password, _params);
}

}
