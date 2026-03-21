#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle(char *arr, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int length;

    char numbers[] = "0123456789";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbols[] = "!@#$%^&*()-_=+[]{};:,.<>?";

    char all[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+[]{};:,.<>?";

    printf("Enter password length (max 14): ");
    scanf("%d", &length);

    // Validation
    if (length <= 0 || length > 14) {
        printf("Invalid length.\n");
        return 1;
    }

    char password[15]; 

    srand(time(NULL));


    password[0] = numbers[rand() % (sizeof(numbers) - 1)];
    password[1] = lowercase[rand() % (sizeof(lowercase) - 1)];
    password[2] = uppercase[rand() % (sizeof(uppercase) - 1)];
    password[3] = symbols[rand() % (sizeof(symbols) - 1)];

    for (int i = 4; i < length; i++) {
        password[i] = all[rand() % (sizeof(all) - 1)];
    }

    shuffle(password, length);

    password[length] = '\0';

    printf("Generated password: %s\n", password);

    return 0;
}