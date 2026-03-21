#include <stdio.h>
 
int main()
{
    int fib1 = 0, fib2 = 1, fib3, num, count = 0;
 
    printf("Enter the value of num: \n");
    scanf("%d", &num);
    printf("First %d Fibonacci numbers are ...\n", num);
    printf("%d\n", fib1);
    printf("%d\n", fib2);
    count = 2; 
    for (int i =2; count < num; count++){
        fib3 = fib1 + fib2;
        printf("%d\n", fib3);
        fib1 = fib2;
        fib2 = fib3;
    }
}