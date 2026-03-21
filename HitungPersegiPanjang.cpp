#include <stdio.h>

int main() {
    double panjang, lebar, luas, keliling;

    printf("Masukkan panjang: ");
    scanf("%lf", &panjang);
    printf("Masukkan lebar: ");
    scanf("%lf", &lebar);

    luas = panjang * lebar;
    keliling = 2 * (panjang + lebar);

    printf("Luas persegi panjang     : %.2lf\n", luas);
    printf("Keliling persegi panjang : %.2lf\n", keliling);

    return 0;
}
