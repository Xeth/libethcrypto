#include "PubKeyArchiver.hpp"


namespace BitCrypto{


PubKeyArchiver::PubKeyArchiver()
{
    Secp256k1ContextFactory factory;
    _context = factory.create();
}


PubKeyArchiver::PubKeyArchiver(const Secp256k1ContextPtr &context) : 
    _context(context)
{}


CompressedPoint PubKeyArchiver::compress(const PubKey &key)
{
    CompressedPoint point;
    size_t pointSize = point.size();

    if(!secp256k1_ec_pubkey_serialize(_context.get(), point.data(), &pointSize, &key, SECP256K1_EC_COMPRESSED))
    {
        throw std::runtime_error("failed to compress pubkey");
    }

    if(pointSize!=point.size())
    {
        throw std::runtime_error("invalid compressed point");
    }

    return point;
}


PubKey PubKeyArchiver::decompress(const CompressedPoint &point)
{
    PubKey key(_context);

    if(!secp256k1_ec_pubkey_parse(_context.get(), &key, point.data(), point.size()))
    {
        throw std::runtime_error("failed to decompress key");
    }
    return key;
}


PubKey PubKeyArchiver::decompress(const Data &data)
{
    PubKey key(_context);
    if(!secp256k1_ec_pubkey_parse(_context.get(), &key, data.data(), data.size()))
    {
        throw std::runtime_error("failed to decompress key");
    }
    return key;
}

}
