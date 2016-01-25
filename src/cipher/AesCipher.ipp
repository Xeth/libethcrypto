
namespace Ethereum{

inline AesKey::AesKey(const std::string &password) :
    _password(password)
{}

inline AesKey::AesKey(const std::string &password, const std::string &iv) :
    _password(password),
    _iv(iv)
{}

inline const unsigned char * AesKey::getPassword() const
{
    return (unsigned char *)_password.c_str();
}

inline const unsigned char * AesKey::getIV() const
{
    return (unsigned char *)_iv.c_str();
}


template<class Input, class Output>
bool AesCipher::execute(const Input &input, Output &output, const AesKey &key, int encrypt)
{
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();

    if(!EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL, encrypt))
    {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    if(!EVP_CipherInit_ex(ctx, NULL, NULL, key.getPassword().c_str(), key.getIV().c_str(), encrypt))
    {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    int outSize = output.size();
    int inSize = input.size();

    if(!EVP_CipherUpdate(ctx, &*output.begin(), &outSize, input, inSize))
    {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    if(!EVP_CipherFinal_ex(ctx, &*output.begin(), &outSize))
    {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    EVP_CIPHER_CTX_free(ctx);
    output.resize(outSize);
    return true;
}


template<class Input, class Output>
bool AesCipher::encrypt(const Input &input, Output &output,  const AesKey &key)
{
    output.resize(((input.size() + EVP_MAX_BLOCK_LENGTH) / EVP_MAX_BLOCK_LENGTH ) * EVP_MAX_BLOCK_LENGTH );
    return execute(input, output, key, 1);
}


template<class Input, class Output>
bool AesCipher::decrypt(const Input &input, Output &output, const AesKey &key)
{
    output.resize(input.size());
    return execute(input, output, key, 0);
}


template<class Output, class Input>
Output AesCipher::encrypt(const Input &input, const AesKey &key)
{
    Output output;
    if(!encrypt(input, output, key))
    {
        throw std::runtime_error("failed to encrypt");
    }
    return output;
}


template<class Output, class Input>
Output AesCipher::decrypt(const Input &input, const AesKey &key)
{
    Output output;
    if(!decrypt(input, output, key))
    {
        throw std::runtime_error("failed tp decrypt");
    }
    return output;
}


template<class Input>
Data AesCipher::encrypt(const Input &input, const AesKey &key)
{
    return encrypt<Data>(input, key);
}


template<class Input>
Data AesCipher::decrypt(const Input &input, const AesKey &key)
{
    return decrypt<Data>(input, key);
}

}
