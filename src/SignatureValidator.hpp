#pragma once 

#include "Data.hpp"
#include "Signature.hpp"
#include "PublicKey.hpp"
#include "detail/Secp256k1Handler.hpp"


namespace Ethereum{


class SignatureValidator : public Secp256k1Handler
{

    public:
        SignatureValidator();
        SignatureValidator(const Secp256k1ContextPtr &);

        bool verify(const PublicKey &, const Signature &, const Data &hash);
        bool verify(const PublicKey &, const Signature &, const unsigned char *);

};


}
