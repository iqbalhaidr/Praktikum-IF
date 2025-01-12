#include <stdio.h>

#include "listdin.h"

boolean isOverlap(int s1, int e1, int s2, int e2) { return (s2 <= e1); }

int mergeStart(int s1, int s2) { return (s1 < s2) ? s1 : s2; }

int mergeStop(int e1, int e2) { return (e1 > e2) ? e1 : e2; }

int main() {
    ListDin intervalay, newInterval, result;
    int n;

    // Baca intervalay
    CreateListDin(&intervalay, 100000);
    readList(&intervalay);
    n = NEFF(intervalay);  // Jumlah elemen di intervalay

    // Baca newInterval
    CreateListDin(&newInterval, 2);
    NEFF(newInterval) = 2;
    for (int i = 0; i < 2; ++i) {
        scanf("%d", &ELMT(newInterval, i));
    }

    // Inisialisasi list untuk hasil
    CreateListDin(&result, 100000);

    int i = 0;

    // Tambahkan interval sebelum newInterval yang tidak beririsan
    while (i < n && ELMT(intervalay, i + 1) < ELMT(newInterval, 0)) {
        insertLast(&result, ELMT(intervalay, i));      // Masukkan start
        insertLast(&result, ELMT(intervalay, i + 1));  // Masukkan stop
        i += 2;
    }

    // Gabungkan interval yang beririsan dengan newInterval
    int newStart = ELMT(newInterval, 0);
    int newStop = ELMT(newInterval, 1);
    while (i < n && isOverlap(newStart, newStop, ELMT(intervalay, i),
                              ELMT(intervalay, i + 1))) {
        newStart =
            mergeStart(newStart, ELMT(intervalay, i));  // Gabungkan start
        newStop =
            mergeStop(newStop, ELMT(intervalay, i + 1));  // Gabungkan stop
        i += 2;
    }
    // Tambahkan newInterval yang telah digabung
    insertLast(&result, newStart);
    insertLast(&result, newStop);

    // Tambahkan interval setelah newInterval yang tidak beririsan
    while (i < n) {
        insertLast(&result, ELMT(intervalay, i));      // Masukkan start
        insertLast(&result, ELMT(intervalay, i + 1));  // Masukkan stop
        i += 2;
    }

    // Cetak hasil
    for (int j = 0; j < NEFF(result); ++j) {
        if (j > 0) {
            printf(" ");
        }
        printf("%d", ELMT(result, j));
    }
    printf("\n");

    // Dealokasi memori
    dealocateList(&intervalay);
    dealocateList(&newInterval);
    dealocateList(&result);

    return 0;
}
