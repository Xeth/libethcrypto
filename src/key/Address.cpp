#include "Address.hpp"
#include "AddressFactory.hpp"

namespace Ethereum{


Address::Address()
{}


Address::Address(const PublicKey &key)
{
    AddressFactory factory;
    factory.createFromPublicKey(key, *this);
}

Address::Address(const std::string &str)
{
    AddressFactory factory;
    factory.createFromString(str, *this);
}

Address::Address(const char *str, size_t size)
{
    AddressFactory factory;
    factory.createFromString(str, size, *this);
}

std::string Address::toString() const
{
    HexEncoder encoder;
    return encoder.encode(begin(), end());
}

std::string Address::toStringCheckSum() const
{
    HexEncoder encoder;
    HexCaseCheckSum checksum;
    return checksum.compute(encoder.encode(begin(), end()));
}


Address::operator std::string () const
{
    return toString();
}


boost::array<unsigned char, 20> & Address::toArray()
{
    return *this;
}

const boost::array<unsigned char , 20> & Address::toArray() const
{
    return *this;
}


}
