
#include <stdio.h>
#include <string.h>

char input[50], stack[50];
int top = -1;

void display(char remaining[]) {
    stack[top + 1] = '\0';
    printf("\n%-15s %-15s", stack, remaining);
}

int main() {
    int i, len;
    char remaining[50];

    printf("SHIFT REDUCE PARSER\n");
    printf("Grammar: E -> E+E | E*E | E/E | a | b\n");
    printf("Enter the input string: ");
    scanf("%49s", input);

    len = strlen(input);

    printf("\nStack          Input           Action\n");
    printf("--------------------------------------------");

    for (i = 0; i < len; i++) {
        stack[++top] = input[i];
        strcpy(remaining, input + i + 1);

        display(remaining);
        printf("  Shift %c", input[i]);

        if (stack[top] == 'a' || stack[top] == 'b') {
            stack[top] = 'E';
            display(remaining);
            printf("  Reduce E->%c", input[i]);
        }

        if (top >= 2 &&
            stack[top - 2] == 'E' &&
            (stack[top - 1] == '+' ||
             stack[top - 1] == '*' ||
             stack[top - 1] == '/') &&
            stack[top] == 'E') {

            char op = stack[top - 1];
            stack[top - 2] = 'E';
            top -= 2;

            display(remaining);
            printf("  Reduce E->E%cE", op);
        }
    }

    if (top == 0 && stack[0] == 'E')
        printf("\n\nString Accepted.\n");
    else
        printf("\n\nString Rejected.\n");

    return 0;
}
