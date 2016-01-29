#include "AesKey.hpp"

namespace Ethereum{


AesKey::AesKey(const std::string &password) :
    _password(password),
    _r(8),
    _p(1),
    _dkLen(32),
    _iterations(1<<18)
{
    makeRandom(_salt, 32);
    makeRandom(_iv, 16);
}


AesKey::AesKey(const std::string &password, int r, int p, int dkLen, int iterations, const Data &salt, const Data &iv) :
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


const unsigned char * AesKey::getIV() const
{
    return &_iv;
}


const unsigned char * AesKey::getSalt() const
{
    return &_salt;
}


int AesKey::getR() const
{
    return _r;
}


int AesKey::getP() const
{
    return _p;
}


int AesKey::getDKlen() const
{
    return _dkLen;
}


int AesKey::getIterations() const
{
    return _iterations;
}


void AesKey::makeRandom(Data &result, size_t size)
{
    boost::random_device engine;
    boost::random::uniform_int_distribution<unsigned char> generator;
    result.resize(size);

    for(Data::iterator it = result.begin(), end=result.end(); it!=end; ++it)
    {
        *it = generator(engine);
    }
}


bool AesKey::getDerivedKey(Data &result) const
{
    result.resize(_dkLen);
    return libscrypt_scrypt
    (
        (uint8_t const*)_password.data(), 
        _password.size(), 
        &_salt, 
        _salt.size(), 
        _iterations, 
        _r, 
        _p, 
        &result,
         _dkLen
     ) == 0;
}


Data AesKey::getDerivedKey() const
{
    Data derived;
    if(!getDerivedKey(derived))
    {
        throw std::runtime_error("failed to derive key");
    }
    return derived;
}


}
