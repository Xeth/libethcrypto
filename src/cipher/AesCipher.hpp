#pragma once 

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

#include "ScryptKey.hpp"
#include "DerivedKeyFactory.hpp"
#include "../BufferCast.hpp"

namespace Ethereum{


using namespace CryptoPP;


class AesCipher
{
    public:
        typedef ScryptKey Key;


    public:

        template<class Input, class Output>
        bool encrypt(const Input &input, Output &output,  const Key &key);


        template<class Input, class Output>
        bool decrypt(const Input &input, Output &output, const Key &key);


        template<class Output, class Input>
        Output encrypt(const Input &input, const Key &key);


        template<class Output, class Input>
        Output decrypt(const Input &input, const Key &key);

        template<class Input>
        Data encrypt(const Input &, const Key &);

        template<class Input>
        Data decrypt(const Input &, const Key &);

    private:
        template<class Handler, class Input, class Output>
        bool execute(Handler &, const Input &input, Output &output, const Key &key);
};



}

#include "AesCipher.ipp"
