#ifndef DAFTARTIKET_H
#define DAFTARTIKET_H

#define Nil NULL
#include <string>
using namespace std;

struct infotypeTiket {
    int nomor;
    string nama;
    int kategori;
    int jumlah;
    int total;
    bool terpakai;
};

typedef struct elmlist *address;

struct elmlist {
    infotypeTiket info;
    address next;
};

struct ListTiket {
    address first;
    address last;
};

void createList(ListTiket &L);
address alokasi(infotypeTiket X);
void dealokasi(address P);
void insertLast(ListTiket &L, address P);
address findElm(ListTiket L, int nomor);
void urutkanTiket(ListTiket &L, int mode);
void printInfo(ListTiket L);
void dealokasiSemua(ListTiket &L);

#endif
