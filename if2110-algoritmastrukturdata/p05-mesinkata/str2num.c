#include <stdio.h>

#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

char currentChar;
boolean EOP;
boolean EndWord;
Word currentWord;

int stringlen(char string[]) {
    int i = 0, len = 0;
    while (string[i] != '\0') {
        len++;
        i++;
    }
    return len;
}

void concatnumber(char result[], char str1[]) {
    int i = stringlen(result);
    int j = 0;
    if (i > 0) {
        result[i] = ' ';
        i++;
    }
    while (str1[j] != '\0') {
        result[i] = str1[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

void concat(char result[], Word str1) {
    int i = stringlen(result);
    int j = 0;
    if (i > 0) {
        result[i] = ' ';
        i++;
    }
    while (j < str1.Length) {
        result[i] = str1.TabWord[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

boolean sameword(char string1[], Word string2) {
    if (stringlen(string1) != string2.Length) {
        return false;
    }
    for (int i = 0; i < stringlen(string1); i++) {
        if (string1[i] != string2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

boolean isratusan(Word string1) { return sameword("ratus", string1); }

boolean ispuluhan(Word string1) { return sameword("puluh", string1); }

boolean isbelasan(Word string1) { return sameword("belas", string1); }

int searchidxinListString(Word string, char arr[][10]) {
    for (int i = 0; i < 13; i++) {
        if (sameword(arr[i], string)) {
            return i;
        }
    }
    return -1;
}

void str2num() {
    char huruf_depanEksklusif[13][10] = {
        "nol",   "satu",    "dua",      "tiga",    "empat",   "lima",   "enam",
        "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "seratus"};
    int bilangan[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 100};
    int angka = 0;
    int *Pangka = &angka;
    char finalsentence[100000] = "";

    START();
    while (!EOP) {
        int local = 0;
        int idx;
        IgnoreBlanks();
        CopyWord();
        idx = searchidxinListString(currentWord, huruf_depanEksklusif);

        if (idx != -1) {  // Kata numerik ditemukan
            local += bilangan[idx];
            IgnoreBlanks();
            if (idx == 10 || idx == 11) {  // sepuluh atau sebelas
                *Pangka += bilangan[idx];
                char num[10];
                sprintf(num, "%d", *Pangka);
                concatnumber(finalsentence, num);
                *Pangka = 0;
                continue;
            } else if (idx == 12) {  // seratus
                *Pangka += bilangan[idx];
                continue;
            } else if (local == 0) {
                char num[50];
                sprintf(num, "%d", local);
                concatnumber(finalsentence, num);
                continue;
            }

            CopyWord();
            if (isratusan(currentWord)) {
                local *= 100;
            } else if (ispuluhan(currentWord)) {
                local *= 10;
            } else if (isbelasan(currentWord)) {
                local += 10;
            } else if (local == 0) {
                int oneDigit =
                    searchidxinListString(currentWord, huruf_depanEksklusif);
                local += oneDigit;
            } else {
                if (local > 0) {
                    *Pangka += local;
                    char num[50];
                    sprintf(num, "%d", *Pangka);
                    concatnumber(finalsentence, num);
                }
                concat(finalsentence, currentWord);
                *Pangka = 0;
                continue;
            }
            *Pangka += local;
        } else {  // Kata non-numerik
            if (*Pangka > 0) {
                char num[10];
                sprintf(num, "%d", *Pangka);
                concatnumber(finalsentence, num);
                *Pangka = 0;
            }
            concat(finalsentence, currentWord);
        }
        ADV();
    }

    if (*Pangka > 0) {  // Print angka terakhir jika ada
        char num[10];
        sprintf(num, "%d", *Pangka);
        concatnumber(finalsentence, num);
    }

    printf("%s\n", finalsentence);
}

int main() {
    str2num();
    return 0;
}
