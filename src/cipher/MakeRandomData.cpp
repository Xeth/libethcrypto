#include "MakeRandomData.hpp"


namespace Ethereum{


Data MakeRandomData(size_t size)
{
    Data result;
    MakeRandomData(result, size);
    return result;
}


void MakeRandomData(Data &result, size_t size)
{
    boost::random_device engine;
    boost::random::uniform_int_distribution<unsigned char> generator;
    result.resize(size);

    for(Data::iterator it = result.begin(), end=result.end(); it!=end; ++it)
    {
        *it = generator(engine);
    }
}

Data MakeRandomIV()
{
    return MakeRandomData(16);
}




}
