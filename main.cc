#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "hashTable.h"
#include "person.h"
using namespace std;

int main() {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    hashTable ht;

    try {
        while ( std::cin >> cmd ) {
            if (cmd == "help") {
                cout << "add [person name] [person age] : adds a new person to the hash table." << endl;
                cout << "delete [person name] : removes a person from the hash table." << endl;
                cout << "lookup [person name] : does a lookup in the hash table for a person with the given name." << endl;
                cout << "print : prints the current state of the hash table." << endl;
            } else if (cmd == "add") {
                string name;
                int age;
                cin >> name; 
                cin >> age;
                Person * tmp = new Person{name, age};
                ht.hash_table_insert(tmp);
            } else if (cmd == "delete") {
                string name;
                cin >> name;
                Person * temp = ht.hash_table_delete(name);
                delete temp;
            } else if (cmd == "lookup") {
                string name;
                cin >> name;
                ht.hash_table_lookup(name);
                Person * search = ht.hash_table_lookup(name);
                if (search != nullptr) {
                    cout << *search << endl;
                } else {
                    cout << "Person not found." << endl;
                }
            } else if (cmd == "print") {
                ht.print();
            } else if (cmd == "quit"){
                break;
            } else {
                cout << "Command not recognized." << endl;
            }
        }
    } catch (ios::failure &) {}  // Any I/O failure quits
    catch (...) {}
    /*
    Person jacob = {"Jacob", 25};
    Person nate = {"Nate", 19};
    Person sara = {"Sara", 23};
    Person edna = {"Edna", 13};
    Person amy = {"Amy", 55};

    ht.hash_table_insert(&jacob);
    ht.hash_table_insert(&nate);
    ht.hash_table_insert(&sara);
    ht.hash_table_insert(&edna);
    ht.hash_table_insert(&amy);
    
    ht.print();
    

    
    ht.hash_table_delete("Jacob");
    ht.print();

    printf("Jacob => %u\n", hash_func("Jacob"));
    printf("Nate => %u\n", hash_func("Nate"));
    printf("Sara => %u\n", hash_func("Sara"));
    printf("Tim => %u\n", hash_func("Tim"));
    printf("Amy => %u\n", hash_func("Amy"));
    printf("Ron => %u\n", hash_func("Ron"));
    */
}