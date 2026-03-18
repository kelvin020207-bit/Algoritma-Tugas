#include <stdio.h>

int main() {
    int x;
    int *ptr;

    // 1. x = 25
    x = 25;

    // 2. ptr = &x
    ptr = &x;

    // 3. write(x)
    printf("x = %d\n", x);

    // 4. write(ptr)
    printf("ptr = %p\n", ptr);

    // 5. x = x + 5
    x = x + 5;

    // 6. *ptr = *ptr + 10
    *ptr = *ptr + 10;

    // 7. write(x)
    printf("x = %d\n", x);

    // 8. write(ptr)
    printf("ptr = %p\n", ptr);

    return 0;
}