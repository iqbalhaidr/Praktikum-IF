#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity) {
    BUFFER(*l) = (ElType*) malloc(capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l) {
    free(BUFFER(*l));
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
}

int listLength(ListDin l) {
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l) {
    return NEFF(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i) {
    return i>=IDX_MIN && i<=CAPACITY(l);
}

boolean isIdxEff(ListDin l, IdxType i) {
    return i>=IDX_MIN && i<NEFF(l);
}

boolean isEmpty(ListDin l) {
    return NEFF(l) == 0;
}

boolean isFull(ListDin l) {
    return NEFF(l) == CAPACITY(l);
}

void readList(ListDin *l) {
    int N;
    do {
        scanf("%d", &N);
    } while (!isIdxValid(*l, N));
    CreateListDin(l, CAPACITY(*l));
    NEFF(*l) = N;
    for (int i=0; i<N; ++i) {
        scanf("%d", &ELMT(*l, i));
    }
} 

void printList(ListDin l) {
    printf("[");
    for (int i=IDX_MIN; i<NEFF(l) ; ++i) {
        if (i > 0) {
            printf(",");
        }
        printf("%d", ELMT(l, i));
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin result;
    CreateListDin(&result, CAPACITY(l1)); 
    NEFF(result) = NEFF(l1);
    if (plus) {
        for (int i=IDX_MIN; i<NEFF(l1); ++i) {
            ELMT(result, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for (int i=IDX_MIN; i<NEFF(l1); ++i) {
            ELMT(result, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return result;
}

boolean isListEqual(ListDin l1, ListDin l2) {
    if (NEFF(l1) == NEFF(l2)) {
        for (int i=IDX_MIN; i<NEFF(l1); ++i) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                return false;
            }
        }
        return true;
    } 
    return false;
}

IdxType indexOf(ListDin l, ElType val) {
    int i = IDX_MIN;
    boolean isFound = false;
    while (!isFound && i<NEFF(l)) {
        if (ELMT(l, i) == val) {
            return i;
        }
        ++i;
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min) {
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);
    for (int i=IDX_MIN; i<NEFF(l); ++i) {
        if (*max<ELMT(l, i)) {
            *max = ELMT(l, i);
        }
        if (*min>ELMT(l, i)) {
            *min = ELMT(l, i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (int i=IDX_MIN; i<NEFF(lIn); ++i) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l) {
    ElType sum = 0;
    for (int i=IDX_MIN; i<NEFF(l); ++i) {
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal(ListDin l, ElType val) {
    int count = 0;
    for (int i=IDX_MIN; i<NEFF(l); ++i) {
        if (ELMT(l, i) == val) {
            count += 1;
        }
    }
    return count;
}

void sort(ListDin *l, boolean asc) {
    int n = NEFF(*l);  
    ElType temp;

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (asc) {
                if (ELMT(*l, j) > ELMT(*l, j+1)) {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j+1);
                    ELMT(*l, j+1) = temp;
                }
            } else {
                if (ELMT(*l, j) < ELMT(*l, j+1)) {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j+1);
                    ELMT(*l, j+1) = temp;
                }
            }
        }
    }
}

void insertLast(ListDin *l, ElType val){
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}

void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) -= 1;
} 

void expandList(ListDin *l, int num) {
    ListDin l_copy;
    copyList(*l, &l_copy);
    dealocateList(l);
    CreateListDin(l, (CAPACITY(l_copy) + num));
    NEFF(*l) = NEFF(l_copy);
    for (int i=IDX_MIN; i<NEFF(l_copy); ++i) {
        ELMT(*l, i) = ELMT(l_copy, i);
    }
    dealocateList(&l_copy);
}

void shrinkList(ListDin *l, int num) {
    ListDin l_copy;
    copyList(*l, &l_copy);
    dealocateList(l);
    CreateListDin(l, (CAPACITY(l_copy) - num));
    NEFF(*l) = NEFF(l_copy);
    for (int i=IDX_MIN; i<NEFF(l_copy); ++i) {
        ELMT(*l, i) = ELMT(l_copy, i);
    }
    dealocateList(&l_copy);
}

void compressList(ListDin *l) {
    ListDin l_copy;
    copyList(*l, &l_copy);
    dealocateList(l);
    CreateListDin(l, NEFF(l_copy));
    NEFF(*l) = NEFF(l_copy);
    for (int i=IDX_MIN; i<NEFF(l_copy); ++i) {
        ELMT(*l, i) = ELMT(l_copy, i);
    }
    dealocateList(&l_copy);
}
