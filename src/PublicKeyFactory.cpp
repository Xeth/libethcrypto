#include "bitcrypto/PublicKeyFactory.hpp"


namespace BitCrypto{


PublicKeyFactory::PublicKeyFactory(const Secp256k1ContextPtr &context) : 
    Secp256k1Handler(context)
{}


PublicKeyFactory::PublicKeyFactory()
{}


PublicKey PublicKeyFactory::createFromSecret(const PrivateKey &secret)
{
    Secp256k1ContextPtr & context = getContext();
    PublicKey key(context);

    if(!secp256k1_ec_pubkey_create(context.get(), &key, secret.data()))
    {
        throw std::runtime_error("failed to create PublicKey");
    }

    return key;
}


template<class Point>
PublicKey PublicKeyFactory::createFromPointData(const Point &point)
{
    BinaryPublicKeySerializer serializer(getContext());
    PublicKey key(getContext());

    if(!serializer.unserialize(point, key))
    {
        throw std::runtime_error("invalid point");
    }

    return key;
}


PublicKey PublicKeyFactory::createFromPoint(const Data &point)
{
    return createFromPointData(point);
}


PublicKey PublicKeyFactory::createFromPoint(const UncompressedPoint &point)
{
    return createFromPointData(point);
}


PublicKey PublicKeyFactory::createFromPoint(const CompressedPoint &point)
{
    return createFromPointData(point);
}


}
