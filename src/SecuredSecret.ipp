
namespace BitCrypto{


template<class Cipher>
template<class CipherKey>
SecuredSecret<Cipher>::SecuredSecret(const Secret &secret, const CipherKey &key) :
    _secret(_cipher.encrypt(secret, key))
{}


template<class Cipher>
SecuredSecret<Cipher>::SecuredSecret(const Data &secret) :
    _secret(secret)
{}



template<class Cipher>
template<class CipherKey>
Secret SecuredSecret<Cipher>::unlock(const CipherKey &key) 
{
    return _cipher.decrypt(_secret, key);
}



}
