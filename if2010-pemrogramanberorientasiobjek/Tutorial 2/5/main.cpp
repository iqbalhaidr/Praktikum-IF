#include <iostream>

#include "FirePokemon.hpp"
#include "GrassPokemon.hpp"
#include "Pokemon.hpp"
#include "WaterPokemon.hpp"

using namespace std;

int main() {
    FirePokemon *c = new FirePokemon("Charmander");
    FirePokemon *c2 = new FirePokemon(*c);

    WaterPokemon *s = new WaterPokemon("Squirtle", 100, 20, 10);
    s->heal(10);

    WaterPokemon *m = new WaterPokemon("Magikarp");
    *m = *s;

    s->attack(*c);
    s->attack(*c);

    delete c;
    delete s;

    // m dan s tidak delete supaya tidak memanggil dtor

    return 0;
}