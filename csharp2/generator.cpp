#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void printTest(int test) {
    if (test == 0) {
        cout << "4\n";
        cout << "Life 1001 2024-04-01 5000\n";
        cout << "Health 1002 2024-04-05 3000\n";
        cout << "Auto 1003 2024-04-10 7000\n";
        cout << "Home 1004 2024-04-15 10000\n";
        cout << "1001\n";
    } else if (test == 1) {
        cout << "3\n";
        cout << "Life 1001 2024-06-01 7000\n";
        cout << "Auto 1002 2024-06-05 9500\n";
        cout << "Health 1003 2024-06-10 5500\n";
        cout << "1001\n";
    } else if (test == 2) {
        cout << "5\n";
        cout << "Life 1001 2024-04-01 5000\n";
        cout << "Health 1002 2024-04-05 3000\n";
        cout << "Auto 1003 2024-04-10 7000\n";
        cout << "Home 1004 2024-04-15 10000\n";
        cout << "Life 1005 2024-04-20 2000\n";
        cout << "1003\n";
    } else if (test >= 3 && test <= 8) {
        int numEntries = 5 + (test - 3); // Varying number of entries
        vector<string> policyTypes = {"Life", "Health", "Auto", "Home", "Travel", "Pet", "Business", "Property"};

        cout << numEntries << "\n";
        for (int i = 0; i < numEntries; ++i) {
            string policyType = policyTypes[i % policyTypes.size()];
            int claimID = 1000 + (i + 1);
            char date[11];
            snprintf(date, sizeof(date), "2024-%02d-%02d", (i % 12) +1, (i % 28)+1);
            int amount = (i + 1) * 2000;

            cout << policyType << " " << claimID << " " << date << " " << amount << "\n";
        }
        cout << 1000 + test << "\n"; // ClaimID to remove a claim
    } else if (test >= 9) {
        // Generate random test case with 100 entries
        int numOfEntries = 100;
        cout << numOfEntries << "\n";
        vector<string> policyTypes = {
            "Life", "Health", "Auto", "Home", "Travel", "Pet", "Business", "Property"
        };
        //int to_remove;
        vector<int>claim_ids;
        for(int i=0;i<numOfEntries;i++){
            claim_ids.push_back(rnd.next(1000,1000000));
        }
        shuffle(claim_ids.begin(),claim_ids.end());
        for (int i = 0; i < numOfEntries; ++i) {
            string policyType = policyTypes[rnd.next(policyTypes.size())];
            int claimID = claim_ids[i];
            char date[11];
            snprintf(date, sizeof(date), "2024-%02d-%02d", rnd.next(1, 12), rnd.next(1, 29));
            int amount = rnd.next(2000, 10001) * 100; // Amount between 2000 and 10000

            cout << policyType << " " << claimID << " " << date << " " << amount << "\n";
        }
        int to_remove = rnd.next(0,numOfEntries-1);
        cout << claim_ids[to_remove] << "\n"; // ClaimID to remove a claim
    }
}

void writeTest(int test) {
    startTest(test);
    printTest(test);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int tests = atoi(argv[1]);
    for (int i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}
