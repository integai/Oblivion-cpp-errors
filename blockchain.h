#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <ctime>
#include <string>
#include "block.h"


class Blockchain {
public:
    Blockchain();
    int difficulty;
    std::vector<Block> chain;

    Block createGenesisBlock();
    Block getLatestBlock() const;
    bool isChainValid() const;
    void addBlock(Block &newBlock);
    void MineBlock(Block &newBlock, int difficulty);
    bool IsEmpty() const;
    Block getGenesisBlock() const;
    double getBalance(const std::string& address) const; // New function to check wallet balance
};

#endif
