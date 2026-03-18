#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    
    
    *ptr = 25;
    printf("Value of variable: %d\n", *ptr);

    
    scanf("%d", ptr);

    printf("Value of variable: %d\n", *ptr);

    int total = *ptr * 2;
    printf("Total: %d\n", total);

    // Free allocated memory
    free(ptr);

    return 0;
}