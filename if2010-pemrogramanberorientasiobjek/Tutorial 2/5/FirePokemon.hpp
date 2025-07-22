#ifndef _FIREPOKEMON_HPP_
#define _FIREPOKEMON_HPP_

#include "Pokemon.hpp"

class FirePokemon : public Pokemon {
   private:
    int attackCount;  // Counts the number of attacks

   public:
    // Ctor, Cctor, Dtor, dan operasi assignment
    FirePokemon(string name);
    FirePokemon(string name, int hp, int att);
    FirePokemon(const FirePokemon &);
    FirePokemon &operator=(const FirePokemon &);

    void attack(Pokemon &target);
};

#endif