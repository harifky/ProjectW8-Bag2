#ifndef RIFHEADER_H
#define RIFHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 10
#define MAX_STRING 100

typedef char infotype[MAX_STRING];

typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype nm;
    address q;
} ElmtList;

typedef struct tKota *addressKt;
typedef struct tKota {
	infotype kt;
	addressKt p;
	address r;
} Kota;

// Fungsi alokasi
address EntryAddress();
addressKt EntryAddressKt();

// Fungsi manipulasi nama dalam satu kota
void EntryNamaAwal(address *head, const char *nama);
void EntryNamaAkhir(address *head, const char *nama);
void EntryNamaAfter(address *head, const char *namaBaru, const char *namaSebelum);
void DelNm(address *head, const char *nama);

// Fungsi manipulasi kota
void EntryKotaAwal(addressKt *headKt, const char *namaKota);
void EntryKotaAkhir(addressKt *headKt, const char *namaKota);
void EntryKotaAfter(addressKt *headKt, const char *namaKotaBaru, const char *namaKotaSebelum);
void DelKt(addressKt *headKt, const char *namaKota);

// Fungsi utility
void PrintNmprtKt(addressKt headKt);
addressKt CariKota(addressKt headKt, const char *namaKota);
void tampilkanKotaTersedia(addressKt headKt);
void tampilkanNamaTersedia(addressKt headKt);

#endif