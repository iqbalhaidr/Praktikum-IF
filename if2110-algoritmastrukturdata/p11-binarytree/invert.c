#include <stdio.h>

#include "bintree.h"

void invertTree(BinTree *p) {
    if (isTreeEmpty(*p)) {
        return;
    }
    Address temp = LEFT(*p);
    LEFT(*p) = RIGHT(*p);
    RIGHT(*p) = temp;
    invertTree(&LEFT(*p));
    invertTree(&RIGHT(*p));
}