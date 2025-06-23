#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;
vector<string> table(TABLE_SIZE, "");

// Primary hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Secondary hash function for step size
int hashFunction2(int key) {
    return 1 + (key % 5);
}

// Insert key using double hashing
void insert(int key) {
    int index = hashFunction(key);
    int step = hashFunction2(key);
    int i = 0;

    while (table[index] != "") {
        i++;
        if (i >= TABLE_SIZE) {
            cerr << "Error: Could not insert key " << key << ". Table might be full or probing failed." << endl;
            return;
        }
        index = (hashFunction(key) + i * step) % TABLE_SIZE;
    }

    table[index] = to_string(key);
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != "") {
            cout << "Index " << i << ": " << table[i] << endl;
        } else {
            cout << "Index " << i << ": Empty" << endl;
        }
    }
}

int main() {
    insert(12);
    insert(18);
    insert(13);
    insert(2);
    insert(3);
    insert(23);
    insert(5);
    insert(15);

    display();

    return 0;
}
