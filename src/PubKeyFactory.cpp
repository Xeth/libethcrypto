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



PubKey PubKeyFactory::create(const Secret &secret)
{
    PubKey key(_context);

    if(!secp256k1_ec_pubkey_create(_context.data(), &key, secret.data()))
    {
        throw std::runtime_error("failed to create pubkey");
    }

    return key;
}


}
