#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "Creature.hpp"

class Dragon : public Creature {
   private:
    int additionalHealth;

   public:
    Dragon(string name) : Creature(name) {
        additionalHealth = 100;
        cout << "A dragon has been born!" << endl;
    }

    void speak() const {
        cout << "I am the mighty dragon " << name << "! Beware of my flames!"
             << endl;
    }

    void wound() { additionalHealth -= 10; }

    void print() {
        cout << "Base Health: " << baseHealth
             << "; Additional Health: " << additionalHealth << endl;
    }
};

#endif