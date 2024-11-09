#include <stdio.h>
#include "stack.h"
#include "boolean.h"

#define MaxN 10007

int main() {
    int N, i, val, a[MaxN], Left[MaxN], Right[MaxN], ans[MaxN];
    Stack s;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    CreateEmpty(&s);
    for (i = 0; i < N; i++) {
        while (!IsEmpty(s) && a[InfoTop(s)] >= a[i]) {
            Pop(&s, &val);
        }
        if (IsEmpty(s)) {
            Left[i] = -1;
        } else {
            Left[i] = InfoTop(s);
        }
        Push(&s, i);
    }

    CreateEmpty(&s);
    for (i = N - 1; i >= 0; i--) {
        while (!IsEmpty(s) && a[InfoTop(s)] >= a[i]) {
            Pop(&s, &val);
        }
        if (IsEmpty(s)) {
            Right[i] = N;
        } else {
            Right[i] = InfoTop(s);
        }
        Push(&s, i);
    }

    for (i = 1; i <= N; i++) {
        ans[i] = 0;
    }

    for (i = 0; i < N; i++) {
        int len = Right[i] - Left[i] - 1;
        if (a[i] > ans[len]) {
            ans[len] = a[i];
        }
    }

    for (i = N - 1; i >= 1; i--) {
        if (ans[i] < ans[i + 1]) {
            ans[i] = ans[i + 1];
        }
    }

    for (i = 1; i <= N; i++) {
        printf("%d", ans[i]);
        if (i != N) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
