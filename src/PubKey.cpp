#include "PubKey.hpp"

#include <algorithm>

namespace BitCrypto{


PubKey::PubKey()
{}

PubKey::PubKey(const Secp256k1ContextPtr &context) : 
    _context(context)
{}

PubKey::PubKey(const PubKey &copy) :
    _context(copy._context)
{
    std::copy(copy._data.data, copy._data.data+33, _data.data);
}

PubKey::PubKey(const Data &bin)
{
    std::copy(bin.begin(), bin.begin()+33, _data.data);
}

PubKey::PubKey(const Data &bin, const Secp256k1ContextPtr &context) :
    _context(context)
{
    std::copy(bin.begin(), bin.begin()+33, _data.data);
}

PubKey::operator secp256k1_pubkey & ()
{
    return _data;
}

PubKey::operator const secp256k1_pubkey & () const
{
    return _data;
}

secp256k1_pubkey * PubKey::operator & ()
{
    return &_data;
}

const secp256k1_pubkey * PubKey::operator & () const
{
    return &_data;
}


const uint8_t * PubKey::getData() const
{
    return _data.data;
}

uint8_t PubKey::operator [](int i) const
{
    return _data.data[i];
}

PubKey::Iterator PubKey::begin()
{
    return _data.data;
}

PubKey::Iterator PubKey::end()
{
    return _data.data+33;
}

PubKey::ConstIterator PubKey::begin() const
{
    return _data.data;
}

PubKey::ConstIterator PubKey::end() const
{
    return _data.data+33;
}

}
