#include <stdio.h>
#include <stdlib.h>
void Angka (int *input)
{
    printf("Masukkan angka: ");
    scanf ("%d", &*input);

}
void Double (int  *nilai)
{
*nilai = *nilai *2;
}

int main() {
    
    int num;
    Angka(&num);
    Double (&num);
    printf( "Nilai setelah dikalikan 2: %d\n", num);
    return 0;
}