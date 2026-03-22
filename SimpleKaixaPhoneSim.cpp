#include <stdio.h>

int main() {
    int code;

    printf("Enter Kaixa Code: ");
    scanf("%d", &code);

    switch(code) {
        case 913:
            printf("Kaixa Transformation\n");
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

        case 9821:
            printf("Side Basshar, come closer\n");
            break;

        case 9814:
            printf("Side Basshar, get into the action\n");
            break;

        case 9826:
            printf("Side Basshar Battle Mode\n");
            break;

        case 9886:
            printf("Side Basshar Vehicle Mode\n");
            break;

        case 3821:
            printf("Jetsliger\n");
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