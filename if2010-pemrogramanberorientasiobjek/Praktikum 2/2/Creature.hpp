#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>

using namespace std;

class Creature {
   protected:
    string name;
    int baseHealth;

   public:
    Creature(string name) : name(name) {
        baseHealth = 100;
        cout << "A creature has been born!" << endl;
    }

    virtual void speak() const {
        cout << "I am a mystical creature named " << name << "!" << endl;
    }

    void wound() { baseHealth -= 10; }

    void print() { cout << "Base Health: " << baseHealth << endl; }
};

#endif