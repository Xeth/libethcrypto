#pragma once 


#include "../Data.hpp"
#include "MakeRandomData.hpp"


namespace Ethereum{




class ScryptParams
{
    public:
        ScryptParams();
        ScryptParams(const Data &salt, int r, int p, int dkLen = 32, int iterations=(1<<18));

        const Data & getSalt() const;
        const Data & getIV() const;

        int getR() const;
        int getP() const;
        int getDKlen() const;
        int getIterations() const;

        ScryptParams & operator = (const ScryptParams &);

    private:
        Data _iv;
        Data _salt;
        int _r;
        int _p;
        int _dkLen;
        int _iterations;
};



}
