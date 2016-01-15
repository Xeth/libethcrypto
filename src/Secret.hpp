#pragma once 

#include <boost/array.hpp>

#include "detail/LazySecp256k1Handler.hpp"
#include "Data.hpp"


namespace BitCrypto{


class Secret : 
    public boost::array<unsigned char, 32>,
    public LazySecp256k1Handler
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

};


//typedef boost::array<unsigned char, 32> Secret;


}
