
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp, *out;
    char result[20], a[20], b[20], op[5];
    char temp[10] = "t";
    int count = 1;

    fp = fopen("sum.txt", "r");
    out = fopen("out.txt", "w");

    if (fp == NULL || out == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    fscanf(fp, "%s", result);
    fscanf(fp, "%s", op);
    fscanf(fp, "%s", a);
    fscanf(fp, "%s", op);
    fscanf(fp, "%s", b);

    sprintf(temp, "t%d", count);
    fprintf(out, "%s=%s%s%s\n", temp, a, op, b);

    while (fscanf(fp, "%s", op) == 1) {
        if (fscanf(fp, "%s", b) != 1)
            break;

        count++;
        sprintf(temp, "t%d", count);

        fprintf(out, "%s=t%d%s%s\n",
                temp, count - 1, op, b);
    }

    fprintf(out, "%s=t%d\n", result, count);

    fclose(fp);
    fclose(out);

    printf("Three address code generated successfully.\n");
    printf("Check the output in out.txt\n");

    return 0;
}
