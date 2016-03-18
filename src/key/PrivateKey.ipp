namespace Ethereum{

template<class Secret>
PrivateKey PrivateKey::operator + (const Secret &secret) const
{
    return sum(secret);
}

template<class Secret>
PrivateKey PrivateKey::operator * (const Secret &secret) const
{
    return multiply(secret);
}


template<class Secret>
PrivateKey PrivateKey::sum(const Secret &secret) const
{
    if(!validateSecretSize(secret))
    {
        throw std::runtime_error("invalid secret");
    }

    PrivateKey result(*this);
    if(!secp256k1_ec_privkey_tweak_add(getContext().get(), &result, &secret))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}

template<class Secret>
PrivateKey PrivateKey::multiply(const Secret &secret ) const
{
    if(!validateSecretSize(secret))
    {
        throw std::runtime_error("invalid secret");
    }

    PrivateKey result(*this);
    if(!secp256k1_ec_privkey_tweak_mul(getContext().get(), &result, &secret))
    {
        throw std::runtime_error("private key operation failed");
    }
    return result;
}


template<class Secret>
bool PrivateKey::validateSecretSize(const Secret &secret) const
{
    return secret.size() == 32;
}


inline bool PrivateKey::validateSecretSize(const PrivateKey &) const
{
    return true;
}


}
