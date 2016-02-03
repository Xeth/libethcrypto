#pragma once 

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

#include "ScryptParams.hpp"
#include "DerivedKeyFactory.hpp"
#include "../BufferCast.hpp"

namespace Ethereum{


using namespace CryptoPP;

Data MakeRandomIV();


class AesCipher
{

    public:

        AesCipher(const Data &iv, const ScryptParams &scrypt);

        const ScryptParams & getParams() const;
        const Data & getIV() const;

        template<class Input, class Output>
        bool encrypt(const Input &input, Output &output,  const std::string &password);


        template<class Input, class Output>
        bool decrypt(const Input &input, Output &output, const std::string &password);


        template<class Output, class Input>
        Output encrypt(const Input &input, const std::string &password);


        template<class Output, class Input>
        Output decrypt(const Input &input, const std::string &password);

        template<class Input>
        Data encrypt(const Input &, const std::string &);

        template<class Input>
        Data decrypt(const Input &, const std::string &);



    private:
        template<class Handler, class Input, class Output>
        bool execute(Handler &, const Input &input, Output &output, const std::string &password);

    private:
        Data _iv;
        ScryptParams _params;

};



}

#include "AesCipher.ipp"
