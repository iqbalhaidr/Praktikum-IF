#include <stdio.h>

int fibo(int n, int a, int b) {
    if (n == 1) {
        return a;
    }
    if (n == 2) {
        return b;
    }

    int fmin2 = a;
    int fmin1 = b;
    int fnow;

    for (int i = 3; i <= n; i++) {
        fnow = fmin1 + fmin2;
        fmin2 = fmin1;
        fmin1 = fnow;
    }

    return fnow;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", fibo(n, a, b));

    return 0;
}
