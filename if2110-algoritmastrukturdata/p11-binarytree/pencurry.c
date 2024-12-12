#include "bintree.h"

void oportunis(BinTree T, int *ambil, int *lewat) {
    if (isTreeEmpty(T)) {
        *ambil = 0;
        *lewat = 0;
        return;
    }

    int ambilKiri = 0, lewatKiri = 0;
    int ambilKanan = 0, lewatKanan = 0;

    oportunis(LEFT(T), &ambilKiri, &lewatKiri);
    oportunis(RIGHT(T), &ambilKanan, &lewatKanan);

    *ambil = ROOT(T) + lewatKiri + lewatKanan;
    *lewat = (ambilKiri > lewatKiri ? ambilKiri : lewatKiri) +
             (ambilKanan > lewatKanan ? ambilKanan : lewatKanan);
}

int mencurry(BinTree T) {
    int ambil = 0, lewat = 0;

    oportunis(T, &ambil, &lewat);

    return (ambil > lewat ? ambil : lewat);
}