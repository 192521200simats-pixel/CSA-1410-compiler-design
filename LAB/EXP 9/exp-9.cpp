#include <stdio.h>

int main()
{
    char non_terminal;
    char beta, alpha;
    int num, i;
    char production[10][50];
    int index;

    printf("Enter number of productions: ");
    scanf("%d", &num);

    printf("Enter grammar (example: E->E-A|B):\n");

    for(i = 0; i < num; i++)
        scanf("%49s", production[i]);

    for(i = 0; i < num; i++)
    {
        index = 3;
        non_terminal = production[i][0];

        printf("\nGrammar: %s", production[i]);

        if(non_terminal == production[i][index])
        {
            alpha = production[i][index + 1];

            while(production[i][index] != '\0' &&
                  production[i][index] != '|')
            {
                index++;
            }

            if(production[i][index] != '\0')
            {
                beta = production[i][index + 1];

                printf("\nLeft recursive grammar");

                printf("\nGrammar without left recursion:");

                printf("\n%c->%c%c'", non_terminal, beta, non_terminal);

                printf("\n%c'->%c%c'|E\n",
                       non_terminal, alpha, non_terminal);
            }
            else
            {
                printf("\nCannot eliminate left recursion");
            }
        }
        else
        {
            printf("\nNot left recursive\n");
        }
    }

    return 0;
}