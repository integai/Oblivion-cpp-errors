#include "../crypto/sha256.h"
#include <string>

bool validateAddress(const std::string& address) {
    std::string prefix = "oblivion";
    if (address.substr(0, prefix.size()) != prefix) {
        return false;
    }
    std::string hashPart = address.substr(prefix.size());
    std::string regeneratedHash = generateSHA256(prefix + hashPart);
    return regeneratedHash == address;
}
