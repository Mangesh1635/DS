#include <iostream>
#include <vector>
#include <cmath>
#define EMPTY -1
using namespace std;

class CuckooHash {
private:
    vector<int> table1, table2;
    int size;
    int max_kicks;

    // Hash functions
    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return (key / size) % size;
    }

public:
    CuckooHash(int s) {
        size = s;
        table1.resize(size, EMPTY);
        table2.resize(size, EMPTY);
        max_kicks = size; // Prevent infinite loops
    }

    // Insert a key using cuckoo hashing
    bool insert(int key) {
        int pos, temp;
        for (int i = 0; i < max_kicks; ++i) {
            pos = hash1(key);
            if (table1[pos] == EMPTY) {
                table1[pos] = key;
                return true;
            }
            swap(key, table1[pos]);

            pos = hash2(key);
            if (table2[pos] == EMPTY) {
                table2[pos] = key;
                return true;
            }
            swap(key, table2[pos]);
        }

        cout << "Rehash needed for key: " << key << "\n";
        return false;
    }

    // Display both hash tables
    void display() {
        cout << "Table 1:\n";
        for (int i = 0; i < size; ++i) {
            cout << "[" << i << "]: " << (table1[i] == EMPTY ? "EMPTY" : to_string(table1[i])) << "\n";
        }

        cout << "\nTable 2:\n";
        for (int i = 0; i < size; ++i) {
            cout << "[" << i << "]: " << (table2[i] == EMPTY ? "EMPTY" : to_string(table2[i])) << "\n";
        }
    }
};

int main() {
    CuckooHash hashTable(7); // Size of each table

    int arr[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
int n = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < n; i++) {
    hashTable.insert(arr[i]);
}

    hashTable.display();

    return 0;
}
