#pragma once 

#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <libscrypt.h>

#include "../Data.hpp"


namespace Ethereum{


class AesKey
{
    public:
        AesKey(const std::string &password);
        AesKey(const std::string &password, int r, int p, int dkLen = 32, int iterations=(1<<18), const Data &salt=Data(), const Data &iv=Data());

        const unsigned char *getIV() const;
        const unsigned char * getSalt() const;

        int getR() const;
        int getP() const;
        int getDKlen() const;
        int getIterations() const;

        Data getDerivedKey() const;
        bool getDerivedKey(Data &) const;

    private:
        void makeRandom(Data &, size_t);

    private:
        std::string _password;
        Data _iv;
        Data _salt;
        int _r;
        int _p;
        int _dkLen;
        int _iterations;
};


}
