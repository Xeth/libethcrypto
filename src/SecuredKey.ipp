namespace Ethereum{


template<class Cipher>
SecuredKey<Cipher>::SecuredKey(const SecuredPrivateKey<Cipher> &secret, const Address &address) :
    _secret(secret),
    _address(address)
{}


template<class Cipher>
SecuredKey<Cipher>::SecuredKey(const SecuredKeyPair<Cipher> &pair) :
    _secret(pair.getPrivateKey()),
    _address(pair.getPublicKey())
{}


template<class Cipher>
template<class CipherParams>
SecuredKey<Cipher>::SecuredKey(const PrivateKey &secret, const Cipher &cipher, const CipherParams &cipherParams):
    _secret(secret, cipher, cipherParams),
    _address(MakePublicKey(secret))
{}


template<class Cipher>
const SecuredPrivateKey<Cipher> & SecuredKey<Cipher>::getPrivateKey() const
{
    return _secret;
}


template<class Cipher>
const Address & SecuredKey<Cipher>::getAddress() const
{
    return _address;
}


}
