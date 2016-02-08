#pragma once 

#include "ScryptParams.hpp"
#include "MakeRandomData.hpp"


namespace Ethereum{


class ScryptParamsGenerator
{
    public:
        ScryptParams generate() const;
        ScryptParams generate(int r, int p, int dkLen, int iterations) const;
};


ScryptParams MakeRandomScryptParams();
ScryptParams MakeRandomScryptParams(int r, int p, int dkLen, int iterations);


}
