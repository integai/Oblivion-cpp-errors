#include "../block.h"
#include "../blockchain.h"
#include <iostream>

bool isBlockValid(const Block& block, const Blockchain& blockchain) {
    const Block& latestBlock = blockchain.getLatestBlock();

    if (block.GetHash() != block.CalculateHash()) {
        std::cerr << "Block hash is not valid.\n";
        return false;
    }
    //TODO: Fix validation for Genesis Block (Currently disabled)
    /*if (block.GetHash() == blockchain.getGenesisBlock().GetHash()) {
        if (blockchain.IsEmpty()) {
            std::cerr << "Blockchain is empty. Cannot validate block.\n";
            return false;
        }
        return true;
    } else if (latestBlock.GetHash() != block.GetPrevHash()) {
        std::cerr << "Block does not continue from the latest block in the blockchain.\n";
        return false;
    }*/

    return true;
}
