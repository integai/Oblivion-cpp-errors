#include "adresses/private_key_gen.h"
#include "adresses/pub_adress_isValid.h"
#include "adresses/pub_adress_generate.h"
#include "transaction.h"
#include <fstream>
#include "wallet.h"
#include <stdexcept>

class Wallet {
public:
    Wallet() {
        loadPrivateKey();
        address = generateWalletAddress(private_key);
        while (!validateAddress(address)) {
            generatePrivateKey();
            address = generateWalletAddress(private_key);
        }
    }

    std::string getAddress() const {
        return address;
    }

    void createTransaction(const std::string& receiver, int amount, Blockchain* blockchain) {
        Transaction transaction(address, receiver, amount, blockchain);
        std::string transactionHash = transaction.getTransactionHash();
    }

    void signTransaction(Transaction& transaction) {
        transaction.signTransaction(private_key);
    }

    void sendTransaction(Transaction& transaction) {
        if (transaction.isValid()) {
            transaction.send();
        } else {
            throw std::runtime_error("Invalid transaction or blockchain");
        }
    }

    int checkBalance(Blockchain* blockchain) {
        return blockchain->getBalance(address);
    }

private:
    std::string address;
    std::string private_key;

    void generatePrivateKey() {
        try {
            PrivateKeyGenerator private_key_generator;
            private_key = private_key_generator.generate();
            savePrivateKey();
        } catch (const std::exception& e) {
            throw std::runtime_error("Error generating private key: " + std::string(e.what()));
        }
    }

    void loadPrivateKey() {
        std::ifstream key_file("private_key.txt");
        if (key_file.is_open()) {
            std::getline(key_file, private_key);
            key_file.close();
        } else {
            generatePrivateKey();
        }
    }

    void savePrivateKey() {
        std::ofstream key_file("private_key.txt");
        if (key_file.is_open()) {
            key_file << private_key;
            key_file.close();
        } else {
            throw std::runtime_error("Unable to open file to save private key");
        }
    }
};

