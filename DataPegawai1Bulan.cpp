#include <stdio.h>
#include <string.h>

#define MAX 100

struct Penjualan {
    int unit;
    long nominal;
};

struct Pegawai {
    int nomor;
    char namaDepan[50];
    char namaBelakang[30];
    struct Penjualan minggu[4];
    long totalPenjualan;
    long komisi;
    long gajiAkhir;
};

void hitungSemua(struct Pegawai *p) {
    p->totalPenjualan = 0;
    for (int i = 0; i < 4; i++) {
        p->totalPenjualan += p->minggu[i].nominal;
    }
    p->komisi = p->totalPenjualan * 0.02;
    p->gajiAkhir = 3000000 + p->komisi;

    if (p->totalPenjualan > 500000000) {
        p->gajiAkhir += 2000000;
    }
}

// SUB ALGORITMA a -> komisi tertinggi
void komisiTertinggi(struct Pegawai p[], int n) {
    long maks = -1;
    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (p[i].komisi > maks) {
            maks = p[i].komisi;
            idx = i;
        }
    }

    printf("\nPegawai dengan komisi TERTINGGI:\n");
    printf("%s %s -> Komisi: %ld\n", p[idx].namaDepan, p[idx].namaBelakang, p[idx].komisi);
}

// SUB ALGORITMA b -> komisi terendah
void komisiTerendah(struct Pegawai p[], int n) {
    long min = p[0].komisi;
    int idx = 0;

    for (int i = 1; i < n; i++) {
        if (p[i].komisi < min) {
            min = p[i].komisi;
            idx = i;
        }
    }

    printf("\nPegawai dengan komisi TERENDAH:\n");
    printf("%s %s -> Komisi: %ld\n", p[idx].namaDepan, p[idx].namaBelakang, p[idx].komisi);
}

// SUB ALGORITMA c -> urutkan berdasarkan total penjualan tertinggi
void urutkanPenjualan(struct Pegawai p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].totalPenjualan > p[i].totalPenjualan) {
                struct Pegawai temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// SUB ALGORITMA d -> pegawai tanpa penjualan
void tampilTanpaPenjualan(struct Pegawai p[], int n) {
    printf("\nPegawai TANPA penjualan (bulan ini):\n");
    int ada = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].totalPenjualan == 0) {
            printf("- %s %s\n", p[i].namaDepan, p[i].namaBelakang);
            ada = 1;
        }
    }

    if (!ada) {
        printf("Semua pegawai memiliki penjualan.\n");
    }
}

int main() {
    int n;
    struct Pegawai p[MAX];

    printf("Jumlah pegawai: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n=== INPUT PEGAWAI %d ===\n", i + 1);

        printf("Nomor Pegawai: ");
        scanf("%d", &p[i].nomor);

        printf("Nama Depan: ");
        scanf(" %[^\n]", p[i].namaDepan);

        printf("Nama Belakang: ");
        scanf("%s", p[i].namaBelakang);

        for (int m = 0; m < 4; m++) {
            printf("\n Minggu %d:\n", m + 1);
            printf("   Jumlah unit terjual: ");
            scanf("%d", &p[i].minggu[m].unit);

            printf("   Total nominal penjualan: ");
            scanf("%ld", &p[i].minggu[m].nominal);
        }

        hitungSemua(&p[i]);
    }

    printf("\n========================");
    printf("\nDATA PEGAWAI (1 BULAN)\n");
    printf("========================\n");

    for (int i = 0; i < n; i++) {
        printf("\n%s %s\n", p[i].namaDepan, p[i].namaBelakang);
        printf("Total Penjualan: %ld\n", p[i].totalPenjualan);
        printf("Komisi: %ld\n", p[i].komisi);
        printf("Gaji Akhir: %ld\n", p[i].gajiAkhir);
    }

    komisiTertinggi(p, n);
    komisiTerendah(p, n);

    urutkanPenjualan(p, n);

    printf("\nUrutan Pegawai berdasarkan penjualan tertinggi:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s -> %ld\n", p[i].namaDepan, p[i].namaBelakang, p[i].totalPenjualan);
    }

    tampilTanpaPenjualan(p, n);

    return 0;
}