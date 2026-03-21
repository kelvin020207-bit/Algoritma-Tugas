#include <stdio.h>
int main () {
    int baris, kolom;
    int i, j;
    int sama = 1;
    printf ( " === Program Perhitungan Matriks Penjumlahan dan Pengurangan ======\n");
    printf( " Masukkan Jumlah Baris: ");
    scanf ( "%d", &baris);
    printf (" Masukkan Jumlah Kolom: ");
    scanf ( "%d", &kolom);
    int A [baris] [ kolom], B [baris] [kolom], jumlah [baris] [kolom], kurang [ baris] [kolom];
    
    printf ( " \nMasukkan elemen matriks A: \n");
    for ( i = 0; i < baris; i++) {
        for ( j =0; j < kolom; j++) {
printf ( " Elemen A [ %d] [%d]: ", i + 1, j + 1);
        scanf( "%d", &A[i] [j]);
        }
        
    }
    printf ( "\nMasukkan elemen matriks B: ");
     for ( i = 0; i < baris; i++) {
        for ( j=0; j < kolom; j++){
            printf ( " Elemen B [ %d] [%d]: ", i + 1, j + 1);
        scanf( "%d", &B[i] [j]);
}
        }
        
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            jumlah[i][j] = A[i][j] + B[i][j];
            kurang[i][j] = A[i][j] - B[i][j];

            if (A[i][j] != B[i][j]) {
                sama = 0; 
            }
        }
    }

    printf("\nHasil Penjumlahan (A + B):\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%d\t", jumlah[i][j]);
        }
        printf("\n");
    }

    printf("\nHasil Pengurangan (A - B):\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%d\t", kurang[i][j]);
        }
        printf("\n");
    }

    if (sama == 1)
        printf("\nKomentar: Matriks A = Matriks B\n");
    else
        printf("\nKomentar: Matriks A ≠ Matriks B\n");

    return 0;

        }