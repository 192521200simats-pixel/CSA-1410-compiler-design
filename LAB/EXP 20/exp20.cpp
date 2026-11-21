
#include <stdio.h>

int main() {
    char arr[18][3] = {
        {'E','+','F'}, {'E','*','F'}, {'E','(','F'},
        {'E',')','F'}, {'E','i','F'}, {'E','$','F'},
        {'F','+','F'}, {'F','*','F'}, {'F','(','F'},
        {'F',')','F'}, {'F','i','F'}, {'F','$','F'},
        {'T','+','F'}, {'T','*','F'}, {'T','(','F'},
        {'T',')','F'}, {'T','i','F'}, {'T','$','F'}
    };

    int i, j;

    printf("TRAILING TABLE\n");

    for (i = 0; i < 18; i++) {
        for (j = 0; j < 3; j++)
            printf("%c\t", arr[i][j]);
        printf("\n");
    }

    printf("\n\n");
    printf("E ->\n");
    printf("F ->\n");
    printf("T ->\n");

    return 0;
}
