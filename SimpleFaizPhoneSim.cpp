#include <stdio.h>
int main () {
    int code;
    printf ("Enter the Code: ");
    scanf ("%d", &code);
    switch (code){
    case 555:
    printf( "Standing by, Complete.");
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

        case 5821:
            printf("Auto Vajin, come closer\n");
            break;

        case 5826:
            printf("Auto Vajin Battle Mode\n");
            break;

        case 5886:
            printf("Auto Vajin Vehicle Mode\n");
            break;

        case 5814:
            printf("Auto Vajin, get into the action\n");
            break;

        case 5846:
            printf("Auto vajin take off\n");
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