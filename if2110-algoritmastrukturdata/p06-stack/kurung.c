#include <stdio.h>
#include "stack.h"

int main() {
    infotype val;
    Stack S;
    CreateEmpty(&S);

    int n;
    scanf("%d", &n);
    char string[1000];
    scanf("%s", string);

    boolean valid = true;

    for (int i = 0; i < n && valid; ++i) {
        if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
            Push(&S, string[i]);
        } else {
            if (IsEmpty(S)) {
                valid = false;
            } else if ((string[i] == ')' && InfoTop(S) == '(') ||
                      (string[i] == '}' && InfoTop(S) == '{') ||
                      (string[i] == ']' && InfoTop(S) == '[')) {
                Pop(&S, &val);
            } else {
                valid = false;
            }
        }   
    }

    if (valid && IsEmpty(S)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
