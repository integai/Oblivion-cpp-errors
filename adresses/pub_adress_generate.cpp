#include "../crypto/sha256.h"
#include <string>
#include <sstream>
#include <iomanip>

std::string generateWalletAddress(const std::string& privateKey) {
    std::string prefix = "oblivion";
    std::string hash = generateSHA256(prefix + privateKey);
    return hash;
}
