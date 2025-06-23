#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key into the hash table using linear probing
void insert(vector<string> &table, int key) {
    int index = hashFunction(key);

    while (table[index] != "") {
        index = (index + 1) % TABLE_SIZE;
    }

    table[index] = to_string(key);
}

// Display the hash table
void display(const vector<string> &table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != "") {
            cout << "Index " << i << ": " << table[i] << endl;
        } else {
            cout << "Index " << i << ": Empty" << endl;
        }
    }
}

int main() {
    vector<string> table(TABLE_SIZE, "");

    insert(table, 12);
    insert(table, 18);
    insert(table, 13);
    insert(table, 2);
    insert(table, 3);
    insert(table, 23);
    insert(table, 5);
    insert(table, 15);

    display(table);

    return 0;
}
