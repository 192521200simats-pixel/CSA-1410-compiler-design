
#include <stdio.h>

int main() {
    char arr[18][3] = {
        {'E', '+', 'T'},
        {'E', '*', 'T'},
        {'E', '(', 'T'},
        {'E', ')', 'F'},
        {'E', 'i', 'T'},
        {'E', '$', 'F'},
        {'F', '+', 'F'},
        {'F', '*', 'F'},
        {'F', '(', 'T'},
        {'F', ')', 'F'},
        {'F', 'i', 'T'},
        {'F', '$', 'F'},
        {'T', '+', 'F'},
        {'T', '*', 'T'},
        {'T', '(', 'T'},
        {'T', ')', 'F'},
        {'T', 'i', 'T'},
        {'T', '$', 'F'}
    };

    int i, j;
    char sets[3][20] = {
        "E -> + * ( i",
        "F -> ( i",
        "T -> * ( i"
    };

    printf("\nLEADING TABLE\n");

    for (i = 0; i < 18; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 3; i++) {
        printf("%s\n", sets[i]);
    }

    return 0;
}
