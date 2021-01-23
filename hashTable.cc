#include "hashTable.h"
#include <iostream>
using namespace std;

hashTable::hashTable() {
    vector<Person *> hash_table;
    hash_table.resize(TABLE_SIZE);
    
    this->hash_table = hash_table;
}

hashTable::~hashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != nullptr) {
            delete hash_table[i];
        }
    }
}

bool hashTable::hash_table_insert(Person * p) {
    if (p == nullptr) return false;
    int index = hash_func(p->name);
    // method for handling collissions: Linear probing
    // if our hash location is populated, keep find the next empty space
    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == nullptr) {
            hash_table[try] = p;
            return true;
        }
    }
    return true;
}

Person * hashTable::hash_table_delete(string name) {
    int index = hash_func(name);

    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] != nullptr && hash_table[try]->name == name) {
            Person * temp = hash_table[try];
            hash_table[try] = nullptr;
            return temp;
        }
    }
    return nullptr;
}

unsigned int hashTable::hash_func(string name){
    int len = name.length();
    unsigned int hash_val = 0;
    for (int i = 0; i < len; i++) {
        hash_val += name[i];
        hash_val *= name[i];
        hash_val %= TABLE_SIZE;
    }
    return hash_val;
}

Person * hashTable::hash_table_lookup(string name) {
    int index = hash_func(name);
    
    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] != nullptr && hash_table[try]->name == name) {
            return hash_table[try];
        }
    }
    return nullptr;
}

void hashTable::print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == nullptr) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            cout << hash_table[i]->name << endl;
        }
    }
}

