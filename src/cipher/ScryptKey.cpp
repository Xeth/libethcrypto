#include "ScryptKey.hpp"

namespace Ethereum{


ScryptKey::ScryptKey(const std::string &password) :
    _password(password),
    _r(8),
    _p(1),
    _dkLen(32),
    _iterations(1<<18)
{
    makeRandom(_salt, 32);
    makeRandom(_iv, 16);
}


ScryptKey::ScryptKey(const std::string &password, int r, int p, int dkLen, int iterations, const Data &salt, const Data &iv) :
    _password(password),
    _r(r),
    _p(p),
    _dkLen(dkLen),
    _iterations(iterations),
    _salt(salt),
    _iv(iv)
{
    if(!salt.size())
    {
        makeRandom(_salt, 32);
    }

    if(!iv.size())
    {
        makeRandom(_iv, 16);
    }
}


const Data & ScryptKey::getIV() const
{
    return _iv;
}


const Data & ScryptKey::getSalt() const
{
    return _salt;
}


int ScryptKey::getR() const
{
    return _r;
}


int ScryptKey::getP() const
{
    return _p;
}


int ScryptKey::getDKlen() const
{
    return _dkLen;
}


int ScryptKey::getIterations() const
{
    return _iterations;
}


void ScryptKey::makeRandom(Data &result, size_t size)
{
    boost::random_device engine;
    boost::random::uniform_int_distribution<unsigned char> generator;
    result.resize(size);

    for(Data::iterator it = result.begin(), end=result.end(); it!=end; ++it)
    {
        *it = generator(engine);
    }
}

const std::string & ScryptKey::getPassword() const
{
    return _password;
}



}
