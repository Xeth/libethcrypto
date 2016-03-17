#pragma once 

#include <boost/array.hpp>

#include "PublicKey.hpp"
#include "encoding/HexEncoder.hpp"


namespace Ethereum{



class Address : public boost::array<unsigned char, 20>
{
    public:

        Address();
        Address(const PublicKey &);
        Address(const char *, size_t );
        Address(const std::string &);

        std::string toString() const;
        operator std::string () const;

        boost::array<unsigned char, 20> & toArray();
        const boost::array<unsigned char, 20> & toArray()  const;

};


}
