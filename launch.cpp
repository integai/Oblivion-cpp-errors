#include "blockchain.h"
#include "transaction.h"
#include "utils/isTransactionValid.h"
#include <iostream>
#include "block.h"
#include "utils/isBlockValid.h"
using namespace std;

void test_blockchain_creation() {

    Blockchain myBlockchain;
    Block genesisBlock = myBlockchain.createGenesisBlock();
    myBlockchain.addBlock(genesisBlock);
    cout << "Genesis block created and added to blockchain. Hash: " << genesisBlock.GetHash() << endl;

    Block newBlock = Block("Block data", genesisBlock.GetHash());
    myBlockchain.addBlock(newBlock);
    cout << "New block created and added to blockchain. Hash: " << newBlock.GetHash() << endl;
    cout << "Previous Hash: " << newBlock.GetPrevHash() << endl;

    bool isValid = isBlockValid(newBlock, myBlockchain);
    if (isValid) {
        cout << "The new block is valid." << endl;
    } else {
        cout << "The new block is not valid." << endl;
    }
    return;
}

void test_transaction() {
    Blockchain myBlockchain;
    Transaction myTransaction = Transaction("senderKey", "receiverKey", 100, &myBlockchain);
    myTransaction.send();
    cout << "Transaction sent. Transaction hash: " << myTransaction.getTransactionHash() << endl;
    cout << "Sender: " << myTransaction.senderKey << endl;
    cout << "Receiver: " << myTransaction.receiverKey << endl;
    cout << "Amount: " << myTransaction.amount << endl;
    
    bool isTransValid = isTransactionValid(myTransaction);
    if (isTransValid) {
        cout << "The transaction is valid." << endl;
    } else {
        cout << "The transaction is not valid." << endl;
    }
    return;
}
