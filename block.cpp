#include <string>
#include <vector>
#include "crypto/sha256.h"
#include "transaction.h"
#include "block.h"

class Block {
public:
    std::string sPrevHash;
    std::string sHash;
    int nNonce = -1;
    std::string sData;
    std::string sExtraData;
    std::string sMemo;
    std::vector<Transaction> transactions;

    Block(std::string sDataIn, std::string sPrevHashIn, std::string sExtraDataIn = "", std::string sMemoIn = "");

    std::string GetHash() const;
    std::string GetPrevHash() const;
    std::string GetExtraData() const;
    std::string GetMemo() const;
    std::string CalculateHash() const;
    std::vector<Transaction> GetTransactions() const;
};

Block::Block(std::string sDataIn, std::string sPrevHashIn, std::string sExtraDataIn, std::string sMemoIn) {
    this->sData = sDataIn;
    this->sPrevHash = sPrevHashIn;
    this->sExtraData = sExtraDataIn;
    this->sMemo = sMemoIn;
    this->sHash = CalculateHash();
}


std::string Block::CalculateHash() const {
    return generateSHA256(sData + sPrevHash + std::to_string(nNonce) + sExtraData + sMemo); // Added memo to hash calculation
}

std::string Block::GetHash() const {
    return this->sHash; // Return the stored hash instead of calculating it again
}

std::string Block::GetPrevHash() const {
    return this->sPrevHash;
}

std::string Block::GetExtraData() const {
    return this->sExtraData;
}

std::string Block::GetMemo() const {
    return this->sMemo;
}

std::vector<Transaction> Block::GetTransactions() const { // Added a getter for transactions
    return this->transactions;
}
