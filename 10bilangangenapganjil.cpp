#include <stdio.h>

int main() {
    int numbers[10];
    
    printf("Masukkan 10 bilangan:\n");
    for (int i = 0; i < 10; i++) {
        printf("Angka %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    printf("\n Bilangan Ganjil: ");
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 != 0) {
            printf("%d ", numbers[i]);
        }
    }
    
    printf("\nAngka Genap: ");
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d ", numbers[i]);
        }
    }
    
    printf("\n");
    return 0;
}