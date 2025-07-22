#include "FirePokemon.hpp"
#include "GrassPokemon.hpp"
#include "Pokemon.hpp"
#include "WaterPokemon.hpp"

using namespace std;

int main() {
    FirePokemon c("Charmander");
    WaterPokemon s("Squirtle", 100, 20, 10);
    s.Pokemon::heal(10);
    s.attack(c);
    c.attack(s);
    s.attack(c);
    GrassPokemon b("Bulbasaur", 100, 50, 20);
    s.attack(b);
    b.attack(s);

    return 0;
}

// Charmander is born
// Charmander is born with type: fire | HP: 100 | ATT: 20 | attack count: 0
// Squirtle is born
// Squirtle is born with type: water | HP: 100 | ATT: 20 | attack boost: 10
// Squirtle heals 10 points | HP: 110
// Squirtle used Water Gun on Charmander for 40 damage and it's super effective!
// Charmander took 40 damage and now has 60 HP
// Squirtle's Flow State increases! Current damage: 30
// Charmander used Flamethrower on Squirtle for 20 damage
// Squirtle took 20 damage and now has 90 HP
// Squirtle used Water Gun on Charmander for 60 damage and it's super effective!
// Charmander took 60 damage and now has 0 HP
// Charmander has fainted
// Squirtle's Flow State increases! Current damage: 40
// Bulbasaur is born
// Bulbasaur is born with type: grass | HP: 100 | ATT: 50 | regen amount: 20 |
// max HP: 100 tle used Water Gun on Bulbasaur for 40 damage Bulbasaur took
// 40 damage and now has 60 HP Squirtle's Flow State increases! Current damage:
// 50 Bulbasaur used Vine Whip on Squirtle for 100 damage and it's super
// effective! Squirtle took 100 damage and now has 0 HP Squirtle has fainted
// Bulbasaur regenerates 20 HP! Current HP: 80
// Bulbasaur has run away
// Squirtle has run away
// Charmander has run away