#pragma once 

#include <boost/array.hpp>

#include "../detail/LazySecp256k1Handler.hpp"
#include "../detail/Data.hpp"
#include "../signature/Signature.hpp"

namespace Ethereum{


class PrivateKey : 
    public boost::array<unsigned char, 32>,
    public LazySecp256k1Handler
{
    public:
        PrivateKey();
        explicit PrivateKey(const Secp256k1ContextPtr &);
        explicit PrivateKey(const Data &);

        unsigned char * operator & ();
        const unsigned char * operator & () const;

        PrivateKey operator + (const PrivateKey &) const;
        PrivateKey operator * (const PrivateKey &) const;

        PrivateKey & operator += (const PrivateKey &);
        PrivateKey & operator *= (const PrivateKey &);


        template<class Secret>
        PrivateKey operator + (const Secret &) const;

        template<class Secret>
        PrivateKey operator * (const Secret &) const;

    private:

        template<class Secret>
        bool validateSecretSize(const Secret &) const;
        bool validateSecretSize(const PrivateKey &) const;


        template<class Secret>
        PrivateKey sum(const Secret &) const;

        template<class Secret>
        PrivateKey multiply(const Secret &) const;
};




}


#include "PrivateKey.ipp"
