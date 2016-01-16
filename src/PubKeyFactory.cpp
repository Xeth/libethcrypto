#include "bitcrypto/PubKeyFactory.hpp"


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


template<class Point>
PubKey PubKeyFactory::createFromPointData(const Point &point)
{
    BinaryPubKeySerializer serializer(getContext());
    PubKey key(getContext());

    if(!serializer.unserialize(point, key))
    {
        throw std::runtime_error("invalid point");
    }

    return key;
}


PubKey PubKeyFactory::createFromPoint(const Data &point)
{
    return createFromPointData(point);
}


PubKey PubKeyFactory::createFromPoint(const UncompressedPoint &point)
{
    return createFromPointData(point);
}


PubKey PubKeyFactory::createFromPoint(const CompressedPoint &point)
{
    return createFromPointData(point);
}


}
