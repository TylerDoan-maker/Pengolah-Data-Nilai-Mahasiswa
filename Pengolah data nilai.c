#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MHS 50
#define MAX_NIM 22

char nim[MAX_MHS][MAX_NIM];
float nilai[MAX_MHS][3];
int jumlah_mhs = 0;

float hitung_total_rekursif(int index, int kolom) {
    if (index == jumlah_mhs) {
        return 0.0;
    }
    return nilai[index][kolom] + hitung_total_rekursif(index + 1, kolom);
}

void input_data() {
    printf("Masukkan jumlah mahasiswa: ", MAX_MHS);
    scanf("%d", &jumlah_mhs);
    if (jumlah_mhs > MAX_MHS) {
        printf("Jumlah mahasiswa melebihi batas!\n");
        jumlah_mhs = MAX_MHS;
    }

    for (int i = 0; i < jumlah_mhs; i++) {
        printf("\nMahasiswa %d:\n", i + 1);
        printf("NIM: ");
        scanf("%s", nim[i]);
        printf("Nilai Tugas: ");
        scanf("%f", &nilai[i][0]);
        printf("Nilai UTS: ");
        scanf("%f", &nilai[i][1]);
        printf("Nilai UAS: ");
        scanf("%f", &nilai[i][2]);
    }
    printf("Data berhasil diinput!\n");
}

void tampilkan_data() {
    if (jumlah_mhs == 0) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    printf("\nData Mahasiswa:\n");
    printf("No. | NIM          | Tugas | UTS | UAS\n");
    printf("----|--------------|-------|-----|----\n");
    for (int i = 0; i < jumlah_mhs; i++) {
        printf("%2d. | %-12s | %5.2f | %3.2f | %3.2f\n", i + 1, nim[i], nilai[i][0], nilai[i][1], nilai[i][2]);
    }
}

void ubah_data() {
    char cari_nim[MAX_NIM];
    printf("Masukkan NIM mahasiswa yang ingin diubah: ");
    scanf("%s", cari_nim);

    for (int i = 0; i < jumlah_mhs; i++) {
        if (strcmp(nim[i], cari_nim) == 0) {
            printf("Data ditemukan. Masukkan data baru:\n");
            printf("Nilai Tugas: ");
            scanf("%f", &nilai[i][0]);
            printf("Nilai UTS: ");
            scanf("%f", &nilai[i][1]);
            printf("Nilai UAS: ");
            scanf("%f", &nilai[i][2]);
            printf("Data berhasil diubah!\n");
            return;
        }
    }
    printf("NIM tidak ditemukan.\n");
}

void hapus_data() {
    char cari_nim[MAX_NIM];
    printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
    scanf("%s", cari_nim);

    for (int i = 0; i < jumlah_mhs; i++) {
        if (strcmp(nim[i], cari_nim) == 0) {
            for (int j = i; j < jumlah_mhs - 1; j++) {
                strcpy(nim[j], nim[j + 1]);
                nilai[j][0] = nilai[j + 1][0];
                nilai[j][1] = nilai[j + 1][1];
                nilai[j][2] = nilai[j + 1][2];
            }
            jumlah_mhs--;
            printf("Data berhasil dihapus!\n");
            return;
        }
    }
    printf("NIM tidak ditemukan.\n");
}

void hitung_nilai() {
    if (jumlah_mhs == 0) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    printf("\nPerhitungan Nilai:\n");
    float total_tugas = hitung_total_rekursif(0, 0);
    float total_uts = hitung_total_rekursif(0, 1);
    float total_uas = hitung_total_rekursif(0, 2);

    printf("Total Tugas: %.2f\n", total_tugas);
    printf("Rata-rata Tugas: %.2f\n", total_tugas / jumlah_mhs);
    printf("Total UTS : %.2f\n", total_uts);
    printf("Rata-rata UTS: %.2f\n", total_uts / jumlah_mhs);
    printf("Total UAS: %.2f\n", total_uas);
    printf("Rata-rata UAS: %.2f\n", total_uas / jumlah_mhs);

    printf("\nNilai Rata-Rata:\n");
    for (int i = 0; i < jumlah_mhs; i++) {
        float rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3.0;
        printf("%s: %.2f\n", nim[i], rata);
    }
}

int main() {
    int pilihan;

    do {
        printf("\n=== Program Pengolahan Nilai Mahasiswa ===\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Ubah Data Mahasiswa\n");
        printf("4. Hapus Data Mahasiswa\n");
        printf("5. Hitung Nilai\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                input_data();
                break;
            case 2:
                tampilkan_data();
                break;
            case 3:
                ubah_data();
                break;
            case 4:
                hapus_data();
                break;
            case 5:
                hitung_nilai();
                break;
            case 6:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);

    return 0;
}
