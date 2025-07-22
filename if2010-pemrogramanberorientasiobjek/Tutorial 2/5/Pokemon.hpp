#ifndef _POKEMON_HPP_
#define _POKEMON_HPP_

#include <string>

using namespace std;

class Pokemon {
   protected:
    string name;
    string type;
    int hp;   // health point
    int att;  // attack power

   public:
    // Ctor, Cctor, Dtor, and Operation
    Pokemon(string name, string type);
    Pokemon(string name, string type, int hp, int att);
    Pokemon(const Pokemon &);
    virtual ~Pokemon();

    string getName() const;
    string getType() const;

    void heal(int x);
    void takeDamage(int damage);
    virtual void attack(Pokemon &target) = 0;
};

#endif