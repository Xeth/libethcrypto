
namespace BitCrypto{


template<class Cipher>
template<class CipherKey>
SecuredPrivateKey<Cipher>::SecuredPrivateKey(const PrivateKey &privateKey, const Cipher &cipher, const CipherKey &key) :
    _cipher(cipher),
    _privateKey(cipher.encrypt(privateKey, key))
{}


template<class Cipher>
SecuredPrivateKey<Cipher>::SecuredPrivateKey(const Data &privateKey, const Cipher &cipher) :
    _cipher(cipher),
    _privateKey(privateKey)
{}



template<class Cipher>
template<class CipherKey>
PrivateKey SecuredPrivateKey<Cipher>::unlock(const CipherKey &key) const
{
    return _cipher.decrypt(_privateKey, key);
}


template<class Cipher>
const Data & SecuredPrivateKey<Cipher>::getData() const
{
    return _privateKey;
}


template<class Cipher>
Data & SecuredPrivateKey<Cipher>::getData()
{
    return _privateKey;
}


}
