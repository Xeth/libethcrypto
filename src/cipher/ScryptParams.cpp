#include "ScryptParams.hpp"

#include <iostream>

namespace Ethereum{


ScryptParams MakeRandomScryptParams()
{
    return ScryptParams(MakeRandomData(32), 8, 1, 32, 1<<18);
}

ScryptParams MakeRandomScryptParams(int r, int p, int dkLen, int iterations)
{
    return ScryptParams(MakeRandomData(32), r, p, dkLen, iterations);
}


ScryptParams::ScryptParams(const Data &salt, int r, int p, int dkLen, int iterations) :
    _r(r),
    _p(p),
    _dkLen(dkLen),
    _iterations(iterations),
    _salt(salt)
{}


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
