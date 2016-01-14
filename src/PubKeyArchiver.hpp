#pragma once 


#include "CompressedPoint.hpp"
#include "PubKey.hpp"
#include "Data.hpp"
#include "Secp256k1ContextPtr.hpp"


namespace BitCrypto{


class PubKeyArchiver 
{
    public:
        PubKeyArchiver();
        PubKeyArchiver(const Secp256k1ContextPtr &);

        CompressedPoint compress(const PubKey &);
        PubKey decompress(const CompressedPoint &);
        PubKey decompress(const Data &);


    private:
        Secp256k1ContextPtr _context;
};



}
