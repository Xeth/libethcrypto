
namespace Ethereum{


template<class Cipher, class CipherKey>
SecuredKeyPair<Cipher> KeyGenerator::generate(const Cipher &cipher, const CipherKey &key)
{
    PrivateKey privateKey  = _privateKeyGenerator.generate();
    return SecuredKeyPair<Cipher>(privateKey, _publicKeyGenerator.createFromSecret(privateKey), cipher, key);
}


template<class Cipher, class CipherKey>
SecuredKeyPair<Cipher> KeyGenerator::generate(const Data &entropy, const Cipher &cipher, const CipherKey &key)
{
    PrivateKey privateKey  = _privateKeyGenerator.generate(entropy);
    return SecuredKeyPair<Cipher>(privateKey, _publicKeyGenerator.createFromSecret(privateKey), cipher, key);
}


template<class Cipher, class CipherKey>
SecuredKeyPair<Cipher> KeyGenerator::generate(const unsigned char *entropy, size_t entropySize, const Cipher &cipher, const CipherKey &key)
{
    PrivateKey privateKey  = _privateKeyGenerator.generate(entropy, entropySize);
    return SecuredKeyPair<Cipher>(privateKey, _publicKeyGenerator.createFromSecret(privateKey), cipher, key);
}


}
