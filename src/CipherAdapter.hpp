#pragma once 

#include "AesCipher.hpp"


namespace Stealth{


class CipherAdapter
{
    public:
        CipherAdapter(const std::string &);

        template<class Key>
        CipherAdapter(const Key &);

        ~CipherAdapter();

        template<class Input, class Output, class Key>
        bool encrypt(const Input &in, Output &out, const Key &) const;

        template<class Output, class Input, class Key>
        Output encrypt(const Input &in, const Key &) const;

        template<class Input, class Output, class Key>
        bool decrypt(const Input &in, Output &out, const Key &) const;

        template<class Output, class Input, class Key>
        Output decrypt(const Input &in, const Key &) const;

        

    private:
        class CipherHolder;
        template<class Cipher> class CipherHolderImpl;

    private:
        CipherHolder *_handle;
};


}

#include "CipherAdapter.ipp"
