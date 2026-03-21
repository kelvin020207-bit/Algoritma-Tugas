#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

struct emp {
    int id;
    char name[SIZE];
};

void create(const char *filename);
void display(const char *filename);
void update(const char *filename);

int main(int argc, char *argv[])
{
    int ch;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    while (1) {
        printf("\n1. Create Record");
        printf("\n2. Display Records");
        printf("\n3. Update Record");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(argv[1]); break;
            case 2: display(argv[1]); break;
            case 3: update(argv[1]); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

void create(const char *filename)
{
    FILE *fp = fopen(filename, "ab");
    struct emp e;

    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter ID: ");
    scanf("%d", &e.id);

    fwrite(&e, sizeof(struct emp), 1, fp);

    fclose(fp);
}

void display(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    struct emp e;

    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    while (fread(&e, sizeof(struct emp), 1, fp)) {
        printf("\nID: %d | Name: %s", e.id, e.name);
    }

    fclose(fp);
}

void update(const char *filename)
{
    FILE *fp = fopen(filename, "rb+");
    struct emp e;
    int id, found = 0;

    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter ID to update: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(struct emp), 1, fp)) {
        if (e.id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", e.name);

            fseek(fp, -sizeof(struct emp), SEEK_CUR);
            fwrite(&e, sizeof(struct emp), 1, fp);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found\n");

    fclose(fp);
}