namespace Ethereum{

template<class Key>
PrivateKey DummyCipher::decrypt(const EncryptedData &encrypted, const Key &) const
{
    if(encrypted.data.size() != 32)
    {
        throw std::runtime_error("invalid data");
    }
    PrivateKey PrivateKey;
    std::copy(encrypted.data.begin(), encrypted.data.end(), PrivateKey.begin());
    return PrivateKey;
}

template<class Key>
EncryptedData DummyCipher::encrypt(const PrivateKey &PrivateKey, const Key &) const
{
    EncryptedData encrypted;
    encrypted.data.resize(32);
    std::copy(PrivateKey.begin(), PrivateKey.end(), encrypted.data.begin());
    return encrypted;
}


}
