#pragma once

#include <algorithm>

#include "ethkey/secp256k1/secp256k1.h"
#include "detail/LazySecp256k1Handler.hpp"
#include "Data.hpp"
#include "PrivateKey.hpp"


namespace Ethereum{


class PublicKey : public LazySecp256k1Handler
{
    public:
        typedef  unsigned char * Iterator;
        typedef const unsigned char * ConstIterator;

    public:
        PublicKey();
        PublicKey(const PublicKey &);
        explicit PublicKey(const Data &);
        explicit PublicKey(const Secp256k1ContextPtr &);
        explicit PublicKey(const Data &, const Secp256k1ContextPtr &);

        operator secp256k1_pubkey & ();
        operator const secp256k1_pubkey & () const;
        secp256k1_pubkey * operator & ();
        const secp256k1_pubkey * operator & () const;
        
        unsigned char operator [](int i) const;
        const unsigned char * getData() const;

        ConstIterator begin() const;
        ConstIterator end() const;

        Iterator begin();
        Iterator end();

        PublicKey operator + (const PublicKey &) const;
        PublicKey operator + (const PrivateKey &) const;
        PublicKey operator * (const PrivateKey &) const;
        PublicKey & operator += (const PublicKey &);
        PublicKey & operator += (const PrivateKey &);
        PublicKey & operator *= (const PrivateKey &);
        PublicKey & operator = (const PublicKey &);

        bool operator == (const PublicKey &) const;

    private:
        secp256k1_pubkey _data;

};



}
