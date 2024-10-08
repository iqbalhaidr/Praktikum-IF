#include "boolean.h"
#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
    for (int i=IDX_MIN; i<CAPACITY; ++i) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    int i = IDX_MIN;
    while ((ELMT(l, i) != MARK) && (i<CAPACITY)) {
        ++i;
    }
    return i;
}

IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    return (listLength(l)-1);
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return i>=IDX_MIN && i<CAPACITY;
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i>=IDX_MIN) && (i<=listLength(l)-1);
}

boolean isEmpty(ListStatik l) {
    return listLength(l) == 0;
}

boolean isFull(ListStatik l) {
    return listLength(l) == CAPACITY;
}

void readList(ListStatik *l) {
    CreateListStatik(l);
    IdxType n;
    scanf("%d", &n);

    while (n < IDX_MIN || n > CAPACITY) {
        scanf("%d", &n);
    }

    for (int i = IDX_MIN; i < n; ++i) {
        ElType el;
        scanf("%d", &el);
        ELMT(*l, i) = el;
    }
}


void printList(ListStatik l) {
    if (listLength(l) == 0) {
        printf("[]");
    } else {
        printf("[");
        for (int i = IDX_MIN; i < listLength(l); ++i) {
            if (i > 0) {
                printf(",");
            }
            printf("%d", ELMT(l, i));
        }
        printf("]");
    }
}


ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    if (plus) {
        for (int i=0; i<listLength(l1); ++i) {
            ELMT(l1, i) += ELMT(l2, i);
        }
    } else {
        for (int i=0; i<listLength(l1); ++i) {
            ELMT(l1, i) -= ELMT(l2, i);
        }
    } return l1;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    if (listLength(l1) == listLength(l2)) {
        boolean flag = true;
        for (int i=IDX_MIN; i<listLength(l1); ++i) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                flag = false;
            }
        }
        return flag;
    } else {
        return false;
    }
}

int indexOf(ListStatik l, ElType val) {
    if (listLength(l) == 0) {
        return IDX_UNDEF;
    } else {
        boolean isFound = false;
        int i = IDX_MIN;
        while (!isFound && i<listLength(l)) {
            if (ELMT(l, i) == val) {
                isFound = true;
            }
            ++i;
        }
        if (isFound) {
            return i-1;
        } else {
            return IDX_UNDEF;
        }
    }
}


void extremeValues(ListStatik l, ElType *max, ElType *min) {
    ElType ma = ELMT(l, 0);
    ElType mi = ELMT(l, 0);
    for (int i=0; i<listLength(l); ++i) {
        if (ma<ELMT(l, i)) {
            ma = ELMT(l, i);
        }
        if (mi>ELMT(l, i)) {
            mi = ELMT(l, i);
        }
    }
    *max = ma;
    *min = mi;
}

void insertFirst(ListStatik *l, ElType val) {
    if (listLength(*l) == 0) {
        ELMT(*l, 0) = val;
    } else {
        for (int i=listLength(*l); i>0; --i) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, 0) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    for (int i=listLength(*l); i>idx; --i) {
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val) {
    if (listLength(*l) == 0) {
        ELMT(*l, 0) = val;
    } else {
        ELMT(*l, listLength(*l)) = val;
    }
}

void deleteFirst(ListStatik *l, ElType *val) {
    *val = ELMT(*l, 0);
    for (int i=0; i<listLength(*l)-1; ++i) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, listLength(*l)-1) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    *val = ELMT(*l, idx);
    for (int i=idx; i<listLength(*l)-1; ++i) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, listLength(*l)-1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val) {
    *val = ELMT(*l, listLength(*l)-1);
    ELMT(*l, listLength(*l)-1) = MARK;
}

void sortList(ListStatik *l, boolean asc) {
    int n = listLength(*l);  
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