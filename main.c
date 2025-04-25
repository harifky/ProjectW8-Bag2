#include <stdio.h>
#include <string.h>

#include "rifheader.h"

void tampilkanMenu() {
    printf("\n==================== MENU UTAMA ====================\n");
    printf("1. Entry Kota\n");
    printf("2. Entry Nama\n");
    printf("3. Delete Kota\n");
    printf("4. Delete Nama\n");
    printf("0. Keluar\n");
    printf("====================================================\n");
    printf("Pilihan: ");
}

int main() {
    addressKt daftarKota = NULL;
    int pilihan, sub;
    char kota[MAX_STRING], nama[MAX_STRING], target[MAX_STRING];

    do {
        // Menampilkan Daftar Kota dan Daftar Nama sebelum menu
        tampilkanKotaTersedia(daftarKota);
        tampilkanNamaTersedia(daftarKota);

        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); // hapus newline

        switch (pilihan) {
            case 1: // Entry Kota
                printf("\n--- Entry Kota ---\n");
                printf("Nama kota: ");
                fgets(kota, MAX_STRING, stdin);
                kota[strcspn(kota, "\n")] = '\0';
                printf("1. Awal\n2. Akhir\n3. Setelah kota tertentu\nPilihan: ");
                scanf("%d", &sub); getchar();

                if (sub == 1)
                    EntryKotaAwal(&daftarKota, kota);
                else if (sub == 2)
                    EntryKotaAkhir(&daftarKota, kota);
                else if (sub == 3) {
                    tampilkanKotaTersedia(daftarKota);
                    printf("Setelah kota: ");
                    fgets(target, MAX_STRING, stdin);
                    target[strcspn(target, "\n")] = '\0';
                    EntryKotaAfter(&daftarKota, kota, target);
                } else {
                    printf("Pilihan tidak valid.\n");
                }
                printf("----------------------------------------------------\n");
                break;

            case 2: // Entry Nama
                printf("\n--- Entry Nama ---\n");
                tampilkanKotaTersedia(daftarKota);
                printf("Masukkan nama kota: ");
                fgets(kota, MAX_STRING, stdin);
                kota[strcspn(kota, "\n")] = '\0';

                addressKt kt = CariKota(daftarKota, kota);
                if (kt == NULL) {
                    printf("Kota tidak ditemukan!\n");
                    break;
                }

                printf("Nama: ");
                fgets(nama, MAX_STRING, stdin);
                nama[strcspn(nama, "\n")] = '\0';

                printf("1. Awal\n2. Akhir\n3. Setelah nama tertentu\nPilihan: ");
                scanf("%d", &sub); getchar();

                if (sub == 1)
                    EntryNamaAwal(&kt->r, nama);
                else if (sub == 2)
                    EntryNamaAkhir(&kt->r, nama);
                else if (sub == 3) {
                    printf("Setelah nama: ");
                    fgets(target, MAX_STRING, stdin);
                    target[strcspn(target, "\n")] = '\0';
                    EntryNamaAfter(&kt->r, nama, target);
                } else {
                    printf("Pilihan tidak valid.\n");
                }
                printf("----------------------------------------------------\n");
                break;

            case 3: // Delete Kota
                printf("\n--- Delete Kota ---\n");
                tampilkanKotaTersedia(daftarKota);
                printf("Nama kota yang ingin dihapus: ");
                fgets(kota, MAX_STRING, stdin);
                kota[strcspn(kota, "\n")] = '\0';
                DelKt(&daftarKota, kota);
                printf("----------------------------------------------------\n");
                break;

            case 4: // Delete Nama
                printf("\n--- Delete Nama ---\n");
                tampilkanKotaTersedia(daftarKota);
                printf("Masukkan nama kota: ");
                fgets(kota, MAX_STRING, stdin);
                kota[strcspn(kota, "\n")] = '\0';
                kt = CariKota(daftarKota, kota);
                if (kt == NULL) {
                    printf("Kota tidak ditemukan!\n");
                    break;
                }

                // Menampilkan daftar nama yang terdaftar di kota
                printf("Daftar nama di kota %s:\n", kota);
                address namaList = kt->r;
                while (namaList != NULL) {
                    printf("[%s] ", namaList->nm);
                    namaList = namaList->q;
                }
                printf("\n");

                // Menghapus nama
                printf("Nama yang ingin dihapus: ");
                fgets(nama, MAX_STRING, stdin);
                nama[strcspn(nama, "\n")] = '\0';
                DelNm(&kt->r, nama);
                printf("----------------------------------------------------\n");
                break;

            case 0:
                printf("Terima kasih! Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}