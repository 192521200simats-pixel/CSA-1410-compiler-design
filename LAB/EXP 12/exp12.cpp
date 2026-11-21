
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();

int E() {
    if (T())
        return EP();
    return 0;
}

int EP() {
    if (input[i] == '+') {
        i++;
        if (T())
            return EP();
        return 0;
    }
    return 1;
}

int T() {
    if (F())
        return TP();
    return 0;
}

int TP() {
    if (input[i] == '*') {
        i++;
        if (F())
            return TP();
        return 0;
    }
    return 1;
}

int F() {
    if (input[i] == '(') {
        i++;
        if (E() && input[i] == ')') {
            i++;
            return 1;
        }
        return 0;
    }

    if (isalpha((unsigned char)input[i])) {
        while (isalnum((unsigned char)input[i]))
            i++;
        return 1;
    }

    return 0;
}

int main() {
    printf("Recursive Descent Parser\n");
    printf("Enter the string: ");
    scanf("%99s", input);

    i = 0;

    if (E() && input[i] == '\0')
        printf("String is accepted.\n");
    else
        printf("String is not accepted.\n");

    return 0;
}
