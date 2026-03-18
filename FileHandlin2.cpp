#include <stdio.h>
#include <string.h>
typedef struct {
    char NPM[10];
    char Nama[51];
} Mahasiswa;

int main() {
    Mahasiswa ListMhs [3];
    strcpy ( ListMhs [0]. NPM, "5350001");
    strcpy ( ListMhs [0].Nama, "Mhs 1");
    strcpy ( ListMhs [0]. NPM, "5350002");
    strcpy ( ListMhs [0].Nama, "Mhs 2");
    strcpy ( ListMhs [0]. NPM, "5350003");
    strcpy ( ListMhs [0].Nama, "Mhs 3");

    listmhs {"npm1","nama1","npm2","nama2"}
    
FILE *FileMahasiswaWrite;
FileMahasiswaWrite = fopen ("ListMhs.txt", "wb");

fwrite (&ListMhs, sizeof (Mahasiswa), 2, FileMahasiswaWrite);
fclose (FileMahasiswaWrite);


    FILE *FileMahasiswaRead;
    FileMahasiswaRead = fopen("ListMhsNew.txt", "r");

    Mahasiswa ReadListMhs[3];

    fread(&ReadListMhs, sizeof(Mahasiswa), 3, FileMahasiswaRead);
    fclose(FileMahasiswaRead);
    
    for(int i = 0; i < 3; i++){
        printf("%s\t%s\n", ReadListMhs[i].NPM, ReadListMhs[i].Nama);
    }
    
    return 0;
}