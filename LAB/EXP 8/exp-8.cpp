#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][20];
char firstSet[26][20];
char followSet[26][20];
int limit;

void add(char set[], char ch)
{
    int i;

    for(i = 0; set[i] != '\0'; i++)
    {
        if(set[i] == ch)
            return;
    }

    set[i] = ch;
    set[i + 1] = '\0';
}

void findFirst(char ch, char result[])
{
    int i, j;

    if(!isupper((unsigned char)ch))
    {
        add(result, ch);
        return;
    }

    for(i = 0; i < limit; i++)
    {
        if(production[i][0] == ch)
        {
            if(production[i][2] == '$')
            {
                add(result, '$');
            }
            else
            {
                for(j = 2; production[i][j] != '\0'; j++)
                {
                    char temp[20] = "";
                    findFirst(production[i][j], temp);

                    int k;
                    for(k = 0; temp[k] != '\0'; k++)
                        add(result, temp[k]);

                    if(strchr(temp, '$') == NULL)
                        break;
                }
            }
        }
    }
}

int main()
{
    int i, j, k, changed;
    char ch;

    printf("Enter total number of productions: ");
    scanf("%d", &limit);

    for(i = 0; i < limit; i++)
    {
        printf("Enter production %d: ", i + 1);
        scanf("%19s", production[i]);
    }

    for(i = 0; i < 26; i++)
    {
        firstSet[i][0] = '\0';
        followSet[i][0] = '\0';
    }

    for(i = 0; i < limit; i++)
    {
        ch = production[i][0];
        findFirst(ch, firstSet[ch - 'A']);
    }

    add(followSet[production[0][0] - 'A'], '$');

    do
    {
        changed = 0;

        for(i = 0; i < limit; i++)
        {
            char lhs = production[i][0];

            for(j = 2; production[i][j] != '\0'; j++)
            {
                ch = production[i][j];

                if(isupper((unsigned char)ch))
                {
                    int oldLength = strlen(followSet[ch - 'A']);

                    if(production[i][j + 1] != '\0')
                    {
                        char temp[20] = "";
                        findFirst(production[i][j + 1], temp);

                        for(k = 0; temp[k] != '\0'; k++)
                        {
                            if(temp[k] != '$')
                                add(followSet[ch - 'A'], temp[k]);
                        }

                        if(strchr(temp, '$') != NULL)
                        {
                            for(k = 0; followSet[lhs - 'A'][k] != '\0'; k++)
                                add(followSet[ch - 'A'], followSet[lhs - 'A'][k]);
                        }
                    }
                    else
                    {
                        for(k = 0; followSet[lhs - 'A'][k] != '\0'; k++)
                            add(followSet[ch - 'A'], followSet[lhs - 'A'][k]);
                    }

                    if(strlen(followSet[ch - 'A']) != oldLength)
                        changed = 1;
                }
            }
        }
    } while(changed);

    do
    {
        printf("\nEnter production value to find FOLLOW: ");
        scanf(" %c", &ch);

        printf("FOLLOW(%c) = { ", ch);

        for(i = 0; followSet[ch - 'A'][i] != '\0'; i++)
            printf("%c ", followSet[ch - 'A'][i]);

        printf("}\n");

        printf("Find another? (y/n): ");
        scanf(" %c", &ch);

        if(ch == 'y' || ch == 'Y')
            continue;
        else
            break;

    } while(1);

    return 0;
}