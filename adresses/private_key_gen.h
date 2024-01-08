#ifndef PRIVATE_KEY_GEN_H
#define PRIVATE_KEY_GEN_H

#include <string>

class PrivateKeyGenerator {
public:
    std::string generate();
    std::string generateSignature(const std::string& privateKey, const std::string& transactionHash);
};

#endif
