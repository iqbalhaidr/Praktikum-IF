#include "FirePokemon.hpp"

#include <iostream>

using namespace std;

FirePokemon::FirePokemon(string name) : Pokemon(name, "fire"), attackCount(0) {
    cout << name << " is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | attack count: " << attackCount << endl;
}

FirePokemon::FirePokemon(string name, int hp, int att)
    : Pokemon(name, "fire", hp, att), attackCount(0) {
    cout << name << " is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | attack count: " << attackCount << endl;
}

FirePokemon::FirePokemon(const FirePokemon &fp)
    : Pokemon(fp), attackCount(fp.attackCount) {
    cout << name << " (copy) is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | attack count: " << attackCount << endl;
}

FirePokemon &FirePokemon::operator=(const FirePokemon &a) {
    name = a.name;
    type = a.type;
    hp = a.hp;
    att = a.att;
    attackCount = a.attackCount;

    cout << name << " is assigned with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | attack count: " << attackCount << endl;

    return *this;
}

void FirePokemon::attack(Pokemon &target) {
    int damage = att;
    bool isEffective = false;

    if (target.getType() == "grass") {
        damage *= 2;
        isEffective = true;
    }

    // Every 2 attacks, add +20
    if (++attackCount % 2 == 0) {
        damage += 20;
    }

    cout << name << " used Flamethrower on " << target.getName() << " for "
         << damage << " damage"
         << (isEffective ? " and it's super effective!" : "") << endl;

    target.takeDamage(damage);
}