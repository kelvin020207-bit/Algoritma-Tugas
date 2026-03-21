#include <stdio.h>

int main() {
    double d, r, luas, keliling;
    const double pi = 3.14;  // correct placement

    printf("Masukkan diameter: ");
    scanf("%lf", &d);

    r = d / 2;
    luas = pi * r * r;
    keliling = 2 * pi * r;

    printf("Jari-jari: %.2lf\n", r);
    printf("Luas: %.2lf\n", luas);
    printf("Keliling: %.2lf\n", keliling);

    return 0;
}

