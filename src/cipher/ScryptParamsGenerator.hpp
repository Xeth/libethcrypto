#pragma once 

#include "ScryptParams.hpp"
#include "MakeRandomData.hpp"


namespace Ethereum{


class ScryptParamsGenerator
{
    public:
        ScryptParams generate();
        ScryptParams generate(int r, int p, int dkLen, int iterations);
};


ScryptParams MakeRandomScryptParams();
ScryptParams MakeRandomScryptParams(int r, int p, int dkLen, int iterations);


}
