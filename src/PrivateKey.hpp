#pragma once 

#include <boost/array.hpp>

#include "detail/LazySecp256k1Handler.hpp"
#include "Data.hpp"
#include "Signature.hpp"

namespace BitCrypto{


class PrivateKey : 
    public boost::array<unsigned char, 32>,
    public LazySecp256k1Handler
{
    public:
        PrivateKey();
        PrivateKey(const Secp256k1ContextPtr &);
        PrivateKey(const Data &);

        unsigned char * operator & ();
        const unsigned char * operator & () const;

        PrivateKey operator + (const PrivateKey &) const;
        PrivateKey operator * (const PrivateKey &) const;

        PrivateKey & operator += (const PrivateKey &);
        PrivateKey & operator *= (const PrivateKey &);


        bool sign(const unsigned char *hash, Signature &);
        bool sign(const Data &hash, Signature &);
        Signature sign(const Data &hash);
        Signature sign(const unsigned char *hash);
};


//typedef boost::array<unsigned char, 32> PrivateKey;


}
