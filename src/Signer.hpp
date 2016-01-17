#pragma once

#include "bitcrypto/detail/Secp256k1Handler.hpp"
#include "bitcrypto/PrivateKey.hpp"
#include "bitcrypto/Signature.hpp"
#include "bitcrypto/Data.hpp"


namespace BitCrypto{


class Signer : public Secp256k1Handler
{
    public:

        Signer();
        Signer(const Secp256k1ContextPtr &);


        bool sign(const PrivateKey &, const unsigned char *hash, Signature &);
        bool sign(const PrivateKey &, const Data &hash, Signature &);
        Signature sign(const PrivateKey &, const Data &hash);
        Signature sign(const PrivateKey &, const unsigned char *hash);
};


}
