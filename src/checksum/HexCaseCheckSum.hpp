#pragma once

#include <cctype>
#include <string>
#include <algorithm>
#include <stdexcept>

#include "../hash/Keccak256.hpp"
#include "../hash/Sha256.hpp"


namespace Ethereum{


class HexCaseCheckSum
{
    public:
        std::string compute(const std::string &hex) const;
        bool validate(const std::string &hex) const;

    private:
        inline Data hash(const std::string &) const;
        inline std::string toLowerCase(const std::string &) const;
        inline bool checkAddressLen(const std::string &) const;
};


}
