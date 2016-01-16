
namespace BitCrypto{


template<class Cipher, class CipherKey>
SecuredKeyPair<Cipher> KeyGenerator::generate(const Cipher &cipher, const CipherKey &key)
{
    Secret secret  = _secretGenerator.generate();
    return SecuredKeyPair<Cipher>(secret, _pubKeyGenerator.createFromSecret(secret), cipher, key);
}


template<class Cipher, class CipherKey>
SecuredKeyPair<Cipher> KeyGenerator::generate(const Data &entropy, const Cipher &cipher, const CipherKey &key)
{
    Secret secret  = _secretGenerator.generate(entropy);
    return SecuredKeyPair<Cipher>(secret, _pubKeyGenerator.createFromSecret(secret), cipher, key);
}


template<class Cipher, class CipherKey>
SecuredKeyPair<Cipher> KeyGenerator::generate(const unsigned char *entropy, size_t entropySize, const Cipher &cipher, const CipherKey &key)
{
    Secret secret  = _secretGenerator.generate(entropy, entropySize);
    return SecuredKeyPair<Cipher>(secret, _pubKeyGenerator.createFromSecret(secret), cipher, key);
}


}
