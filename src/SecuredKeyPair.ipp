
namespace BitCrypto{


template<class Cipher>
template<class CipherKey>
SecuredKeyPair<Cipher>::SecuredKeyPair(const Secret &secret, const PubKey &pubKey, const Cipher &cipher, const CipherKey &cipherKey) :
    _secret(secret, cipher, cipherKey),
    _pubKey(pubKey)
{}

template<class Cipher>
SecuredKeyPair<Cipher>::SecuredKeyPair(const Data &secret, const PubKey &pubKey, const Cipher &cipher) :
    _secret(secret, cipher),
    _pubKey(pubKey)
{}

template<class Cipher>
SecuredSecret<Cipher> & SecuredKeyPair<Cipher>::getSecret()
{
    return _secret;
}

template<class Cipher>
const SecuredSecret<Cipher> & SecuredKeyPair<Cipher>::getSecret() const
{
    return _secret;
}

template<class Cipher>
PubKey & SecuredKeyPair<Cipher>::getPubKey()
{
    return _pubKey;
}

template<class Cipher>
const PubKey & SecuredKeyPair<Cipher>::getPubKey() const
{
    return _pubKey;
}

}
