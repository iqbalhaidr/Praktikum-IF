#include "Creature.hpp"
#include "Dragon.hpp"

void fnW(Creature *x) {
    x->wound();
}

void fnP(Creature *x) {
    x->print();
}

void fnS(Creature *x) {
    x->speak();
}

int main() {
    // Lengkapi disini

    Dragon *d = new Dragon("Draco");
    Dragon d2 = *d;
    Creature c = *d;

    d->speak();
    d->wound();
    d->wound();
    d->print();
    d->speak();
    fnW(d);
    fnP(d);
    d->print();
    c.speak();
    fnW(d);
    fnP(d);

    d2.wound();
    d2.wound();
    fnW(&d2);
    d2.print();

    return 0;
}

//A creature has been born!
//A dragon has been born!
//I  am the mighty dragon Draco! Beware of my flames!
//Base Health: 100; Additional Health: 80
//I am the mighty dragon Draco! Beware of my flames!
//Base Health: 90
//Base Health: 90; Additional Health: 80
//I am a mystical creature named Draco!
//Base Health: 80
//Base Health: 90; Additional Health: 80