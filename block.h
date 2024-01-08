#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "transaction.h"

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
    std::string GetExtraData() const;
    std::string GetMemo() const;
    std::string CalculateHash() const;
    std::string GetPrevHash() const;
    const std::vector<Transaction>& GetTransactions() const {
        return transactions;
    }
};

#endif
