#include <stdio.h>

int main() {
    int n, k, num;
    int sum = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        if (num % k != 0) {
            sum += num;
        }
    }

    printf("%d\n", sum);

    return 0;
}
