#include <stdio.h>

void print_number(int number, int is_first) {
    if (is_first) {
        printf("%d", number);
    } else {
        printf(" %d", number);
    }
}

void deret(int a, int b) {
    int current = a;
    int first_num = 1;

    while (current <= b) {
        print_number(current, first_num);
        first_num = 0;

        if (current % 2 == 0) {
            current *= 2;
        } else {
            current += 1;
        }
    }
    printf("\n");
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    deret(a, b);

    return 0;
}
