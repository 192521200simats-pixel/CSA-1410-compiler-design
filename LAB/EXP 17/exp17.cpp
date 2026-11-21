
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    int ch, characters = 0, words = 0, lines = 0;
    int inWord = 0, lastChar = '\0';

    fp = fopen("sample.c", "r");

    if (fp == NULL) {
        printf("Cannot open sample.c\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            words++;
            inWord = 1;
        }

        lastChar = ch;
    }

    if (characters > 0 && lastChar != '\n')
        lines++;

    printf("Total number of words : %d\n", words);
    printf("Total number of lines : %d\n", lines);
    printf("Total number of characters : %d\n", characters);

    fclose(fp);
    return 0;
}
