
#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    int i, flag = 0;

    printf("The grammar is: S -> aS | Sb | ab\n");
    printf("Enter the string: ");
    scanf("%49s", str);

    if (strlen(str) < 2 || str[0] != 'a') {
        printf("String is not accepted.\n");
        return 0;
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'b')
            flag = 1;
        else if (str[i] == 'a' && flag == 1) {
            printf("String is not accepted.\n");
            return 0;
        }
        else if (str[i] != 'a' && str[i] != 'b') {
            printf("String is not accepted.\n");
            return 0;
        }
    }

    if (flag == 1)
        printf("String is accepted.\n");
    else
        printf("String is not accepted.\n");

    return 0;
}
