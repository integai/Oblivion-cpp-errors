#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Block.h"
#include "Blockchain.h"

class Transaction {
public:
    Transaction(std::string sender, std::string receiver, int amount, Blockchain* blockchain);
    std::string getTransactionHash() const;
    bool isValid() const;
    void signTransaction(const std::string &privateKey);
    bool isSigned() const;
    void send();
    std::string senderKey;
    std::string receiverKey;
    int amount;
    std::string transactionHash;
    Blockchain* blockchain;
    std::string signature;
};

#endif

