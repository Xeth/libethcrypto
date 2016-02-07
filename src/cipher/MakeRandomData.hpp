#pragma once 

#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "../Data.hpp"

namespace Ethereum{

Data MakeRandomIV();
Data MakeRandomData(size_t size);
void MakeRandomData(Data &data, size_t size);



}
