
namespace Ethereum{

inline LazySecp256k1Handler::LazySecp256k1Handler()
{}

inline LazySecp256k1Handler::LazySecp256k1Handler(const Secp256k1ContextPtr &context) :
    _context(context)
{}


inline Secp256k1ContextPtr & LazySecp256k1Handler::getContext() const
{
    if(!_context)
    {
        Secp256k1ContextFactory factory;
        _context = factory.create();
    }
    return _context;
}





}
