#include "launch.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Select the test to run (1 - Blockchain, 2 - Transaction, 3 - Wallet, 4 - Block Mining): ";
    cin >> choice;
    switch(choice) {
        case 1:
            test_blockchain_creation();
            break;
        case 2:
            test_transaction_creation();
            break;
        case 3:
            test_wallet_functions();
            break;
        case 4:
            test_block_mining();
            break;
        default:
            cout << "Invalid choice. Please select either 1, 2, 3 or 4." << endl;
            break;
    }
    return 0;
}

