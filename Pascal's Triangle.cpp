#include <stdio.h>

int main() {
    int rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++) {
        int num = 1;

        
        for (int k = rows - i - 1; k > 0; k--) {
            printf("  ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%-5d", num);

            num = num * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}