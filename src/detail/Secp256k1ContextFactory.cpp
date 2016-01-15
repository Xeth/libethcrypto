#include "Secp256k1ContextFactory.hpp"

namespace BitCrypto{


boost::shared_ptr<secp256k1_context> Secp256k1ContextFactory::create() const
{
    boost::shared_ptr<secp256k1_context> context(makeNew(), Secp256k1ContextDisposer());
    return context;
}


boost::shared_ptr<secp256k1_context> Secp256k1ContextFactory::create(int flags) const
{
    boost::shared_ptr<secp256k1_context> context(makeNew(flags), Secp256k1ContextDisposer());
    return context;
}


secp256k1_context * Secp256k1ContextFactory::makeNew(int flags) const
{
    return secp256k1_context_create(flags);
}


void Secp256k1ContextDisposer::operator()(secp256k1_context *context) const
{
    if(context)
    {
        secp256k1_context_destroy(context);
    }
}


}
