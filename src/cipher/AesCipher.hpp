#pragma once 

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

#include "ScryptParams.hpp"
#include "DerivedKeyFactory.hpp"
#include "CipherMacFactory.hpp"
#include "EncryptedData.hpp"
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

        template<class Input>
        bool encrypt(const Input &input, EncryptedData &output,  const std::string &password);


        template<class Output>
        bool decrypt(const EncryptedData &input, Output &output, const std::string &password);


        template<class Input>
        EncryptedData encrypt(const Input &input, const std::string &password);


        template<class Output>
        Output decrypt(const EncryptedData &input, const std::string &password);

        Data decrypt(const EncryptedData &, const std::string &);



    private:
        template<class Handler, class Input, class Output>
        bool execute(Handler &, const Input &input, Output &output, const Data &derivedKey);

        Data makeDerived(const std::string &password);

    private:
        Data _iv;
        ScryptParams _params;

};



}

#include "AesCipher.ipp"
