
namespace Ethereum{




template<class Handler, class Input, class Output>
bool AesCipher::execute(Handler &handler, const Input &input, Output &output, const Data &derivedKey)
{
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


template<class Input>
bool AesCipher::encrypt(const Input &input, EncryptedData &output, const std::string &password)
{
    Data derivedKey = makeDerived(password);

    CTR_Mode< AES >::Encryption encryption;
    if(!execute(encryption, input, output.data, derivedKey))
    {
        return false;
    }

    CipherMacFactory macFactory;
    macFactory.createMac(output.data, derivedKey, output.mac);

    return true;
}


template<class Output>
bool AesCipher::decrypt(const EncryptedData &input, Output &output, const std::string &password)
{
    Data derivedKey = makeDerived(password);
    Data mac;
    CipherMacFactory macFactory;
    macFactory.createMac(input.data, derivedKey, mac);

    if(mac!=input.mac)
    {
        return false;
    }

    CTR_Mode<AES>::Decryption decryption;
    if(!execute(decryption, input.data, output, derivedKey))
    {
        return false;
    }

    return true;
}




template<class Input>
EncryptedData AesCipher::encrypt(const Input &input, const std::string &password)
{
    EncryptedData output;
    if(!encrypt(input, output, password))
    {
        throw std::runtime_error("failed to encrypt");
    }
    return output;
}


template<class Output>
Output AesCipher::decrypt(const EncryptedData &input, const std::string &password)
{
    Output output;
    if(!decrypt(input, output, password))
    {
        throw std::runtime_error("failed tp decrypt");
    }
    return output;
}






}
