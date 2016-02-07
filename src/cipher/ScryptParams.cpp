#include "ScryptParams.hpp"

#include <iostream>

namespace Ethereum{


ScryptParams::ScryptParams()
{}


ScryptParams::ScryptParams(const Data &salt, int r, int p, int dkLen, int iterations) :
    _r(r),
    _p(p),
    _dkLen(dkLen),
    _iterations(iterations),
    _salt(salt)
{}


ScryptParams & ScryptParams::operator = (const ScryptParams &copy)
{
    _r = copy._r;
    _p = copy._p;
    _dkLen = copy._dkLen;
    _iterations = copy._iterations;
    _salt = copy._salt;
    return *this;
}

const Data & ScryptParams::getSalt() const
{
    return _salt;
}


int ScryptParams::getR() const
{
    return _r;
}


int ScryptParams::getP() const
{
    return _p;
}


int ScryptParams::getDKlen() const
{
    return _dkLen;
}


int ScryptParams::getIterations() const
{
    return _iterations;
}






}
