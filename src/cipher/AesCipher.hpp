#pragma once 

#include <openssl/aes.h>


namespace Ethereum{


class AesKey
{
    public:
        AesKey(const std::string &password);
        AesKey(const std::string &password, const std::string &iv);

        const unsigned char *getPassword() const;
        const unsigned char *getIV() const;

    private:
        std::string _password;
        std::string _iv;
};



class AesCipher
{
    public:

        template<class Input, class Output>
        bool encrypt(const Input &input, Output &output,  const AesKey &key);


        template<class Input, class Output>
        bool decrypt(const Input &input, Output &output, const AesKey &key);


        template<class Output, class Input>
        Output encrypt(const Input &input, const AesKey &key);


        template<class Output, class Input>
        Output decrypt(const Input &input, const AesKey &key);

        template<class Input>
        Data encrypt(const Input &, const AesKey &);

        template<class Input>
        Data decrypt(const Input &);

    private:
        template<class Input, class Output>
        bool execute(const Input &input, Output &output, const AesKey &key, int encrypt);
};



}

#include "AesCipher.ipp"
