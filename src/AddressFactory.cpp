#include "AddressFactory.hpp"

namespace Ethereum{


bool AddressFactory::createFromPublicKey(const PublicKey &key, Address &result) const
{
    Sha256 hasher;
    Data hash = hasher.hash(key.begin(), key.end());
    std::copy(hash.begin() + 12, hash.end(), result.begin());
    return true;
}


Address AddressFactory::createFromPublicKey(const PublicKey &key) const
{
    Address address;
    createFromPublicKey(key, address);
    return address;
}


bool AddressFactory::createFromString(const std::string &str, Address &address) const
{
    Base16Encoder encoder;
    encoder.decode(str.begin(), str.end(), address.toArray());
    return true;
}

Address AddressFactory::createFromString(const std::string &str) const
{
    Address address;
    createFromString(str, address);
    return address;
}


bool AddressFactory::createFromString(const char *str, size_t size, Address &address) const
{
    Base16Encoder encoder;
    encoder.decode(str, str+size, address.toArray());
    return true;
}


Address AddressFactory::createFromString(const char *str, size_t size) const
{
    Address address;
    createFromString(str, size, address);
    return address;
}

}
