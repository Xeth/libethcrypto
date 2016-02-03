
namespace Ethereum{




template<class Handler, class Input, class Output>
bool AesCipher::execute(Handler &handler, const Input &input, Output &output, const std::string &password)
{
    DerivedKeyFactory keyFactory;
    Data derivedKey = keyFactory.makeDerived(password, _params);

    handler.SetKeyWithIV(&derivedKey, derivedKey.size(), &_iv);
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
bool AesCipher::encrypt(const Input &input, Output &output, const std::string &password)
{
    CTR_Mode< AES >::Encryption encryption;
    return execute(encryption, input, output, password);
}


template<class Input, class Output>
bool AesCipher::decrypt(const Input &input, Output &output, const std::string &password)
{
    CTR_Mode<AES>::Decryption decryption;
    return execute(decryption, input, output, password);
}




template<class Output, class Input>
Output AesCipher::encrypt(const Input &input, const std::string &password)
{
    Output output;
    if(!encrypt(input, output, password))
    {
        throw std::runtime_error("failed to encrypt");
    }
    return output;
}


template<class Output, class Input>
Output AesCipher::decrypt(const Input &input, const std::string &password)
{
    Output output;
    if(!decrypt(input, output, password))
    {
        throw std::runtime_error("failed tp decrypt");
    }
    return output;
}


template<class Input>
Data AesCipher::encrypt(const Input &input, const std::string &password)
{
    return encrypt<Data>(input, password);
}


template<class Input>
Data AesCipher::decrypt(const Input &input, const std::string &password)
{
    return decrypt<Data>(input, password);
}

}
