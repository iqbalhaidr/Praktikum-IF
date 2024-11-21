/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

#ifndef LISTCIRCULAR_H
#define LISTCIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"

typedef int ElType;
typedef struct node *Address;
typedef struct node {
    ElType info;
    Address next;
} ElmtList;
typedef struct {
    Address first;
} List;

/* Definisi list : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* Selektor */
#define INFO(P) (P)->info
#define NEXT(P) (P)->next
#define FIRST(l) ((l).first)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) { return FIRST(l) == NULL; }

void CreateList(List *l) { FIRST(*l) == NULL; }

Address allocate(ElType val) {
    Address p = (Address)malloc(sizeof(ElmtList));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }

    return p;
}

/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void deallocate(Address P) { free(P); }
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
    if (isEmpty(l)) {
        return NULL;
    }

    Address firstElmt = FIRST(l);
    if (INFO(firstElmt) == val) {
        return firstElmt;
    }

    Address p = NEXT(firstElmt);
    while (p != firstElmt) {
        if (INFO(p) == val) {
            return p;
        }
        p = NEXT(p);
    }

    return NULL;
}
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p) {
    if (isEmpty(l)) {
        return false;
    }

    Address firstElmt = FIRST(l);
    if (firstElmt == p) {
        return true;
    }

    Address trav = NEXT(firstElmt);
    while (trav != firstElmt) {
        if (trav == p) {
            return true;
        }
        trav = NEXT(trav);
    }

    return false;
}
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address p = allocate(val);

    if (p == NULL) {
        return;
    }

    if (isEmpty(*l)) {
        FIRST(*l) = p;
        NEXT(p) = p;
        return;
    }

    Address lastElmt = FIRST(*l);
    while (NEXT(lastElmt) != FIRST(*l)) {
        lastElmt = NEXT(lastElmt);
    }

    NEXT(p) = FIRST(*l);
    FIRST(*l) = p;
    NEXT(lastElmt) = p;
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
void insertLast(List *l, ElType val) {
    Address p = allocate(val);

    if (p == NULL) {
        return;
    }

    if (isEmpty(*l)) {
        FIRST(*l) = p;
        NEXT(p) = p;
        return;
    }

    Address lastElmt = FIRST(*l);
    while (NEXT(lastElmt) != FIRST(*l)) {
        lastElmt = NEXT(lastElmt);
    }

    NEXT(p) = FIRST(*l);
    NEXT(lastElmt) = p;
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    Address firstElmt = FIRST(*l);
    *val = INFO(firstElmt);

    if (NEXT(firstElmt) == firstElmt) {
        FIRST(*l) = NULL;
        deallocate(firstElmt);
        return;
    }

    Address lastElmt = FIRST(*l);
    while (NEXT(lastElmt) != FIRST(*l)) {
        lastElmt = NEXT(lastElmt);
    }

    FIRST(*l) = NEXT(firstElmt);
    NEXT(lastElmt) = NEXT(firstElmt);
    deallocate(firstElmt);
}
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama list l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Alamat elemen terakhir di-dealokasi */
void deleteLast(List *l, ElType *val) {
    Address firstElmt = FIRST(*l);
    Address lastElmt = FIRST(*l);
    Address prevLastElmt;

    while (NEXT(lastElmt) != FIRST(*l)) {
        prevLastElmt = lastElmt;
        lastElmt = NEXT(lastElmt);
    }
    *val = INFO(lastElmt);

    if (NEXT(firstElmt) == firstElmt) {
        FIRST(*l) = NULL;
        deallocate(firstElmt);
        return;
    }

    NEXT(prevLastElmt) = FIRST(*l);
    deallocate(lastElmt);
}
/* I.S. list tidak kosong */
/* F.S. x adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/*      Alamat elemen terakhir di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    if (isEmpty(l)) {
        printf("[]");
        return;
    }

    Address firstElmt = FIRST(l);
    Address p = NEXT(firstElmt);
    printf("[%d", INFO(firstElmt));
    while (p != NULL) {
        printf(",%d", INFO(p));
        p = NEXT(p);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif