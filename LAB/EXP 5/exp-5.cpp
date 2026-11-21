#include <stdio.h>

int main()
{
    char str[1000];
    int words = 0, newline = 0, characters = 0;
    int i;

    printf("Enter the text (use ~ to stop):\n");
    scanf("%999[^~]", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            words++;
        }
        else if(str[i] == '\n')
        {
            newline++;
            words++;
        }
        else
        {
            characters++;
        }
    }

    if(characters > 0)
    {
        words++;
        newline++;
    }

    printf("\nTotal number of words: %d", words);
    printf("\nTotal number of lines: %d", newline);
    printf("\nTotal number of characters: %d", characters);

    return 0;
}