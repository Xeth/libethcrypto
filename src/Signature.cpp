#include "Signature.hpp"


namespace BitCrypto{


Signature::Signature()
{}


Signature::Signature(const Signature &copy)
{
    std::copy(copy._data.data, copy._data.data+64, _data.data);
}


Signature::Signature(const secp256k1_ecdsa_signature &signature) 
{
    std::copy(signature.data, signature.data+64, _data.data);
}


secp256k1_ecdsa_signature * Signature::operator & ()
{
    return &_data;
}


const secp256k1_ecdsa_signature * Signature::operator & () const
{
    return &_data;
}

}
