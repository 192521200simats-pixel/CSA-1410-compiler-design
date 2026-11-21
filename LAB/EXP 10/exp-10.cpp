#include <stdio.h>
#include <string.h>

int main()
{
    char gram[100], part1[50], part2[50];
    char modifiedGram[50], newGram[100];

    int i, j, k = 0, pos = 0;

    printf("Enter production (example: iEtS|iEtSeS|a): ");
    scanf("%99s", gram);

    for(i = 0; gram[i] != '|' && gram[i] != '\0'; i++)
        part1[i] = gram[i];

    part1[i] = '\0';

    if(gram[i] == '\0')
    {
        printf("No left factoring required");
        return 0;
    }

    i++;

    for(j = 0; gram[i] != '\0'; i++, j++)
        part2[j] = gram[i];

    part2[j] = '\0';

    i = 0;

    while(part1[i] != '\0' &&
          part2[i] != '\0' &&
          part1[i] == part2[i])
    {
        modifiedGram[k++] = part1[i];
        i++;
    }

    pos = i;

    if(pos == 0)
    {
        printf("No common prefix found");
        return 0;
    }

    modifiedGram[k++] = 'X';
    modifiedGram[k] = '\0';

    strcpy(newGram, part1 + pos);
    strcat(newGram, "|");
    strcat(newGram, part2 + pos);

    printf("\nS->%s", modifiedGram);
    printf("\nX->%s\n", newGram);

    return 0;
}