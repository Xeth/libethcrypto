
namespace BitCrypto{


template<class Cipher>
template<class CipherKey>
SecuredSecret<Cipher>::SecuredSecret(const Secret &secret, const Cipher &cipher, const CipherKey &key) :
    _cipher(cipher),
    _secret(cipher.encrypt(secret, key))
{}


template<class Cipher>
SecuredSecret<Cipher>::SecuredSecret(const Data &secret, const Cipher &cipher) :
    _cipher(cipher)
    _secret(secret)
{}



template<class Cipher>
template<class CipherKey>
Secret SecuredSecret<Cipher>::unlock(const CipherKey &key) 
{
    return _cipher.decrypt(_secret, key);
}



}
