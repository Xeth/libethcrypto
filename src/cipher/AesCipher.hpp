#pragma once 

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

#include "AesKey.hpp"
#include "../BufferCast.hpp"

namespace Ethereum{


using namespace CryptoPP;


class AesCipher
{
    public:
        typedef AesKey Key;


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
        Data decrypt(const Input &, const AesKey &);

    private:
        template<class Handler, class Input, class Output>
        bool execute(Handler &, const Input &input, Output &output, const AesKey &key);
};



}

#include "AesCipher.ipp"
