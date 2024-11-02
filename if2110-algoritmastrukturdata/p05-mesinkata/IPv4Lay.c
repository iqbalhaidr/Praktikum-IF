#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;
boolean EndWord;
Word currentWord;

boolean isZero(char c) {
    int n = (c);
    return (n==48);
}

boolean isDigit(char c) {
    int n = (int)c;
    return (n>=48 && n<=57);
}

int toNumber(char c) {
    int n = (int)c;
    return (n-48);
} 

boolean isSign(char c) {
    int n = (int)c;
    return (n==64);
}

boolean isWordValid(Word curWord) {
    if (isSign(currentWord.TabWord[0])) {
        return false;
    }

    if (isSign(currentWord.TabWord[currentWord.Length - 1])) {
        return false;
    }

    int ctr = 0;
    boolean prevSign = false;
    for (int i=0; i<currentWord.Length; ++i) {
        if (isSign(currentWord.TabWord[i]) && !prevSign) {
            ctr += 1;
            prevSign = true;
        } else if (isSign(currentWord.TabWord[i]) && prevSign) {
            return false;
        } else if (!isSign(currentWord.TabWord[i]) && !isDigit(currentWord.TabWord[i])) {
            return false;
        } else {
            prevSign = false;
        }
    }
    return (ctr==3);
}

boolean isOktetValid(int oktet) {
    return (oktet>=0 && oktet<=255);
}

boolean isIPv4Lay(Word curWord) {
    if ((currentWord.Length > 50) || !isWordValid(currentWord)) {
        return false;
    } else {
        int ctrOktet = 0;
        int oktet = -1;
        boolean isNew = true;

        for (int i=0; i<currentWord.Length; ++i) {
            if (isSign(currentWord.TabWord[i])) {
                if (!isOktetValid(oktet)) {
                    return false;
                }
                ctrOktet += 1;
                oktet = -1;
                isNew = true;
            } else {
                if (isNew) {
                    if (isZero(currentWord.TabWord[i])) {
                        return false;
                    }
                    oktet = toNumber(currentWord.TabWord[i]);
                    isNew = false;
                } else {
                    if (isNew && isZero(currentWord.TabWord[i]) && 
                        (i + 1 < currentWord.Length) && 
                        !isSign(currentWord.TabWord[i + 1])) {
                        return false;  // Leading zero check
                    }
                    oktet *= 10;
                    oktet += toNumber(currentWord.TabWord[i]); // 192@168@@5
                }
            }
        }
        if (!isOktetValid(oktet)) {
            return false;
        }
        ctrOktet += 1;
        return (ctrOktet==4);
    }
}

int main() {
    STARTWORD();
    if (EndWord) {
        printf("ewh\n");
    } else {
        if (isIPv4Lay(currentWord)) {
            printf("4Lay");
        } else {
            printf("ewh");
        }
        ADVWORD();

        while (!EndWord) {
            if (isIPv4Lay(currentWord)) {
                printf(" 4Lay");
            } else {
                printf(" ewh");
            }
            ADVWORD();
        }

        printf("\n");
    }
    return 0;
}