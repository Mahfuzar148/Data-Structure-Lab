
#include <iostream>
#include <vector>
using namespace std;

void insertLinearProbing(vector<int>& table, int size, int data) {
    int index = data % size;
    int originalIndex = index;

    while (table[index] != -1) {
        index = (index + 1) % size;  // Linear Probing
        if (index == originalIndex) {
            std::cout << "Hash table is full. Cannot insert " << data << "." << std::endl;
            return;
        }
    }

    table[index] = data;
}

int searchLinearProbing(const std::vector<int>& table, int size, int data) {
    int index = data % size;
    int originalIndex = index;

    while (table[index] != data) {
        index = (index + 1) % size;  // Linear Probing
        if (table[index] == -1 || index == originalIndex) {
            std::cout << data << " not found in the hash table." << std::endl;
            return -1;
        }
    }

    std::cout << data << " found at index " << index << " in the hash table." << std::endl;
    return index;
}

void insertQuadraticProbing(std::vector<int>& table, int size, int data) {
    int index = data % size;
    int originalIndex = index;
    int probe = 1;

    while (table[index] != -1) {
        index = (originalIndex + probe * probe) % size;  // Quadratic Probing
        probe++;
        if (index == originalIndex) {
            std::cout << "Hash table is full. Cannot insert " << data << "." << std::endl;
            return;
        }
    }

    table[index] = data;
}

int searchQuadraticProbing(const std::vector<int>& table, int size, int data) {
    int index = data % size;
    int originalIndex = index;
    int probe = 1;

    while (table[index] != data) {
        index = (originalIndex + probe * probe) % size;  // Quadratic Probing
        probe++;
        if (table[index] == -1 || index == originalIndex) {
            std::cout << data << " not found in the hash table." << std::endl;
            return -1;
        }
    }

    std::cout << data << " found at index " << index << " in the hash table." << std::endl;
    return index;
}

void insertChaining(std::vector<std::vector<int>>& table, int size, int data) {
    int index = data % size;
    table[index].push_back(data);
}

int searchChaining(const std::vector<std::vector<int>>& table, int size, int data) {
    int index = data % size;
    const std::vector<int>& chain = table[index];

    for (int item : chain) {
        if (item == data) {
            std::cout << data << " found in the hash table." << std::endl;
            return index;
        }
    }

    std::cout << data << " not found in the hash table." << std::endl;
    return -1;
}

int main() {
    const int tableSize = 11;  // Size of hash table is a prime number (11)

    std::vector<int> linearProbingTable(tableSize, -1);
    std::vector<int> quadraticProbingTable(tableSize, -1);
    std::vector<std::vector<int>> chainingTable(tableSize);

    // Inserting data into the hash tables
    insertLinearProbing(linearProbingTable, tableSize, 54);
    insertLinearProbing(linearProbingTable, tableSize, 26);
    insertLinearProbing(linearProbingTable, tableSize, 93);
    insertLinearProbing(linearProbingTable, tableSize, 17);
    insertLinearProbing(linearProbingTable, tableSize, 77);
    insertLinearProbing(linearProbingTable, tableSize, 31);
    insertLinearProbing(linearProbingTable, tableSize, 44);
    insertLinearProbing(linearProbingTable, tableSize, 55);
    insertLinearProbing(linearProbingTable, tableSize, 20);

    insertQuadraticProbing(quadraticProbingTable, tableSize, 54);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 26);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 93);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 17);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 77);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 31);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 44);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 55);
    insertQuadraticProbing(quadraticProbingTable, tableSize, 20);

    insertChaining(chainingTable, tableSize, 54);
    insertChaining(chainingTable, tableSize, 26);
    insertChaining(chainingTable, tableSize, 93);
    insertChaining(chainingTable, tableSize, 17);
    insertChaining(chainingTable, tableSize, 77);
    insertChaining(chainingTable, tableSize, 31);
    insertChaining(chainingTable, tableSize, 44);
    insertChaining(chainingTable, tableSize, 55);
    insertChaining(chainingTable, tableSize, 20);

    // Searching for an item in the hash tables
    searchLinearProbing(linearProbingTable, tableSize, 44);
    searchQuadraticProbing(quadraticProbingTable, tableSize, 44);
    searchChaining(chainingTable, tableSize, 44);

    return 0;
}
