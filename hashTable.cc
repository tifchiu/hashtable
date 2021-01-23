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
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

Person * hashTable::hash_table_delete(string name) {
    int index = hash_func(name);
    Person * head = hash_table[index];
    Person * parent = nullptr;
    while (head != nullptr) {
        if (name == hash_table[index]->name) {
            Person * new_next = hash_table[index]->next;
            parent->next = new_next;
            return hash_table[index];
        } else {
            parent = head;
            head = hash_table[index]->next;
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
    Person * head = hash_table[index];

    while (head != nullptr) {
        if (name == hash_table[index]->name) {
            return hash_table[index];
        } else {
            head = hash_table[index]->next;
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
            cout << hash_table[i]->name;
            Person * temp = hash_table[i]->next;
            while (temp != nullptr) {
                cout << " -> " << temp->name;
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

