#include <stdio.h>

int main() {
    double sisi, luas, volume;

    printf("Masukkan panjang sisi kubus: ");
    scanf("%lf", &sisi);

    luas = 6 * (sisi * sisi);     // luas permukaan = 6 × s²
    volume = sisi * sisi * sisi;  // volume = s³

    printf("Luas permukaan kubus = %.2lf\n", luas);
    printf("Volume kubus         = %.2lf\n", volume);

    return 0;
}

