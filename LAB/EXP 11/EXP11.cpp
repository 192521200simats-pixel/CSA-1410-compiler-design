
#include <stdio.h>
#include <string.h>

struct symtab {
    char label[20];
    int addr;
};

struct symtab sy[50];
int cnt = 0;

int search(char s[]) {
    int i;
    for (i = 0; i < cnt; i++) {
        if (strcmp(sy[i].label, s) == 0)
            return 1;
    }
    return 0;
}

void insert() {
    char lab[20];

    printf("Enter the label: ");
    scanf("%19s", lab);

    if (search(lab)) {
        printf("Duplicate symbol!\n");
    } else {
        strcpy(sy[cnt].label, lab);
        printf("Enter the address: ");
        scanf("%d", &sy[cnt].addr);
        cnt++;
        printf("Symbol inserted successfully.\n");
    }
}

void display() {
    int i;
    printf("\nSymbol Table\n");
    printf("Label\tAddress\n");

    for (i = 0; i < cnt; i++)
        printf("%s\t%d\n", sy[i].label, sy[i].addr);
}

void modify() {
    char lab[20];
    int ad, i, found = 0;

    printf("Enter the label to modify: ");
    scanf("%19s", lab);

    for (i = 0; i < cnt; i++) {
        if (strcmp(sy[i].label, lab) == 0) {
            printf("Enter the new address: ");
            scanf("%d", &ad);
            sy[i].addr = ad;
            found = 1;
            printf("Address modified successfully.\n");
            break;
        }
    }

    if (!found)
        printf("No such symbol found.\n");
}

int main() {
    int ch;
    char lab[20];

    do {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Modify\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter the label: ");
                scanf("%19s", lab);

                if (search(lab))
                    printf("Label is found.\n");
                else
                    printf("Label is not found.\n");
                break;

            case 4:
                modify();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 5);

    return 0;
}
