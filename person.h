#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <iostream>

using namespace std;

class Person {
    string name;
    int age;
    //
    public:
    Person(string name, int age);
    friend ostream &operator<<(ostream &out, const Person & p);
    friend class hashTable;
};

#endif
