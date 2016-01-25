namespace Ethereum{

inline Secp256k1Handler::Secp256k1Handler() : 
    _context(createContext())
{}

inline Secp256k1Handler::Secp256k1Handler(const Secp256k1ContextPtr &context) :
    _context(context?context:createContext())
{}


inline Secp256k1ContextPtr & Secp256k1Handler::getContext() const
{
    return _context;
}


inline Secp256k1ContextPtr Secp256k1Handler::createContext()
{
    Secp256k1ContextFactory factory;
    return factory.create();
}


}
