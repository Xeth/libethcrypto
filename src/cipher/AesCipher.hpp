#pragma once 

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

#include "ScryptParams.hpp"
#include "ScryptParamsGenerator.hpp"
#include "DerivedKeyFactory.hpp"
#include "CipherMacFactory.hpp"
#include "EncryptedData.hpp"
#include "../BufferCast.hpp"

namespace Ethereum{




template<class KDF>
class AesCipher
{
    public:
        typedef typename KDF::Params KdfParams;

    public:

        AesCipher();
        AesCipher(const Data &iv, const typename KDF::Params &);

        const KdfParams & getParams() const;
        const Data & getIV() const;

        template<class Input>
        bool encrypt(const Input &input, EncryptedData &output,  const std::string &password) const;


        template<class Output>
        bool decrypt(const EncryptedData &input, Output &output, const std::string &password) const;


        template<class Input>
        EncryptedData encrypt(const Input &input, const std::string &password) const;


        template<class Output>
        Output decrypt(const EncryptedData &input, const std::string &password) const;

        Data decrypt(const EncryptedData &, const std::string &) const;

        AesCipher & operator = (const AesCipher &);

    private:
        template<class Handler, class Input, class Output>
        bool execute(Handler &, const Input &input, Output &output, const Data &derivedKey) const;

        Data makeDerived(const std::string &password) const;

    private:
        Data _iv;
        typename KDF::Params _params;

};



}

#include "AesCipher.ipp"
