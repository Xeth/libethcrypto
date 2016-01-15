#pragma once 

#include "Secp256k1ContextPtr.hpp"
#include "Secp256k1ContextFactory.hpp"


namespace BitCrypto{



class LazySecp256k1Handler
{
    public:
        LazySecp256k1Handler();
        LazySecp256k1Handler(const Secp256k1ContextPtr &);


    protected:
        Secp256k1ContextPtr & getContext() const;


    private:
        mutable Secp256k1ContextPtr _context;
};


}


#include "LazySecp256k1Handler.ipp"
