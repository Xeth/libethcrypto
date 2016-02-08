#pragma once 


namespace Ethereum{

class NullCipherParams
{};

class NullParamsGenerator
{
    public:
        NullCipherParams generate() const;
};


template<class Cipher, class ParamsGenerator=NullParamsGenerator>
class CipherFactory
{
    public:
  
        Cipher create() const;
        Cipher create(const Data &iv) const;

        template<class Params>
        Cipher create(const Data &iv, const Params &) const;

    private:
        Cipher create(const Data &iv, const NullCipherParams &) const;

    private:
        ParamsGenerator _paramsGenerator;

};


}

#include "CipherFactory.ipp"
