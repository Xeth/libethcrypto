#include "bitcrypto/CipherAdapter.hpp"


namespace BitCrypto{


CipherAdapter::~CipherAdapter()
{
    delete _handle;
}


CipherAdapter::CipherHolder::~CipherHolder()
{}


}
