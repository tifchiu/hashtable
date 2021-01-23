#include "person.h"

Person::Person(string name, int age) : name{name}, age{age} {}

ostream &operator<<(ostream &out, const Person & p) {
    out << "Name: " + p.name << endl;
    out << "Age: " + to_string(p.age) << endl;
    return out;
}

