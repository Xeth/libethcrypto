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

}
