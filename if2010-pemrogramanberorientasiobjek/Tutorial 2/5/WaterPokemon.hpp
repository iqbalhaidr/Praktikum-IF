#ifndef _WATERPOKEMON_HPP_
#define _WATERPOKEMON_HPP_

#include "Pokemon.hpp"

class WaterPokemon : public Pokemon {
   private:
    int attackBoost;  // Increases attack after every attack

   public:
    // Ctor, Cctor, Dtor, dan operasi assignment
    WaterPokemon(string name);
    WaterPokemon(string name, int hp, int att, int attackBoost);
    WaterPokemon(const WaterPokemon &);
    WaterPokemon &operator=(const WaterPokemon &);

    void attack(Pokemon &target);
};

#endif