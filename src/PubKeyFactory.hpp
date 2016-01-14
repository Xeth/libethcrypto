#pragma once 

#include "Secp256k1ContextFactory.hpp"
#include "PubKey.hpp"


namespace BitCrypto{


class PubKeyFactory
{
    public:
        PubKeyFactory();
        PubKeyFactory(const Secp256k1ContextPtr &);

        PubKey create(const Secret &secret);


    private:
        Secp256k1ContextPtr _context;
};


}
