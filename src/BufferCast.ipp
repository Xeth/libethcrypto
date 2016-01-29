namespace Ethereum{


template<class Data>
unsigned char * BufferCast(Data &data)
{
    return reinterpret_cast<unsigned char *>(&*data.begin());
}


template<class Data>
const unsigned char * BufferCast(const Data &data)
{
    return reinterpret_cast<const unsigned char *>(&*data.begin());
}


inline unsigned char * BufferCast(Data &data)
{
    return &data;
}


inline const unsigned char * BufferCast(const Data &data)
{
    return &data;
}


}
