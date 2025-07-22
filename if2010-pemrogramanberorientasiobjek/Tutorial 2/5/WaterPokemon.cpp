#include "WaterPokemon.hpp"

#include <iostream>

using namespace std;

WaterPokemon::WaterPokemon(string name)
    : Pokemon(name, "water"), attackBoost(0) {
    cout << name << " is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | attack boost: " << attackBoost << endl;
}

WaterPokemon::WaterPokemon(string name, int hp, int att, int attackBoost)
    : Pokemon(name, "water", hp, att), attackBoost(attackBoost) {
    cout << name << " is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | attack boost: " << attackBoost << endl;
}

WaterPokemon::WaterPokemon(const WaterPokemon &fp)
    : Pokemon(fp), attackBoost(fp.attackBoost) {
    cout << name << " (copy) is born with with type: " << type
         << " | HP: " << hp << " | ATT: " << att
         << " | attack boost: " << attackBoost << endl;
}

WaterPokemon &WaterPokemon::operator=(const WaterPokemon &a) {
    name = a.name;
    type = a.type;
    hp = a.hp;
    att = a.att;
    attackBoost = a.attackBoost;

    cout << name << " is assigned with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | attack boost: " << attackBoost << endl;

    return *this;
}

void WaterPokemon::attack(Pokemon &target) {
    int damage = att;
    if (target.getType() == "fire") {
        damage *= 2;
    }

    cout << name << " used Water Gun on " << target.getName() << " for "
         << damage << " damage"
         << (damage != att ? " and it's super effective!" : "") << endl;

    target.takeDamage(damage);

    if (attackBoost != 0) {
        att += attackBoost;
        cout << name << "'s Flow State increases! Current damage: " << att
             << endl;
    }
}