#include <stdio.h>

#include "boolean.h"
#include "stack.h"

boolean isDigit(char c) { return (c >= '0' && c <= '9'); }

int toNumber(char c) { return (c - '0'); }

// mengalikan "len" element teratas "S" sebanyak "factor"
void mullPartStack(Stack* S, int len, int factor) {
    int i, j;
    char part[10001];
    infotype val;

    for (i = 0; i < len; ++i) {  // menyimpan "len" element teratas "S" ([Top,
                                 // Top-1, ..., Top-(len-1)])
        Pop(S, &val);
        part[i] = val;
    }

    if (factor == 0 || len == 0) {  // factor = 0, maka "part" dihapus dari "s".
        return;                     // len = 0, maka do nothing
    }

    for (i = 0; i < factor;
         ++i) {  // mengalikan "part" sebanyak "factor" kedalam "S"
        for (j = len - 1; j >= 0; --j) {
            Push(S, part[j]);
        }
    }
}

int main() {
    int N, i, len, factorList[101],
        lenList[101];  // factorList menyimpan factor (macam stack manual),
                       // lenList menyimpan "len part" yang akan dikalikan
    int factor = 1;    // default value "factor" adalah 1 supaya mullPartStack
                       // tidak menghilangkan "part" kalau "factor" tidak
                       // disebutkan secara eksplisit
    int acm = 0;       // accumulator "factor" jika disebukan eksplisit
    int factorIdx = 0;
    int lenIdx = 0;
    char ch;
    boolean numEksplisit =
        false;  // flag jika "factor" disebutkan secara eksplisit
    Stack S;
    CreateEmpty(&S);

    for (i = 0; i < 100; ++i) {
        lenList[i] = 0;  // insialisasi elemen lenList
    }

    scanf("%d\n", &N);

    for (i = 0; i < N; i++) {
        scanf(" %c", &ch);
        if (isDigit(ch)) {
            numEksplisit = true;
            acm = (acm * 10) + toNumber(ch);
            // lorem
        } else if (ch == '[') {
            if (numEksplisit) {
                factor = acm;
            }
            factorList[factorIdx] = factor;
            factorIdx += 1;
            factor = 1;  // reset default value factor
            lenIdx += 1;
            acm = 0;
        } else if (ch == ']') {
            mullPartStack(&S, lenList[lenIdx], factorList[factorIdx - 1]);
            lenList[lenIdx - 1] +=
                lenList[lenIdx] *
                factorList[factorIdx -
                           1];  // update nilai "len" untuk "part" sebelumnya
            lenList[lenIdx] = 0;
            lenIdx -= 1;
            factorIdx -= 1;
        } else {
            Push(&S, ch);
            lenList[lenIdx] += 1;
        }
    }

    for (i = 0; i <= Top(S); ++i) {
        printf("%c", S.T[i]);
    }

    printf("\n");

    return 0;
}