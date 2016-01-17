#include "SignatureValidator.hpp"

namespace BitCrypto{


SignatureValidator::SignatureValidator()
{}


SignatureValidator::SignatureValidator(const Secp256k1ContextPtr &ptr) :
    Secp256k1Handler(ptr)
{}


bool SignatureValidator::verify(const PublicKey &key, const Signature &signature, const Data &hash)
{
    if(hash.size() != 32)
    {
        return false;
    }
    return  secp256k1_ecdsa_verify(getContext().get(), &signature, &*hash.begin(), &key);
}


bool SignatureValidator::verify(const PublicKey &key, const Signature &signature, const unsigned char *hash)
{
    return  secp256k1_ecdsa_verify(getContext().get(), &signature, hash, &key);
}


}
