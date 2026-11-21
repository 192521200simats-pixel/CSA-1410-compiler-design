
#include <stdio.h>
#include <string.h>

char stack[100], input[100];
int top = 0;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int reduce() {
    if (top >= 3 &&
        stack[top - 2] == 'E' &&
        (stack[top - 1] == '+' || stack[top - 1] == '-' ||
         stack[top - 1] == '*' || stack[top - 1] == '/') &&
        stack[top] == 'E') {
        stack[top - 2] = 'E';
        top -= 2;
        stack[top + 1] = '\0';
        return 1;
    }
    return 0;
}

int main() {
    int i = 0, valid = 1;
    char op;

    printf("Operator Precedence Parser\n");
    printf("Use i for an identifier.\n");
    printf("Enter expression: ");
    scanf("%99s", input);

    stack[0] = '$';
    stack[1] = '\0';
    strcat(input, "$");

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    while (input[i] != '$') {
        if (input[i] == 'i') {
            stack[++top] = 'E';
            stack[top + 1] = '\0';
            i++;

            printf("%s\t\t%s\t\tShift and reduce i to E\n",
                   stack, input + i);
        }
        else if (strchr("+-*/", input[i])) {
            while (top >= 3 &&
                   stack[top] == 'E' &&
                   prec(stack[top - 1]) >= prec(input[i])) {
                reduce();
                printf("%s\t\t%s\t\tReduce\n",
                       stack, input + i);
            }

            if (top >= 1 && stack[top] == 'E') {
                stack[++top] = input[i];
                stack[top + 1] = '\0';
                i++;

                printf("%s\t\t%s\t\tShift\n",
                       stack, input + i);
            } else {
                valid = 0;
                break;
            }
        }
        else {
            valid = 0;
            break;
        }
    }

    while (valid && reduce()) {
        printf("%s\t\t$\t\tReduce\n", stack);
    }

    if (valid && top == 1 && stack[1] == 'E')
        printf("\nExpression Accepted.\n");
    else
        printf("\nExpression Not Accepted.\n");

    return 0;
}
