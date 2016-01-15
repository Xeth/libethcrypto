#pragma once 

#include "Secp256k1ContextPtr.hpp"
#include "Secp256k1ContextFactory.hpp"


namespace BitCrypto{



class Secp256k1Handler
{
    public:
        Secp256k1Handler();
        Secp256k1Handler(const Secp256k1ContextPtr &);


    protected:
        Secp256k1ContextPtr & getContext() const;
        Secp256k1ContextPtr createContext();


    private:
        mutable Secp256k1ContextPtr _context;
};


}


#include "Secp256k1Handler.ipp"
