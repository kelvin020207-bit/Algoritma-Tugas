#include <stdio.h>

int main() {
    int code;

    printf("Enter Orga Code: ");
    scanf("%d", &code);

    switch(code) {
        case 0:
            printf("Standing by, Complete.\n");
            break;

        case 103:
            printf("Single Mode\n");
            break;

        case 106:
            printf("Burst Mode\n");
            break;

        case 279:
            printf("Charge\n");
            break;

        case -1:
            printf("System Off\n");
            break;

        default:
            printf("ERROR\n");
    }

    return 0;
}