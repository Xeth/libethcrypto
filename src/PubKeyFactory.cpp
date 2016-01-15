#include "PubKeyFactory.hpp"


namespace BitCrypto{


PubKeyFactory::PubKeyFactory(const Secp256k1ContextPtr &context) : 
    Secp256k1Handler(context)
{}



PubKeyFactory::PubKeyFactory()
{}



PubKey PubKeyFactory::createFromSecret(const Secret &secret)
{
    Secp256k1ContextPtr & context = getContext();
    PubKey key(context);

    if(!secp256k1_ec_pubkey_create(context.get(), &key, secret.data()))
    {
        throw std::runtime_error("failed to create pubkey");
    }

    return key;
}


PubKey PubKeyFactory::createFromPointData(const unsigned char *ptr, size_t size)
{
    Secp256k1ContextPtr & context = getContext();
    PubKey key(context);

    if(!secp256k1_ec_pubkey_parse(context.get(), &key, ptr, size))
    {
        throw std::runtime_error("failed to parse compressed point");
    }
    return key;
}

PubKey PubKeyFactory::createFromPoint(const Data &point)
{
    if(point.size()!=33&&point.size()!=65)
    {
        throw std::runtime_error("invalid point");
    }
    return createFromPointData(&*point.begin(), point.size());
}

PubKey PubKeyFactory::createFromPoint(const UncompressedPoint &point)
{
    return createFromPointData(point.data(), point.size());
}


PubKey PubKeyFactory::createFromPoint(const CompressedPoint &point)
{
    return createFromPointData(point.data(), point.size());
}

}
