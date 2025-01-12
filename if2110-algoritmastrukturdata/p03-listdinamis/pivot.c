#include <stdio.h>

#include "listdin.h"

int main() {
    ListDin l;
    CreateListDin(&l, 100000);
    readList(&l);

    int N = NEFF(l);
    int counter = 0;

    // Buat array bantu untuk prefix max dan suffix min
    int prefixMax[N], suffixMin[N];

    // Inisialisasi prefixMax dan suffixMin
    prefixMax[0] = ELMT(l, 0);
    suffixMin[N - 1] = ELMT(l, N - 1);

    // Hitung prefixMax
    for (int i = 1; i < N; i++) {
        prefixMax[i] =
            (ELMT(l, i) > prefixMax[i - 1]) ? ELMT(l, i) : prefixMax[i - 1];
    }

    // Hitung suffixMin
    for (int i = N - 2; i >= 0; i--) {
        suffixMin[i] =
            (ELMT(l, i) < suffixMin[i + 1]) ? ELMT(l, i) : suffixMin[i + 1];
    }

    // Cek berapa elemen yang bisa menjadi pivot
    for (int i = 0; i < N; i++) {
        boolean isLessEqual = (i == 0) || (ELMT(l, i) >= prefixMax[i - 1]);
        boolean isGreater = (i == N - 1) || (ELMT(l, i) <= suffixMin[i + 1]);
        if (isLessEqual && isGreater) {
            counter++;
        }
    }

    printf("%d\n", counter);

    return 0;
}
