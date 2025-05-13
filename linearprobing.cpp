#include <iostream>
using namespace std;

#define TABLE_SIZE 11
#define EMPTY -1

class LinearProbingHashTable {
private:
    int table[TABLE_SIZE];
    int step; // Step size for probing (slot)

public:
    LinearProbingHashTable(int s) {
        step = s;
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = EMPTY;
    }

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hash(key);
        int originalIndex = index;
        int i = 0;

        while (table[index] != EMPTY && i < TABLE_SIZE) {
            index = (originalIndex + i * step) % TABLE_SIZE;
            i++;
        }

        if (i < TABLE_SIZE)
            table[index] = key;
        else
            cout << "Hash table is full. Couldn't insert key " << key << "\n";
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << " -> ";
            if (table[i] != EMPTY)
                cout << table[i];
            else
                cout << "EMPTY";
            cout << "\n";
        }
    }
};

int main() {
    int stepSize;
    cout << "Enter step size for linear probing (e.g. 2/3/4): ";
    cin >> stepSize;

    LinearProbingHashTable ht(stepSize);

    int keys[] = {27, 18, 29, 28, 39, 13};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; ++i) {
        ht.insert(keys[i]);
    }

    ht.display();

    return 0;
}
