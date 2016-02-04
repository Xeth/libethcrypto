namespace Ethereum{


template<class Secret>
PublicKey PublicKeyFactory::createFromSecret(const Secret &secret) const
{
    return createFromSecretData(secret);
}


template<class Secret>
bool PublicKeyFactory::validateSecretSize(const Secret &secret) const
{
    return secret.size() == 32;
}

inline bool PublicKeyFactory::validateSecretSize(const PrivateKey &) const
{
    return true;
}

template<class Secret>
PublicKey PublicKeyFactory::createFromSecretData(const Secret &secret) const
{
    if(!validateSecretSize(secret))
    {
        throw std::runtime_error("invalid secret");
    }

    Secp256k1ContextPtr & context = getContext();
    PublicKey key(context);

    if(!secp256k1_ec_pubkey_create(context.get(), &key, &secret))
    {
        throw std::runtime_error("failed to create PublicKey");
    }

    return key;
}


}
