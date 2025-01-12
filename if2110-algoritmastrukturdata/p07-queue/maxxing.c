#include <stdio.h>

#include "prioqueue.h"

int main() {
    int n;
    scanf("%d", &n);
    PrioQueue a;
    CreatePrioQueue(&a);
    PrioQueue b;
    CreatePrioQueue(&b);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&a, x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&b, x);
    }

    long long ans = 0;
    ElType val1, val2;

    while (!isEmpty(a)) {
        dequeue(&a, &val1);
        dequeue(&b, &val2);
        ans += (long long)val1 * (long long)val2;
    }

    printf("%lld\n", ans);
    return 0;
}