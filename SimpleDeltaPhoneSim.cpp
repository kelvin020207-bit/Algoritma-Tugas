#include <stdio.h>
#include <string.h>
int main(){
    char command[50];
    printf("Enter Delta Command: ");
    scanf("%s", command);
    if (strcmp(command, "Henshin") == 0) {
        printf("Standing by, Complete. Delta!\n");
  }
  else if (strcmp(command, "Fire") == 0){
    printf("Burst Mode!\n");
  }
    else if (strcmp(command, "Charge") == 0) {
        printf("Charge\n");
    }
    else if (strcmp(command, "3821") == 0) {
        printf("Jetsliger, come closer\n");
    }
    else if (strcmp(command, "Check") == 0) {
        printf("Lucifer's Hammer\n");
    }
    else if (strcmp(command, "3814") == 0) {
        printf("Jetsliger, get into the action\n");
    }
    else if (strcmp(command, "3846") == 0) {
        printf("Jetsliger, take off\n");
    }
    else if (strcmp(command, "End") == 0) {
        printf("System Off\n");
    }
    else {
        printf("ERROR\n");
    }

    return 0;
}