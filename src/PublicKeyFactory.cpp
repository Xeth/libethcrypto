#include "PublicKeyFactory.hpp"


namespace Ethereum{

PublicKey MakePublicKey(const PrivateKey &secret)
{
    PublicKeyFactory factory;
    return factory.createFromSecret(secret);
}

PublicKeyFactory::PublicKeyFactory(const Secp256k1ContextPtr &context) : 
    Secp256k1Handler(context)
{}


PublicKeyFactory::PublicKeyFactory()
{}


PublicKey PublicKeyFactory::createFromSecret(const PrivateKey &secret) const
{
    return createFromSecretData(secret);
}



template<class Point>
PublicKey PublicKeyFactory::createFromPointData(const Point &point) const
{
    BinaryPublicKeySerializer serializer(getContext());
    PublicKey key(getContext());

    if(!serializer.unserialize(point, key))
    {
        throw std::runtime_error("invalid point");
    }

    return key;
}


PublicKey PublicKeyFactory::createFromPoint(const Data &point) const
{
    return createFromPointData(point);
}


PublicKey PublicKeyFactory::createFromPoint(const UncompressedPoint &point) const
{
    return createFromPointData(point);
}


PublicKey PublicKeyFactory::createFromPoint(const CompressedPoint &point) const
{
    return createFromPointData(point);
}


}
