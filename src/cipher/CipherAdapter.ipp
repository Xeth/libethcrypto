
namespace BitCrypto{

class CipherAdapter::CipherHolder
{
    public:
        virtual ~CipherHolder();
        virtual bool encrypt(const Data &in, Data &out, const void *) = 0;
        virtual bool decrypt(const Data &in, Data &out, const void *) = 0;
        virtual Data encrypt(const Data &in, const void *) = 0;
        virtual Data decrypt(const Data &in, const void *) = 0;


        virtual bool encrypt(const Secret &in, Data &out, const void *) = 0;
        virtual bool decrypt(const Data &in, Secret &out, const void *) = 0;
        virtual Data encrypt(const Secret &in, const void *) = 0;

};

template<class Cipher>
class CipherAdapter::CipherHolderImpl : public CipherAdapter::CipherHolder
{
    public:
        CipherHolderImpl(const Cipher &);
        bool encrypt(const Data &in, Data &out, const void *);
        bool decrypt(const Data &in, Data &out, const void *);
        Data encrypt(const Data &in, const void *);
        Data decrypt(const Data &in, const void *);

        bool encrypt(const Secret &in, Data &out, const void *);
        bool decrypt(const Data &in, Secret &out, const void *);
        Data encrypt(const Secret &in, const void *);

    private:
        Cipher _cipher;
};

template<class Cipher>
CipherAdapter::CipherAdapter(const Cipher &cipher) : 
    _handle(new CipherHolderImpl<Cipher>(cipher))
{}


template<class Input, class Output, class Key>
bool CipherAdapter::encrypt(const Input &in, Output &out, const Key &key) const
{
    return _handle->encrypt(in, out, reinterpret_cast<const void *>(&key));
}


template<class Output, class Input, class Key>
Output CipherAdapter::encrypt(const Input &in, const Key &key) const
{
    Output out;
    return _handle->encrypt(in, out, reinterpret_cast<const void *>(&key));
}


template<class Input, class Output, class Key>
bool CipherAdapter::decrypt(const Input &in, Output &out, const Key &key) const
{
    return _handle->decrypt(in, out, reinterpret_cast<const void *>(&key));
}


template<class Output, class Input, class Key>
Output CipherAdapter::decrypt(const Input &in, const Key &key) const
{
    Output out;
    return _handle->decrypt(in, out, reinterpret_cast<const void *>(&key));
}


template<class Cipher>
CipherAdapter::CipherHolderImpl<Cipher>::CipherHolderImpl(const Cipher &cipher) :
    _cipher(cipher)
{}


template<class Cipher>
bool CipherAdapter::CipherHolderImpl<Cipher>::encrypt(const Data &in, Data &out, const void *key)
{
    return _cipher.encrypt(in, out, *reinterpret_cast<const typename Cipher::Key *>(key));
}

template<class Cipher>
bool CipherAdapter::CipherHolderImpl<Cipher>::decrypt(const Data &in, Data &out, const void *key)
{
    return _cipher.decrypt(in, out, *reinterpret_cast<const typename Cipher::Key *>(key));
}

template<class Cipher>
Data CipherAdapter::CipherHolderImpl<Cipher>::encrypt(const Data &in, const void *key)
{
    return _cipher.encrypt(in, *reinterpret_cast<const typename Cipher::Key *>(key));
}

template<class Cipher>
Data CipherAdapter::CipherHolderImpl<Cipher>::decrypt(const Data &in, const void *key)
{
    return _cipher.decrypt(in, *reinterpret_cast<const typename Cipher::Key *>(key));
}

template<class Cipher>
bool CipherAdapter::CipherHolderImpl<Cipher>::encrypt(const Secret &in, Data &out, const void *key)
{
    return _cipher.encrypt(in, out, *reinterpret_cast<const typename Cipher::Key *>(key));
}

template<class Cipher>
bool CipherAdapter::CipherHolderImpl<Cipher>::decrypt(const Data &in, Secret &out, const void *key)
{
    return _cipher.decrypt(in, out, *reinterpret_cast<const typename Cipher::Key *>(key));
}


template<class Cipher>
Data CipherAdapter::CipherHolderImpl<Cipher>::encrypt(const Secret &in, const void *key)
{
    return _cipher.encrypt(in, *reinterpret_cast<const typename Cipher::Key *>(key));
}

}
