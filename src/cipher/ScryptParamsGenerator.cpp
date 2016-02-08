#include "ScryptParamsGenerator.hpp"

namespace Ethereum{


ScryptParams ScryptParamsGenerator::generate() const
{
    return ScryptParams(MakeRandomData(32), 8, 1, 32, 1<<18);
}

ScryptParams ScryptParamsGenerator::generate(int r, int p, int dkLen, int iterations) const
{
    return ScryptParams(MakeRandomData(32), r, p, dkLen, iterations);
}


ScryptParams MakeRandomScryptParams()
{
    ScryptParamsGenerator generator;
    return generator.generate();
}

ScryptParams MakeRandomScryptParams(int r, int p, int dkLen, int iterations)
{
    ScryptParamsGenerator generator;
    return generator.generate(r, p, dkLen, iterations);
}


}
