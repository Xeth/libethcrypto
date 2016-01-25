#pragma once

#include "detail/Secp256k1Handler.hpp"
#include "PrivateKey.hpp"
#include "Signature.hpp"
#include "Data.hpp"


namespace Ethereum{


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
