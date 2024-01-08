#include "blockchain.h"
#include "transaction.h"
#include "wallet.h"
#include "block.h"
#include <iostream>
using namespace std;

void test_blockchain_creation() {
    Blockchain myBlockchain;
    cout << "Testing blockchain creation..." << endl;
    cout << "Blockchain created. Genesis block hash: " << myBlockchain.getGenesisBlock().GetHash() << endl;
    cout << "Blockchain validity: " << (myBlockchain.isChainValid() ? "Valid" : "Invalid") << endl;
}

void test_block_mining() {
    Blockchain myBlockchain;
    cout << "Testing block mining..." << endl;
    Block newBlock = Block("Block data", myBlockchain.getLatestBlock().GetHash());
    myBlockchain.addBlock(newBlock);
    cout << "New block mined and added to blockchain. Hash: " << newBlock.GetHash() << endl;
    cout << "Blockchain validity: " << (myBlockchain.isChainValid() ? "Valid" : "Invalid") << endl;
}

void test_wallet_functions() {
    Blockchain myBlockchain;
    Wallet myWallet;
    cout << "Testing wallet functions..." << endl;
    cout << "Wallet address: " << myWallet.getAddress() << endl;
    cout << "Initial balance: " << myWallet.checkBalance(&myBlockchain) << endl;
}

void test_transaction_creation() {
    Blockchain myBlockchain;
    Wallet senderWallet, receiverWallet;
    cout << "Testing transaction creation..." << endl;
    senderWallet.createTransaction(receiverWallet.getAddress(), 100, &myBlockchain);
    cout << "Transaction created and sent. Sender balance: " << senderWallet.checkBalance(&myBlockchain) << endl;
}
