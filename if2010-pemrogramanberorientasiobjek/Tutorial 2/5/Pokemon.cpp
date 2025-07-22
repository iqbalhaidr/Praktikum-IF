#include "Pokemon.hpp"

#include <iostream>

using namespace std;

Pokemon::Pokemon(string name, string type) : Pokemon(name, type, 100, 20) {}

Pokemon::Pokemon(string name, string type, int hp, int att)
    : name(name), type(type), hp(hp), att(att) {
    cout << name << " is born" << endl;
}

Pokemon::Pokemon(const Pokemon &p)
    : name(p.name), type(p.type), hp(p.hp), att(p.att) {
    cout << name << " is copied" << endl;
}

Pokemon::~Pokemon() { cout << name << " has run away" << endl; }

string Pokemon::getName() const { return name; }

string Pokemon::getType() const { return type; }

void Pokemon::heal(int x) {
    this->hp += x;
    cout << name << " heals " << x << " points | HP: " << hp << endl;
}

void Pokemon::takeDamage(int damage) {
    hp -= damage;
    bool isDead = hp <= 0;
    cout << name << " took " << damage << " damage and now has "
         << (isDead ? 0 : hp) << " HP" << endl;

    if (isDead) {
        hp = 0;
        cout << name << " has fainted" << endl;
    }
}

void Pokemon::attack(Pokemon &target) {
    cout << name << " attacks " << target.getName() << " for " << att
         << " damage" << endl;
}