#ifndef _GRASSPOKEMON_HPP_
#define _GRASSPOKEMON_HPP_

#include "Pokemon.hpp"

class GrassPokemon : public Pokemon {
   private:
    int regenAmount;  // How much HP to regenerate after an attack
    int maxHP;        // Store the original max HP

   public:
    // Ctor, Cctor, Dtor, dan operasi assignment
    GrassPokemon(string name);
    GrassPokemon(string name, int hp, int att, int regenAmount);
    GrassPokemon(const GrassPokemon &);
    GrassPokemon &operator=(const GrassPokemon &);

    void attack(Pokemon &target);
    void healAfterAttack();
};

#endif