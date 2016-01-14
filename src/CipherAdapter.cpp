#include "CipherAdapter.hpp"


namespace Stealth{


CipherAdapter::~CipherAdapter()
{
    delete _handle;
}


CipherAdapter::CipherHolder::~CipherHolder()
{}


}
