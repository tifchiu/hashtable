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
    // has duplicate value;
    if (hash_table[index] != nullptr) {
        return false;
    }
    hash_table[index] = p;
    return true;
}

Person * hashTable::hash_table_delete(string name) {
    int index = hash_func(name);
    if (hash_table[index] != nullptr) {
        Person * tmp = hash_table[index];
        hash_table[index] = nullptr;
        return tmp;
    } else {
        return nullptr;
    }
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
    if (hash_table[index] != nullptr && name == hash_table[index]->name) {
        return hash_table[index];
    } else {
        return nullptr;
    }
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

