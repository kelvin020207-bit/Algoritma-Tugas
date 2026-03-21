#include <stdio.h>

int main() {
    int barisA, kolomA, barisB, kolomB;
    int i, j, k;
    printf ( " ====== PROGRAM PERKALIAN MATRIKS ====== \n");
    printf("Masukkan jumlah baris matriks A: ");
    scanf("%d", &barisA);
    printf("Masukkan jumlah kolom matriks A: ");
    scanf("%d", &kolomA);

    printf("\nMasukkan jumlah baris matriks B: ");
    scanf("%d", &barisB);
    printf("Masukkan jumlah kolom matriks B: ");
    scanf("%d", &kolomB);

    if (kolomA != barisB) {
        printf("\nSyarat tidak terpenuhi!\n");
        printf("Jumlah kolom matriks A harus sama dengan jumlah baris matriks B.\n");
        return 0;
    }

    int A[barisA][kolomA], B[barisB][kolomB], C[barisA][kolomB];

    printf("\nMasukkan elemen matriks A:\n");
    for (i = 0; i < barisA; i++) {
        for (j = 0; j < kolomA; j++) {
            printf("Elemen A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nMasukkan elemen matriks B:\n");
    for (i = 0; i < barisB; i++) {
        for (j = 0; j < kolomB; j++) {
            printf("Elemen B[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < barisA; i++) {
        for (j = 0; j < kolomB; j++) {
            C[i][j] = 0;
        }
    }

    for (i = 0; i < barisA; i++) {
        for (j = 0; j < kolomB; j++) {
            for (k = 0; k < kolomA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nHasil Perkalian Matriks (A × B):\n");
    for (i = 0; i < barisA; i++) {
        for (j = 0; j < kolomB; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks A:\n");
    for (i = 0; i < barisA; i++) {
        for (j = 0; j < kolomA; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks B:\n");
    for (i = 0; i < barisB; i++) {
        for (j = 0; j < kolomB; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks Hasil (A × B):\n");
    for (i = 0; i < barisA; i++) {
        for (j = 0; j < kolomB; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}