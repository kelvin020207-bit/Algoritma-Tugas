#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* Bil_Acak(int num) {
    int c;
    int *Ar;
    
    if (num <= 0) {
        return NULL;
    }
    
    Ar = (int*)malloc(num * sizeof(int));
    if (Ar == NULL) {
        return NULL;  
    }
    
    
    srand(time(0));
  
    for (c = 0; c < num; c++) {
        Ar[c] = rand();
    }
    
    
    return Ar;
}


int main() {
    int c;
    int num = 5;
    int *bil;
    
    
    bil = Bil_Acak(num);
    
    
    if (bil == NULL) {
        printf("Memory allocation failed or invalid input\n");
        return 1;
    }
    
    for (c = 0; c < num; c++) {
        printf("%d\n", bil[c]);
    }
    
    free(bil);
    
    
    return 0;
}