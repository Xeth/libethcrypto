namespace Ethereum{

template<class Data>
BufferAdapter<Data>::BufferAdapter(Data &data) :
    _data(data)
{}


template<class Data>
void BufferAdapter<Data>::assign(unsigned char value, size_t size)
{
    _data.assign(size, value);
}


template<class Data>
void BufferAdapter<Data>::trim(size_t size)
{
    _data.erase(_data.begin(), _data.begin()+size);
}


template<class Data>
void BufferAdapter<Data>::resize(size_t size)
{
    _data.resize(size);
}


template<class T, size_t capacity>
BufferAdapter<boost::array<T, capacity> >::BufferAdapter(boost::array<T, capacity> &data) :
    _data(data)
{}


template<class T, size_t capacity>
void BufferAdapter<boost::array<T, capacity> >::assign(unsigned char value, size_t size)
{
    checkSize(size);
    std::fill_n(_data.begin(),size, value);
}

template<class T, size_t capacity>
void BufferAdapter<boost::array<T, capacity> >::checkSize( size_t size)
{
    if(size > capacity)
    {
        std::stringstream stream;
        stream<<"container overflow, capacity="<<capacity<<" required size "<<size;
        throw std::runtime_error(stream.str());
    }
}


template<class T, size_t capacity>
void BufferAdapter<boost::array<T, capacity> >::trim(size_t)
{}

template<class T, size_t capacity>
void BufferAdapter<boost::array<T, capacity> >::resize(size_t size)
{
    checkSize(size);
}

template<class T, size_t size>
BufferAdapter<boost::array<T, size> > MakeBufferAdapter(boost::array<T, size> &data)
{
    return BufferAdapter<boost::array<T, size> >(data);
}

template<class Data>
BufferAdapter<Data> MakeBufferAdapter(Data &data)
{
    return BufferAdapter<Data>(data);
}


template<class Data>
void Trim(Data &data, size_t size)
{
    Trim(MakeBufferAdapter(data), size);
}

template<class Data>
void Fill(Data &data, unsigned char c, size_t size)
{
    Fill(MakeBufferAdapter(data), size, c);
}


template<class Data>
void Resize(Data &data, size_t size)
{
    Resize(MakeBufferAdapter(data), size);
}


template<class Data>
void Trim(BufferAdapter<Data> adapter, size_t size)
{
    adapter.trim(size);
}

template<class Data>
void Fill(BufferAdapter<Data> adapter, unsigned char c, size_t size)
{
    adapter.assign(size, c);
}

template<class Data>
void Resize(BufferAdapter<Data> adapter, size_t size)
{
    adapter.resize(size);
}


}
