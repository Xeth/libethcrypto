#include "ethkey/cipher/CipherAdapter.hpp"


namespace Ethereum{


CipherAdapter::~CipherAdapter()
{
    delete _handle;
}


CipherAdapter::CipherHolder::~CipherHolder()
{}


}
