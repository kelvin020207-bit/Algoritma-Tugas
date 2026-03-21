#include <stdio.h>

int main() {
    float temps[7];
    float sum = 0.0, avg, min, max;
    
    printf("Masukkan temperatur untuk 7 hari:\n");
    for (int i = 0; i < 7; i++) {
        printf("Hari %d: ", i + 1);
        scanf("%f", &temps[i]);
        sum += temps[i];
    }
    
    // Calculate average
    avg = sum / 7.0;
    
    // Find min and max
    min = max = temps[0];
    for (int i = 1; i < 7; i++) {
        if (temps[i] < min) min = temps[i];
        if (temps[i] > max) max = temps[i];
    }
    
    printf("\nLaporan Mingguan:\n");
    printf("Rata rata suhu: %.2f°C\n", avg);
    printf("Paling Dingin: %.2f°C\n", min);
    printf("Paling Panas: %.2f°C\n", max);
    
    return 0;
}