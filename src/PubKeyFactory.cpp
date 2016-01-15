#include "PubKeyFactory.hpp"


namespace BitCrypto{


PubKeyFactory::PubKeyFactory(const Secp256k1ContextPtr &context) : 
    _context(context)
{}



PubKeyFactory::PubKeyFactory()
{
    Secp256k1ContextFactory factory;
    _context = factory.create();
}



PubKey PubKeyFactory::createFromSecret(const Secret &secret)
{
    PubKey key(_context);

    if(!secp256k1_ec_pubkey_create(_context.get(), &key, secret.data()))
    {
        throw std::runtime_error("failed to create pubkey");
    }

    return key;
}


template<class Point>
PubKey PubKeyFactory::createFromPointData(const Point &point)
{
    PubKey key(_context);
    if(!secp256k1_ec_pubkey_parse(_context.get(), &key, point.data(), point.size()))
    {
        throw std::runtime_error("failed to parse compressed point");
    }
    return key;
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
