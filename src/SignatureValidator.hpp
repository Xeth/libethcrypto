#pragma once 

#include "bitcrypto/Data.hpp"
#include "bitcrypto/Signature.hpp"
#include "bitcrypto/PublicKey.hpp"
#include "bitcrypto/detail/Secp256k1Handler.hpp"


namespace BitCrypto{


class SignatureValidator : public Secp256k1Handler
{

    public:
        SignatureValidator();
        SignatureValidator(const Secp256k1ContextPtr &);

        bool verify(const PublicKey &, const Signature &, const Data &hash);
        bool verify(const PublicKey &, const Signature &, const unsigned char *);

};


}
