
namespace BitCrypto{


template<class Cipher>
template<class CipherKey>
SecuredKeyPair<Cipher>::SecuredKeyPair(const PrivateKey &privateKey, const PublicKey &publicKey, const Cipher &cipher, const CipherKey &cipherKey) :
    _privateKey(privateKey, cipher, cipherKey),
    _publicKey(publicKey)
{}

template<class Cipher>
SecuredKeyPair<Cipher>::SecuredKeyPair(const Data &privateKey, const PublicKey &publicKey, const Cipher &cipher) :
    _privateKey(privateKey, cipher),
    _publicKey(publicKey)
{}

template<class Cipher>
SecuredPrivateKey<Cipher> & SecuredKeyPair<Cipher>::getPrivateKey()
{
    return _privateKey;
}

template<class Cipher>
const SecuredPrivateKey<Cipher> & SecuredKeyPair<Cipher>::getPrivateKey() const
{
    return _privateKey;
}

template<class Cipher>
PublicKey & SecuredKeyPair<Cipher>::getPublicKey()
{
    return _publicKey;
}

template<class Cipher>
const PublicKey & SecuredKeyPair<Cipher>::getPublicKey() const
{
    return _publicKey;
}

}
