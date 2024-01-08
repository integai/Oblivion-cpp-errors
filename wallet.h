#ifndef WALLET_H
#define WALLET_H

#include "transaction.h"
#include "blockchain.h"
#include <string>

class Wallet {
public:
    Wallet();
    std::string getAddress() const;
    void createTransaction(const std::string& receiver, int amount, Blockchain* blockchain);
    void signTransaction(Transaction& transaction);
    void sendTransaction(Transaction& transaction);
    int checkBalance(Blockchain* blockchain);

private:
    std::string address;
    std::string private_key;
    void generatePrivateKey();
    void loadPrivateKey();
    void savePrivateKey();
};

#endif
