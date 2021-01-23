#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <vector>
#include <iostream>
#include "person.h"
using namespace std;

const int TABLE_SIZE = 10;

class hashTable {
    vector<Person *> hash_table;

    public:
    hashTable();
    ~hashTable();
    bool hash_table_insert(Person * p);
    unsigned int hash_func(string name);
    Person * hash_table_lookup(string name);
    Person * hash_table_delete(string name);
    void print();
};

#endif
