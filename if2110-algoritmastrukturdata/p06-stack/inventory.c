#include <stdio.h>

#include "stack.h"

void sum(Stack* S) {
    if (IsEmpty(*S)) {
        return;
    }
    infotype op1;
    infotype op2;
    while (Top(*S) > 0) {
        Pop(S, &op1);
        Pop(S, &op2);
        Push(S, op1 + op2);
    }
}

void sumTop2(Stack* S) {
    if (IsEmpty(*S)) {
        return;
    }
    infotype op1;
    infotype op2;
    Pop(S, &op1);
    Pop(S, &op2);
    Push(S, op2);
    Push(S, op1);
    Push(S, op1 + op2);
}

boolean isDigit(char c) {
    int n = (int)c;
    return (n >= 48 && n <= 57);
}

int toNumber(char c) {
    int n = (int)c;
    return (n - 48);
}

int main() {
    int n;
    scanf("%d", &n);
    char string[n];
    scanf("%s", string);

    Stack S;
    CreateEmpty(&S);
    int num;
    int op1;

    for (int i = 0; i < n; ++i) {
        if (isDigit(string[i]) || string[i] == 'D') {  //== 'D' untuk kasus tc6
            num = toNumber(string[i]);
            Push(&S, num);
        } else if (string[i] == '+') {
            sumTop2(&S);
        } else if (string[i] == 'X') {
            Pop(&S, &op1);
        } else if (string[i] == 'S') {
            sum(&S);
        } else {
            if (!IsEmpty(S)) {
                int count = Top(S) + 1;
                if (count > 0) {
                    sum(&S);
                    InfoTop(S) /= count;
                }
            }
        }
    }

    sum(&S);
    printf("%d\n", InfoTop(S));

    return 0;
}