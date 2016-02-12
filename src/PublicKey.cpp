#include "PublicKey.hpp"

#include <algorithm>

namespace Ethereum{


PublicKey::PublicKey()
{}

PublicKey::PublicKey(const Secp256k1ContextPtr &context) : 
    LazySecp256k1Handler(context)
{}

PublicKey::PublicKey(const PublicKey &copy) :
    LazySecp256k1Handler(copy.getContext())
{
    std::copy(copy._data.data, copy._data.data+sizeof(_data.data), _data.data);
}

PublicKey::PublicKey(const Data &bin)
{
    std::copy(bin.begin(), bin.begin()+sizeof(_data.data), _data.data);
}

PublicKey::PublicKey(const Data &bin, const Secp256k1ContextPtr &context) :
    LazySecp256k1Handler(context)
{
    std::copy(bin.begin(), bin.begin()+sizeof(_data.data), _data.data);
}

PublicKey::operator secp256k1_pubkey & ()
{
    return _data;
}

PublicKey::operator const secp256k1_pubkey & () const
{
    return _data;
}

secp256k1_pubkey * PublicKey::operator & ()
{
    return &_data;
}

const secp256k1_pubkey * PublicKey::operator & () const
{
    return &_data;
}


const uint8_t * PublicKey::getData() const
{
    return _data.data;
}

uint8_t PublicKey::operator [](int i) const
{
    return _data.data[i];
}

PublicKey::Iterator PublicKey::begin()
{
    return _data.data;
}

PublicKey::Iterator PublicKey::end()
{
    return _data.data+sizeof(_data.data);
}

PublicKey::ConstIterator PublicKey::begin() const
{
    return _data.data;
}

PublicKey::ConstIterator PublicKey::end() const
{
    return _data.data+sizeof(_data.data);
}


PublicKey PublicKey::operator + (const PublicKey &key) const
{
    PublicKey result(getContext());
    const secp256k1_pubkey * keys[2] = {&_data, &key._data};
    if(!secp256k1_ec_pubkey_combine(getContext().get(), &result, keys, 2))
    {
        throw std::runtime_error("PublicKey operation failed");
    }
    return result;
}


PublicKey PublicKey::operator + (const PrivateKey &secret) const
{
    PublicKey result(*this);
    if(!secp256k1_ec_pubkey_tweak_add(getContext().get(), &result, secret.data()))
    {
        throw std::runtime_error("PublicKey operation failed");
    }
    
    return result;
}

PublicKey PublicKey::operator * (const PrivateKey &secret) const
{
    PublicKey result(*this);
    if(!secp256k1_ec_pubkey_tweak_mul(getContext().get(), &result, secret.data()))
    {
        throw std::runtime_error("PublicKey operation failed");
    }
    return result;
}

//

PublicKey & PublicKey::operator += (const PublicKey &key)
{
    PublicKey result(getContext());
    const secp256k1_pubkey * keys[2] = {&_data, &key._data};
    if(!secp256k1_ec_pubkey_combine(getContext().get(), &result, keys, 2))
    {
        throw std::runtime_error("PublicKey operation failed");
    }
    *this = result;
    return *this;
}


PublicKey & PublicKey::operator += (const PrivateKey &secret)
{
    if(!secp256k1_ec_pubkey_tweak_add(getContext().get(), &_data, secret.data()))
    {
        throw std::runtime_error("PublicKey operation failed");
    }

    return *this;
}

PublicKey & PublicKey::operator *= (const PrivateKey &secret)
{
    if(!secp256k1_ec_pubkey_tweak_mul(getContext().get(), &_data, secret.data()))
    {
        throw std::runtime_error("PublicKey operation failed");
    }

    return *this;
}


PublicKey & PublicKey::operator = (const PublicKey &key)
{
    std::copy(key._data.data, key._data.data+sizeof(_data.data), _data.data);
    return *this;
}


bool PublicKey::operator == (const PublicKey &a) const
{
    return std::equal(_data.data, _data.data+sizeof(_data.data), a._data.data);
}



}
