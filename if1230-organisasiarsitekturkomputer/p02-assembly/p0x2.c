#include <stdio.h>

void trap() { printf("Trap!"); }

void stage_completed() { printf("Stage Completed!"); }

void Monitoring() {
    int buffer[6], i;
    int num = 1;
    for (i = 0; i < 6; i++) {
        scanf("%d", &buffer[i]);
    }

    for (i = 0; i < 5; i++) {
        if (buffer[i] != num) {
            trap();
            return;
        }
        num *= 2;
    }

    num = num / 2 + 1;
    if (buffer[5] != num) {
        trap();
        return;
    }

    stage_completed();
}

int feel_like_eleven(int *buffer) {
    for (int i = 0; i < 7; i++) {
        scanf("%d", &buffer[i]);
    }

    if (buffer[6] <= 6) {
        trap();
        return 0;
    }

    return 1;
}

void Eleven() {
    int buffer[7];
    int status = feel_like_eleven(buffer);
    if (!status) {
        return;
    }
    for (int i = 0; i < 7; i++) {
        if (i == 0 && buffer[i] != 7) {
            trap();
            return;
        }
        if ((i % 2 == 0) && i != 0 && (buffer[i] != (buffer[i - 1] * 2) + i)) {
            trap();
            return;
        }
        if ((i % 2 == 1) && (buffer[i] != (buffer[i - 1] * i * 2))) {
            trap();
            return;
        }
    }
    stage_completed();
}

int check(char plain, char encrypt) {
    int decrypt = (encrypt - 'a' - 7 + 26) % 26 + 'a';
    if (decrypt != (int)plain) {
        trap();
        return 0;
    } else {
        return 1;
    }
}

void Bakenohana() {
    char str[5];
    char plain[5] = {'s', 't', 'e', 'i', 'k'};
    int status = 1;
    int i;
    for (i = 0; i < 5; i++) {
        scanf("%c", &str[i]);
    }

    for (i = 0; i < 5; i++) {
        status = check(plain[i], str[i]);
        if (!status) {
            return;
        }
    }
    stage_completed();
}

int main() { Monitoring(); }