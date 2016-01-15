#pragma once

#include <stdint.h>

#include "secp256k1/secp256k1.h"
#include "detail/LazySecp256k1Handler.hpp"
#include "Data.hpp"
#include "Secret.hpp"


namespace BitCrypto{


class PubKey : public LazySecp256k1Handler
{
    public:
        typedef  uint8_t * Iterator;
        typedef const uint8_t * ConstIterator;

    public:
        PubKey();
        PubKey(const PubKey &);
        PubKey(const Data &);
        PubKey(const Secp256k1ContextPtr &);
        PubKey(const Data &, const Secp256k1ContextPtr &);

        operator secp256k1_pubkey & ();
        operator const secp256k1_pubkey & () const;
        secp256k1_pubkey * operator & ();
        const secp256k1_pubkey * operator & () const;
        
        uint8_t operator [](int i) const;
        const uint8_t * getData() const;

        ConstIterator begin() const;
        ConstIterator end() const;

        Iterator begin();
        Iterator end();

        PubKey operator + (const PubKey &);
        PubKey operator + (const Secret &);
        PubKey operator * (const Secret &);
        PubKey & operator += (const PubKey &);
        PubKey & operator += (const Secret &);
        PubKey & operator *= (const Secret &);
        PubKey & operator = (const PubKey &);


    private:
        secp256k1_pubkey _data;
        Secp256k1ContextPtr _context;

};



}
