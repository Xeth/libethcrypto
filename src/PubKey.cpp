#include "PubKey.hpp"

#include <algorithm>

namespace BitCrypto{


PubKey::PubKey()
{}

PubKey::PubKey(const Secp256k1ContextPtr &context) : 
    LazySecp256k1Handler(context)
{}

PubKey::PubKey(const PubKey &copy) :
    LazySecp256k1Handler(copy.getContext())
{
    std::copy(copy._data.data, copy._data.data+33, _data.data);
}

PubKey::PubKey(const Data &bin)
{
    std::copy(bin.begin(), bin.begin()+33, _data.data);
}

PubKey::PubKey(const Data &bin, const Secp256k1ContextPtr &context) :
    LazySecp256k1Handler(context)
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


PubKey PubKey::operator + (const PubKey &key)
{
    PubKey result(getContext());
    const secp256k1_pubkey * keys[2] = {&_data, &key._data};
    if(!secp256k1_ec_pubkey_combine(getContext().get(), &result, keys, 2))
    {
        throw std::runtime_error("pubkey operation failed");
    }
    return result;
}


PubKey PubKey::operator + (const Secret &secret)
{
    PubKey result(*this);
    if(!secp256k1_ec_pubkey_tweak_add(getContext().get(), &result, secret.data()))
    {
        throw std::runtime_error("pubkey operation failed");
    }
    
    return result;
}

PubKey PubKey::operator * (const Secret &secret)
{
    PubKey result(*this);
    if(!secp256k1_ec_pubkey_tweak_mul(getContext().get(), &result, secret.data()))
    {
        throw std::runtime_error("pubkey operation failed");
    }
    return result;
}

//

PubKey & PubKey::operator += (const PubKey &key)
{
    PubKey result(getContext());
    const secp256k1_pubkey * keys[2] = {&_data, &key._data};
    if(!secp256k1_ec_pubkey_combine(getContext().get(), &result, keys, 2))
    {
        throw std::runtime_error("pubkey operation failed");
    }
    *this = result;
    return *this;
}


PubKey & PubKey::operator += (const Secret &secret)
{
    if(!secp256k1_ec_pubkey_tweak_add(getContext().get(), &_data, secret.data()))
    {
        throw std::runtime_error("pubkey operation failed");
    }

    return *this;
}

PubKey & PubKey::operator *= (const Secret &secret)
{
    if(!secp256k1_ec_pubkey_tweak_mul(getContext().get(), &_data, secret.data()))
    {
        throw std::runtime_error("pubkey operation failed");
    }

    return *this;
}


PubKey & PubKey::operator = (const PubKey &key)
{
    std::copy(key._data.data, key._data.data+33, _data.data);
    return *this;
}


}
