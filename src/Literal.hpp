#pragma once 

#include "serialization/HashSerializer.hpp"
#include "serialization/PublicKeySerializer.hpp"
#include "serialization/PrivateKeySerializer.hpp"
#include "serialization/SignatureSerializer.hpp"

#include "encoding/HexEncoder.hpp"

namespace Ethereum{

//hash

template<class Data>
Data Literal(const std::string &);

std::string Literal(const Data &);


//private key

std::string Literal(const PrivateKey &);


template<>
PrivateKey Literal<PrivateKey>(const std::string &);


//public key

std::string Literal(const PublicKey &);

template<>
PublicKey Literal<PublicKey>(const std::string &);

std::string Literal(const UncompressedPoint &);
std::string Literal(const CompressedPoint &);

template<>
UncompressedPoint Literal<UncompressedPoint>(const std::string &);

template<>
CompressedPoint Literal<CompressedPoint>(const std::string &);


//signature

std::string Literal(const Signature &);

template<>
Signature Literal<Signature>(const std::string &);




}

#include "Literal.ipp"
