
namespace Ethereum{


template<class Cipher>
SecuredPrivateKey<Cipher>::SecuredPrivateKey()
{}

template<class Cipher>
template<class CipherKey>
SecuredPrivateKey<Cipher>::SecuredPrivateKey(const PrivateKey &privateKey, const Cipher &cipher, const CipherKey &key) :
    _cipher(cipher),
    _privateKey(cipher.encrypt(privateKey, key))
{}


template<class Cipher>
SecuredPrivateKey<Cipher>::SecuredPrivateKey(const EncryptedData &privateKey, const Cipher &cipher) :
    _cipher(cipher),
    _privateKey(privateKey)
{}


template<class Cipher>
SecuredPrivateKey<Cipher> & SecuredPrivateKey<Cipher>::operator = (const SecuredPrivateKey &copy)
{
    _cipher = copy._cipher;
    _privateKey = copy._privateKey;
    return *this;
}


template<class Cipher>
bool SecuredPrivateKey<Cipher>::operator == (const SecuredPrivateKey &b) const
{
    return _cipher == b._cipher && _privateKey.data ==b._privateKey.data && _privateKey.mac == b._privateKey.mac;
}


template<class Cipher>
template<class CipherKey>
PrivateKey SecuredPrivateKey<Cipher>::unlock(const CipherKey &key) const
{
    return PrivateKey(_cipher.decrypt(_privateKey, key));
}


template<class Cipher>
const EncryptedData & SecuredPrivateKey<Cipher>::getData() const
{
    return _privateKey;
}


template<class Cipher>
EncryptedData & SecuredPrivateKey<Cipher>::getData()
{
    return _privateKey;
}


template<class Cipher>
const Cipher & SecuredPrivateKey<Cipher>::getCipher() const
{
    return _cipher;
}


}
