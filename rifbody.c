#include "rifheader.h"

// Alokasi elemen nama
address EntryAddress() {
    address newNode = (address) malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        newNode->nm[0] = '\0'; // kosong dulu
        newNode->q = NULL;
    }
    return newNode;
}

// Alokasi elemen kota
addressKt EntryAddressKt() {
    addressKt newKota = (addressKt) malloc(sizeof(Kota));
    if (newKota != NULL) {
        newKota->kt[0] = '\0'; // kosong dulu
        newKota->p = NULL;
        newKota->r = NULL;
    }
    return newKota;
}

void EntryNamaAwal(address *head, const char *nama) {
    address newNode = EntryAddress();
    if (newNode != NULL) {
        strcpy(newNode->nm, nama);
        newNode->q = *head;
        *head = newNode;
    }
}

void EntryNamaAkhir(address *head, const char *nama) {
    address newNode = EntryAddress();
    if (newNode != NULL) {
        strcpy(newNode->nm, nama);
        newNode->q = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            address temp = *head;
            while (temp->q != NULL) {
                temp = temp->q;
            }
            temp->q = newNode;
        }
    }
}

void EntryNamaAfter(address *head, const char *namaBaru, const char *namaSebelum) {
    address temp = *head;
    while (temp != NULL && strcmp(temp->nm, namaSebelum) != 0) {
        temp = temp->q;
    }

    if (temp != NULL) {
        address newNode = EntryAddress();
        if (newNode != NULL) {
            strcpy(newNode->nm, namaBaru);
            newNode->q = temp->q;
            temp->q = newNode;
        }
    }
}

void DelNm(address *head, const char *nama) {
    address temp = *head;
    address prev = NULL;

    while (temp != NULL && strcmp(temp->nm, nama) != 0) {
        prev = temp;
        temp = temp->q;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            *head = temp->q;
        } else {
            prev->q = temp->q;
        }
        free(temp);
    }
}

void EntryKotaAwal(addressKt *headKt, const char *namaKota) {
    addressKt newKota = EntryAddressKt();
    if (newKota != NULL) {
        strcpy(newKota->kt, namaKota);
        newKota->p = *headKt;
        *headKt = newKota;
    }
}

void EntryKotaAkhir(addressKt *headKt, const char *namaKota) {
    addressKt newKota = EntryAddressKt();
    if (newKota != NULL) {
        strcpy(newKota->kt, namaKota);
        newKota->p = NULL;

        if (*headKt == NULL) {
            *headKt = newKota;
        } else {
            addressKt temp = *headKt;
            while (temp->p != NULL) {
                temp = temp->p;
            }
            temp->p = newKota;
        }
    }
}

void EntryKotaAfter(addressKt *headKt, const char *namaKotaBaru, const char *namaKotaSebelum) {
    addressKt temp = *headKt;
    while (temp != NULL && strcmp(temp->kt, namaKotaSebelum) != 0) {
        temp = temp->p;
    }

    if (temp != NULL) {
        addressKt newKota = EntryAddressKt();
        if (newKota != NULL) {
            strcpy(newKota->kt, namaKotaBaru);
            newKota->p = temp->p;
            temp->p = newKota;
        }
    }
}

void DelKt(addressKt *headKt, const char *namaKota) {
    addressKt temp = *headKt;
    addressKt prev = NULL;

    while (temp != NULL && strcmp(temp->kt, namaKota) != 0) {
        prev = temp;
        temp = temp->p;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            *headKt = temp->p;
        } else {
            prev->p = temp->p;
        }

        // Hapus semua nama dalam kota tersebut
        address curr = temp->r;
        while (curr != NULL) {
            address del = curr;
            curr = curr->q;
            free(del);
        }

        free(temp);
    }
}

void PrintNmprtKt(addressKt headKt) {
    while (headKt != NULL) {
        printf("Kota: %s\n", headKt->kt);
        address nama = headKt->r;
        int i = 1;
        while (nama != NULL) {
            printf("  %d. %s\n", i++, nama->nm);
            nama = nama->q;
        }
        headKt = headKt->p;
    }
}

addressKt CariKota(addressKt headKt, const char *namaKota) {
    while (headKt != NULL) {
        if (strcmp(headKt->kt, namaKota) == 0) {
            return headKt;
        }
        headKt = headKt->p;
    }
    return NULL;
}

void tampilkanKotaTersedia(addressKt headKt) {
    printf("\n----------------------------------------------------\n");
    printf("Kota tersedia: ");
    while (headKt != NULL) {
        printf("[%s] ", headKt->kt);
        headKt = headKt->p;
    }
    printf("\n----------------------------------------------------\n");
}

void tampilkanNamaTersedia(addressKt headKt) {
    printf("\n----------------------------------------------------\n");
    while (headKt != NULL) {
        if (headKt->r != NULL) {
            address nama = headKt->r;
            printf("Kota: %s -> Nama: ", headKt->kt);
            while (nama != NULL) {
                printf("%s ", nama->nm);
                nama = nama->q;
            }
            printf("\n");
        }
        headKt = headKt->p;
    }
    printf("----------------------------------------------------\n");
}