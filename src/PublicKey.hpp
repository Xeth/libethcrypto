#pragma once

#include <stdint.h>

#include "bitcrypto/secp256k1/secp256k1.h"
#include "bitcrypto/detail/LazySecp256k1Handler.hpp"
#include "bitcrypto/Data.hpp"
#include "bitcrypto/PrivateKey.hpp"


namespace BitCrypto{


class PublicKey : public LazySecp256k1Handler
{
    public:
        typedef  uint8_t * Iterator;
        typedef const uint8_t * ConstIterator;

    public:
        PublicKey();
        PublicKey(const PublicKey &);
        PublicKey(const Data &);
        PublicKey(const Secp256k1ContextPtr &);
        PublicKey(const Data &, const Secp256k1ContextPtr &);

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

        PublicKey operator + (const PublicKey &);
        PublicKey operator + (const PrivateKey &);
        PublicKey operator * (const PrivateKey &);
        PublicKey & operator += (const PublicKey &);
        PublicKey & operator += (const PrivateKey &);
        PublicKey & operator *= (const PrivateKey &);
        PublicKey & operator = (const PublicKey &);



    private:
        secp256k1_pubkey _data;
        Secp256k1ContextPtr _context;

};



}
