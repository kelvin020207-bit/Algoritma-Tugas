#include <stdio.h>

int main() {
    int code;

    printf("Enter Psyga Code: ");
    scanf("%d", &code);

    switch(code) {
        case 315:
            printf("Transformation Standby\n");
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

        case 3176:
            printf("Flying Attacker, put into motion\n");
            break;

        case 3146:
            printf("Flying Attacker, take off\n");
            break;

        case 3821:
            printf("Jetsliger, come closer\n");
            break;

        case 3814:
            printf("Jetsliger, get into the action\n");
            break;

        case 3846:
            printf("Jetsliger, take off\n");
            break;

        case 0:
            printf("Exceed Charge\n");
            break;

        case -1:
            printf("System Off\n");
            break;

        default:
            printf("ERROR\n");
    }

    return 0;
}