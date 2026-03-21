#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_KENDARAAN 3
#define TARIF_DASAR 5000
#define BATAS_DISKON_JAM 5
#define FAKTOR_DISKON 0.9
#define EASTER_EGG_MIN 33000000
#define EASTER_EGG_MAX 34000000


typedef enum {
    JENIS_MOBIL = 1,
    JENIS_MOTOR = 2,
    JENIS_TRUK = 3
} JenisKendaraan;

typedef struct {
    JenisKendaraan jenis;
    int lamaParkir;      // dalam jam
    int biaya;
} Kendaraan;

typedef struct {
    char namaPelanggan[50];
    Kendaraan daftarKendaraan[MAX_KENDARAAN];
    int jumlahKendaraan;
    int totalBiaya;
} TransaksiParkir;



static double getTarifMultiplier(JenisKendaraan jenis) {
    switch (jenis) {
        case JENIS_MOBIL: return 1.0;
        case JENIS_MOTOR: return 0.5;
        case JENIS_TRUK:  return 2.0;
        default:          return 0.0;
    }
}

static const char* getNamaJenisKendaraan(JenisKendaraan jenis) {
    switch (jenis) {
        case JENIS_MOBIL: return "Mobil";
        case JENIS_MOTOR: return "Motor";
        case JENIS_TRUK:  return "Truk";
        default:          return "Tidak Dikenal";
    }
}

int hitungBiayaKendaraan(JenisKendaraan jenis, int lamaJam) {
    double tarif = getTarifMultiplier(jenis);
    if (tarif == 0.0) return 0; 
    
    int biaya = (int)(TARIF_DASAR * tarif * lamaJam);
    
    if (lamaJam > BATAS_DISKON_JAM) {
        biaya = (int)(biaya * FAKTOR_DISKON);
    }
    return biaya;
}



void transaksi_tambahKendaraan(TransaksiParkir *trx, int index, 
                               JenisKendaraan jenis, int lamaJam) {
    if (index < 0 || index >= trx->jumlahKendaraan) return;
    
    trx->daftarKendaraan[index].jenis = jenis;
    trx->daftarKendaraan[index].lamaParkir = lamaJam;
    trx->daftarKendaraan[index].biaya = hitungBiayaKendaraan(jenis, lamaJam);
}

int transaksi_hitungTotal(TransaksiParkir *trx) {
    int total = 0;
    for (int i = 0; i < trx->jumlahKendaraan; i++) {
        total += trx->daftarKendaraan[i].biaya;
    }
    trx->totalBiaya = total;
    return total;
}


void file_buatStruk(const TransaksiParkir *trx) {
    char filename[100];
    snprintf(filename, sizeof(filename), "struk_%s.txt", trx->namaPelanggan);
    
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Gagal membuat file %s\n", filename);
        return;
    }
    
    fprintf(file, "======================================\n");
    fprintf(file, "       STRUK PEMBAYARAN PARKIR\n");
    fprintf(file, "======================================\n");
    fprintf(file, "Nama Pelanggan   : %s\n", trx->namaPelanggan);
    fprintf(file, "Jumlah Kendaraan : %d\n", trx->jumlahKendaraan);
    fprintf(file, "--------------------------------------\n");
    
    for (int i = 0; i < trx->jumlahKendaraan; i++) {
        const Kendaraan *k = &trx->daftarKendaraan[i];
        fprintf(file, "Kendaraan %-2d     : %s\n", i+1, getNamaJenisKendaraan(k->jenis));
        fprintf(file, "Lama Parkir       : %d jam\n", k->lamaParkir);
        fprintf(file, "Biaya             : Rp %d\n", k->biaya);
        fprintf(file, "--------------------------------------\n");
    }
    
    fprintf(file, "TOTAL YANG HARUS DIBAYAR : Rp %d\n", trx->totalBiaya);
    fprintf(file, "======================================\n");
    fprintf(file, "Terima kasih telah menggunakan layanan kami!\n");
    
    fclose(file);
}



int input_jumlahKendaraan() {
    int jumlah;
    printf("Masukkan jumlah kendaraan (maks %d) : ", MAX_KENDARAAN);
    scanf("%d", &jumlah);
    return jumlah;
}

JenisKendaraan input_jenisKendaraan(int urutan) {
    int jenis;
    printf("\nKendaraan ke-%d\n", urutan);
    printf("Jenis (1=Mobil, 2=Motor, 3=Truk) : ");
    scanf("%d", &jenis);
    return (JenisKendaraan)jenis;
}

int input_lamaParkir() {
    int lama;
    printf("Lama parkir (jam)                 : ");
    scanf("%d", &lama);
    return lama;
}

void cekEasterEgg(int totalBiaya) {
    if (totalBiaya >= EASTER_EGG_MIN && totalBiaya < EASTER_EGG_MAX) {
        printf("\n*** The eternal recurrence has begun ***\n");
    }
}

int main() {
    TransaksiParkir transaksi = {0}; 
    printf("=== SISTEM PARKIR ===\n\n");
    printf("Masukkan nama pelanggan : ");
    scanf(" %[^\n]", transaksi.namaPelanggan);
    
    transaksi.jumlahKendaraan = input_jumlahKendaraan();
    
    if (transaksi.jumlahKendaraan < 1 || transaksi.jumlahKendaraan > MAX_KENDARAAN) {
        printf("Jumlah kendaraan tidak valid (harus 1-%d).\n", MAX_KENDARAAN);
        return 1;
    }
    
    
    for (int i = 0; i < transaksi.jumlahKendaraan; i++) {
        JenisKendaraan jenis = input_jenisKendaraan(i+1);
        int lama = input_lamaParkir();
        transaksi_tambahKendaraan(&transaksi, i, jenis, lama);
    }
    
  
    transaksi_hitungTotal(&transaksi);
    
    
    file_buatStruk(&transaksi);
    
    printf("\nStruk telah disimpan ke file: struk_%s.txt\n", transaksi.namaPelanggan);
    printf("Silakan buka file ters  `ebut untuk melihat detail pembayaran.\n");
    
    return 0;
}