#include "transaction.h"
#include "adresses/private_key_gen.h"
#include "crypto/sha256.h"
using namespace std;

Transaction::Transaction(string sender, string receiver, int amount, Blockchain* blockchain) {
    this->senderKey = sender;
    this->receiverKey = receiver;
    this->amount = amount;
    this->blockchain = blockchain;
    Block tempBlock = Block(sender, receiver, to_string(amount));
    this->transactionHash = tempBlock.CalculateHash();
}

string Transaction::getTransactionHash() const {
    return this->transactionHash;
}

bool Transaction::isValid() const {
    return this->senderKey != this->receiverKey && this->blockchain->isChainValid();
}

void Transaction::signTransaction(const std::string& privateKey) {
    PrivateKeyGenerator keyGenerator;
    std::string transactionData = this->senderKey + this->receiverKey + std::to_string(this->amount);
    this->transactionHash = generateSHA256(transactionData);
    this->signature = keyGenerator.generateSignature(privateKey, this->transactionHash);
}

bool Transaction::isSigned() const {
    return !this->signature.empty();
}

void Transaction::send() {
    if (this->isValid()) {
        Block newBlock = Block(this->senderKey, this->receiverKey, std::to_string(this->amount));
        this->blockchain->addBlock(newBlock);
    } else {
        throw std::invalid_argument("Invalid transaction or blockchain");
    }
}
