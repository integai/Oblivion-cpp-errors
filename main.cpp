#include "launch.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Select the test to run (1 - Blockchain, 2 - Transaction): ";
    cin >> choice;
    switch(choice) {
        case 1:
            test_blockchain_creation();
            break;
        case 2:
            test_transaction();
            break;
        default:
            cout << "Invalid choice. Please select either 1 or 2." << endl;
            break;
    }
    return 0;
}

