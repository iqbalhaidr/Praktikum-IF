#include <iostream>

#include "A.hpp"

using namespace std;

int main() {
    A *obj1 = new A('1');
    A *obj2 = new A('2');
    A *cctor = new A(*obj1);
    *obj1 = *obj2;
    obj2->show();
    delete obj2;
    delete obj1;
    delete cctor;

    return 0;
}