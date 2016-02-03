#pragma once

#include "../Data.hpp"


namespace Ethereum{


struct EncryptedData
{
    EncryptedData();
    EncryptedData(const Data &data, const Data &mac);
    Data data;
    Data mac;
};


inline EncryptedData::EncryptedData()
{}

inline EncryptedData::EncryptedData(const Data &data, const Data &mac) :
    data(data),
    mac(mac)
{}

}
