#include <stdio.h>
#include <math.h>

// Fungsi untuk menghitung dot product
double dotProduct(double A[3], double B[3]) {
    return A[0]*B[0] + A[1]*B[1] + A[2]*B[2];
}

// Fungsi untuk menghitung cross product
void crossProduct(double A[3], double B[3], double result[3]) {
    result[0] = A[1]*B[2] - A[2]*B[1];
    result[1] = A[2]*B[0] - A[0]*B[2];
    result[2] = A[0]*B[1] - A[1]*B[0];
}

// Fungsi untuk menghitung norm/magnitude vektor
double vectorNorm(double A[3]) {
    return sqrt(A[0]*A[0] + A[1]*A[1] + A[2]*A[2]);
}

// Fungsi untuk menampilkan vektor
void printVector(double A[3]) {
    printf("(%.2f, %.2f, %.2f)", A[0], A[1], A[2]);
}

int main() {
    double A[3], B[3];
    double result1[3], result2[3], crossAB[3], crossBA[3];
    double dotProd, normA, normB, angle, distance;
    
    printf("==================================================\n");
    printf("PROGRAM OPERASI VEKTOR 3 DIMENSI\n");
    printf("==================================================\n");
    
    // Input vektor pertama
    printf("\nMasukkan komponen vektor pertama (A):\n");
    printf("  A1 (komponen x): ");
    scanf("%lf", &A[0]);
    printf("  A2 (komponen y): ");
    scanf("%lf", &A[1]);
    printf("  A3 (komponen z): ");
    scanf("%lf", &A[2]);
    
    // Input vektor kedua
    printf("\nMasukkan komponen vektor kedua (B):\n");
    printf("  B1 (komponen x): ");
    scanf("%lf", &B[0]);
    printf("  B2 (komponen y): ");
    scanf("%lf", &B[1]);
    printf("  B3 (komponen z): ");
    scanf("%lf", &B[2]);
    
    printf("\n==================================================\n");
    printf("HASIL PERHITUNGAN\n");
    printf("==================================================\n");
    
    // a. 5A - 3B dan 4A + 7B
    printf("\na. Operasi Linear:\n");
    for(int i = 0; i < 3; i++) {
        result1[i] = 5*A[i] - 3*B[i];
        result2[i] = 4*A[i] + 7*B[i];
    }
    printf("   5A - 3B = "); printVector(result1); printf("\n");
    printf("   4A + 7B = "); printVector(result2); printf("\n");
    
    // b. Dot product A.B
    printf("\nb. Hasil Kali Titik (Dot Product):\n");
    dotProd = dotProduct(A, B);
    printf("   A • B = %.2f\n", dotProd);
    
    // c. Sudut antara vektor A dan B
    printf("\nc. Sudut antara Vektor A dan B:\n");
    normA = vectorNorm(A);
    normB = vectorNorm(B);
    if(normA != 0 && normB != 0) {
        angle = acos(dotProd / (normA * normB)) * 180 / M_PI;
        printf("   θ = %.2f°\n", angle);
    } else {
        printf("   Tidak dapat menghitung sudut (vektor nol)\n");
    }
    
    // d. Jarak antara vektor A dan B
    printf("\nd. Jarak antara Vektor A dan B:\n");
    for(int i = 0; i < 3; i++) {
        result1[i] = A[i] - B[i];
    }
    distance = vectorNorm(result1);
    printf("   Jarak = ||A - B|| = %.2f\n", distance);
    
    // e. Cross product A x B
    printf("\ne. Hasil Kali Silang (Cross Product):\n");
    crossProduct(A, B, crossAB);
    printf("   A × B = "); printVector(crossAB); printf("\n");
    
    // f. Cross product B x A
    printf("\nf. Hasil Kali Silang (Cross Product):\n");
    crossProduct(B, A, crossBA);
    printf("   B × A = "); printVector(crossBA); printf("\n");
    
    // g. Norm dari A x B
    printf("\ng. Magnitudo Hasil Kali Silang:\n");
    printf("   ||A × B|| = %.2f\n", vectorNorm(crossAB));
    
    // h. Norm dari B x A
    printf("\nh. Magnitudo Hasil Kali Silang:\n");
    printf("   ||B × A|| = %.2f\n", vectorNorm(crossBA));
    
    printf("\n==================================================\n");
    printf("PROGRAM SELESAI\n");
    printf("==================================================\n");
    
    return 0;
}