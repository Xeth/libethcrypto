#pragma once 

#include <boost/array.hpp>

#include "Secp256k1ContextPtr.hpp"
#include "Secp256k1ContextFactory.hpp"
#include "Data.hpp"


namespace BitCrypto{


class Secret : public boost::array<unsigned char, 32>
{
    public:
        Secret();
        Secret(const Secp256k1ContextPtr &);
        Secret(const Data &);

        unsigned char * operator & ();
        const unsigned char * operator & () const;

        Secret operator + (const Secret &) const;
        Secret operator * (const Secret &) const;

        Secret & operator += (const Secret &);
        Secret & operator *= (const Secret &);

    private:
        void createContextIfNeeded() const;

    private:
        mutable Secp256k1ContextPtr _context;
};


//typedef boost::array<unsigned char, 32> Secret;


}
