
#include <stdio.h>

int main() {
    int n, i;
    char left[50], op1[50], op[50], op2[50];
    char l[50][50], a[50][50], oper[50][50], b[50][50];

    printf("enter the no: intermediate code:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("enter the 3 address code:%d:", i + 1);

        scanf(" %49[^=]=%49s", l[i], a[i]);

        /* Read the expression after '=' */
        if (sscanf(a[i], "%49[^+*/-]%49s", op1, op2) == 2) {
            /* handled below */
        }

        {
            char *p = a[i];
            int j = 0;

            while (p[j] && p[j] != '+' && p[j] != '-' &&
                   p[j] != '*' && p[j] != '/')
                j++;

            if (p[j] == '\0') {
                printf("Invalid intermediate code\n");
                return 0;
            }

            oper[i][0] = p[j];
            oper[i][1] = '\0';

            p[j] = '\0';
            sscanf(p, "%49s", a[i]);
            sscanf(p + j + 1, "%49s", b[i]);
        }
    }

    printf("the generated code is:");

    for (i = 0; i < n; i++) {
        printf("\n mov %s,R%d", a[i], i);

        if (oper[i][0] == '+')
            printf("\n add %s,R%d", b[i], i);
        else if (oper[i][0] == '-')
            printf("\n sub %s,R%d", b[i], i);
        else if (oper[i][0] == '*')
            printf("\n mul %s,R%d", b[i], i);
        else if (oper[i][0] == '/')
            printf("\n div %s,R%d", b[i], i);

        printf("\n mov R%d,%s\n", i, l[i]);
    }

    return 0;
}
