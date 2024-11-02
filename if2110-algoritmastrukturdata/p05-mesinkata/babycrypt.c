#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;
boolean EndWord;
Word currentWord;

int findN(Word currentWord) {
    int num = 0;
    for (int i = 0; i < currentWord.Length; i++) {
        num = num * 10 + (currentWord.TabWord[i] - '0');
    }
    return num%26;
}

boolean isHuruf(char c) {
    int n = (int)c;
    return ((n>=65 && n<=90) || (n>=97 && n<=122));
}

int findShift(char c, int n) {
    int x = (int)c;
    if (x>=65 && x<=90) {
        x = x - n;
        if (x < 65) {
            x += 26;
        } 
        return x;
    } else {
        x = x - n;
        if (x < 97) {
            x += 26;
        }
        return x;
    }
}

void shift(int n, Word *currentWord) {
    int y = (*currentWord).Length;
    for (int i=0; i<y; ++i) {
        if (isHuruf((*currentWord).TabWord[i])) {
            (*currentWord).TabWord[i] = (char)findShift((*currentWord).TabWord[i], n);
        }
    }
}

void displayWord(Word currentWord) {
    int n = currentWord.Length;
    for (int i=0; i<n; ++i) {
        printf("%c", currentWord.TabWord[i]);
    }
}

int main() {
    STARTWORD();
    int n = findN(currentWord);

    ADVWORD();
    while (!EndWord) {
        shift(n, &currentWord);
        displayWord(currentWord);

        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}