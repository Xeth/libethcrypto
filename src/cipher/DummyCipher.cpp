
#include "DummyCipher.hpp"


namespace Ethereum{


DummyCipher::DummyCipher():
    _params(MakeRandomScryptParams())
{}

DummyCipher::DummyCipher(const Data &, const ScryptParams &params):
    _params(params)
{}


const Data & DummyCipher::getIV() const
{
    return _iv;
}

const ScryptParams & DummyCipher::getParams() const
{
    return _params;
}

}
