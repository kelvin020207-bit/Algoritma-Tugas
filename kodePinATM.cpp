#include <stdio.h>
int main (){
    int pin = 14115;
    int pin_input;
    int mistakes = 0;

    do {
        printf("Masukkan PIN ATM Anda: ");
        scanf("%d", &pin_input);

        if (pin_input == pin) {
            printf("PIN Anda Benar\n");
            break;  
        }
        else {
            printf("PIN Anda Salah\n");
            mistakes++;
        }

        if (mistakes == 3) {
            printf("ANDA DIBLOKIR\n");
            break;  
        }
    } while (1);  

    return 0;
}
