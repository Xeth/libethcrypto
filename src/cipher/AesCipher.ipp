
namespace Ethereum{

template<class Handler, class Input, class Output>
bool AesCipher::execute(Handler &handler, const Input &input, Output &output, const AesKey &key)
{
    Data derivedKey = key.getDerivedKey();
    handler.SetKeyWithIV(&derivedKey, derivedKey.size(), key.getIV());
    StreamTransformationFilter stream(handler, NULL);
    for(typename Input::const_iterator it = input.begin(), end=input.end(); it!=end; ++it)
    {
        stream.Put(*it);
    }
    output.resize(stream.MaxRetrievable());
    stream.Get(BufferCast(output), output.size());
    return true;
}


template<class Input, class Output>
bool AesCipher::encrypt(const Input &input, Output &output, const AesKey &key)
{
    CTR_Mode< AES >::Encryption encryption;
    return execute(encryption, input, output, key);
}


template<class Input, class Output>
bool AesCipher::decrypt(const Input &input, Output &output, const AesKey &key)
{
    CTR_Mode<AES>::Decryption decryption;
    return execute(decryption, input, output, key);
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
