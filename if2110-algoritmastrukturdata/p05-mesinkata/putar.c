#include <stdio.h>

#include "mesinkarakter.h"
#include "mesinkata.h"

char currentChar;
boolean EOP;
boolean EndWord;
Word currentWord;

void putar(Word* currentWord) {
    int n = (*currentWord).Length;
    char TempWord[n];
    for (int i = 0; i < n; ++i) {
        TempWord[i] = (*currentWord).TabWord[n - (i + 1)];
    }
    for (int j = 0; j < n; ++j) {
        (*currentWord).TabWord[j] = TempWord[j];
    }
}

void displayWord(Word currentWord) {
    int n = currentWord.Length;
    for (int i = 0; i < n; ++i) {
        printf("%c", currentWord.TabWord[i]);
    }
}

int main() {
    STARTWORD();
    int i = 1;
    while (!EndWord) {
        if ((i % 2) == 1) {
            putar(&currentWord);
        }

        displayWord(currentWord);

        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }

        ++i;
    }
    printf("\n");

    return 0;
}