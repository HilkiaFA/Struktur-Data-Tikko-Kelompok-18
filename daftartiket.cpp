#include "daftartiket.h"
#include "util.h"
#include <iostream>
#include <algorithm>

void createList(ListTiket &L)
{
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotypeTiket X)
{
    address P = new elmlist;
    P->info = X;
    P->next = Nil;
    return P;
}

void dealokasi(address P)
{
    delete P;
}

void insertLast(ListTiket &L, address P)
{
    P->next = Nil;
    if (L.first == Nil)
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        L.last->next = P;
        L.last = P;
    }
}

address findElm(ListTiket L, int nomor)
{
    address P = L.first;
    while (P != Nil)
    {
        if (P->info.nomor == nomor)
        {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

static bool lebihBesar(address a, address b, int mode)
{
    if (mode == 1)
        return a->info.nomor > b->info.nomor;
    if (mode == 2)
        return a->info.nama > b->info.nama;
    if (a->info.kategori != b->info.kategori)
    {
        return a->info.kategori > b->info.kategori;
    }
    return a->info.nomor > b->info.nomor;
}

void urutkanTiket(ListTiket &L, int mode)
{
    for (address i = L.first; i != Nil; i = i->next)
    {
        address minim = i;
        for (address j = i->next; j != Nil; j = j->next)
        {
            if (lebihBesar(minim, j, mode))
            {
                minim = j;
            }
        }
        if (minim != i)
        {
            swap(i->info, minim->info);
        }
    }
}

void printInfo(ListTiket L)
{
    if (L.first == Nil)
    {
        cout << "Belum ada data tiket.\n";
        return;
    }
    cout << "No.Tiket | Nama               | Kategori  | Jml | Total     | Status\n";
    cout << "------------------------------------------------------------------\n";
    address P = L.first;
    while (P != Nil)
    {
        cout << P->info.nomor << "     | "
             << P->info.nama << " | "
             << namaKategori(P->info.kategori) << " | "
             << P->info.jumlah << "   | "
             << "Rp" << P->info.total << " | "
             << (P->info.terpakai ? "Sudah dipakai" : "Belum dipakai") << "\n";
        P = P->next;
    }
}

void dealokasiSemua(ListTiket &L)
{
    address P = L.first;
    while (P != Nil)
    {
        address hapus = P;
        P = P->next;
        delete hapus;
    }
    L.first = Nil;
    L.last = Nil;
}
