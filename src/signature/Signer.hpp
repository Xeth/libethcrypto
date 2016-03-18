#pragma once

#include "../detail/Secp256k1Handler.hpp"
#include "../key/PrivateKey.hpp"
#include "../detail/Data.hpp"

#include "Signature.hpp"

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
