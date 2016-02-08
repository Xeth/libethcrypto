namespace Ethereum{

inline NullCipherParams NullParamsGenerator::generate() const
{
    return NullCipherParams();
}


template<class Cipher, class ParamsGenerator>
Cipher CipherFactory<Cipher, ParamsGenerator>::create() const
{
    return create(MakeRandomIV(), _paramsGenerator.generate());
}


template<class Cipher, class ParamsGenerator>
Cipher CipherFactory<Cipher, ParamsGenerator>::create(const Data &iv) const
{
    return create(iv, _paramsGenerator.generate());
}


template<class Cipher, class ParamsGenerator>
template<class Params>
Cipher CipherFactory<Cipher, ParamsGenerator>::create(const Data &iv, const Params &params) const
{
    return Cipher(iv, params);
}



template<class Cipher, class ParamsGenerator>
Cipher CipherFactory<Cipher, ParamsGenerator>::create(const Data &iv, const NullCipherParams &) const
{
    return Cipher(iv);
}


}
