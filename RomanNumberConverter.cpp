#include <stdio.h>

int main() {
    int number;

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40,
                    10, 9, 5, 4, 1};

    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC",
                       "L", "XL", "X", "IX", "V", "IV", "I"};

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Invalid number, try again\n");
        return 0;
    }

    printf("Roman number is: ");

    for (int i = 0; i < 13; i++) {
        while (number >= values[i]) {
            printf("%s", symbols[i]);
            number -= values[i];
        }
    }

    return 0;
}