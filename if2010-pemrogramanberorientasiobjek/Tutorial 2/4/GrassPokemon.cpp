#include "GrassPokemon.hpp"

#include <iostream>

using namespace std;

GrassPokemon::GrassPokemon(string name)
    : Pokemon(name, "grass"), regenAmount(0), maxHP(100) {
    cout << name << " is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | regen amount: " << regenAmount
         << " | max HP: " << maxHP << endl;
}

GrassPokemon::GrassPokemon(string name, int hp, int att, int regenAmount)
    : Pokemon(name, "grass", hp, att), regenAmount(regenAmount), maxHP(hp) {
    cout << name << " is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | regen amount: " << regenAmount
         << " | max HP: " << maxHP << endl;
}

GrassPokemon::GrassPokemon(const GrassPokemon &gp)
    : Pokemon(gp), regenAmount(gp.regenAmount), maxHP(gp.maxHP) {
    cout << name << " (copy) is born with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | regen amount: " << regenAmount
         << " | max HP: " << maxHP << endl;
}

GrassPokemon &GrassPokemon::operator=(const GrassPokemon &a) {
    name = a.name;
    type = a.type;
    hp = a.hp;
    att = a.att;
    regenAmount = a.regenAmount;
    maxHP = a.maxHP;

    cout << name << " is assigned with type: " << type << " | HP: " << hp
         << " | ATT: " << att << " | regen amount: " << regenAmount
         << " | max HP: " << maxHP << endl;

    return *this;
}

void GrassPokemon::attack(Pokemon &target) {
    int damage = att;
    if (target.getType() == "water") {
        damage *= 2;
    }

    cout << name << " used Vine Whip on " << target.getName() << " for "
         << damage << " damage"
         << (damage != att ? " and it's super effective!" : "") << endl;

    target.takeDamage(damage);

    healAfterAttack();
}

void GrassPokemon::healAfterAttack() {
    hp += regenAmount;
    if (hp > maxHP) hp = maxHP;  // Cap at max HP

    cout << name << " regenerates " << regenAmount << " HP! Current HP: " << hp
         << endl;
}