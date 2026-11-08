#include "fitur.h"
#include "util.h"
#include <iostream>

static int nomorBerikut = 1001;

void pembelianTiket(ListTiket &L) {
    cout << "\n=== PEMBELIAN TIKET ===\n";
    cout << "Harga Dewasa: Rp" << HARGA_DEWASA << " | Anak-anak: Rp" << HARGA_ANAK << "\n";
    cout << "Nama pengunjung   : ";
    string nama;
    getline(cin, nama);
    if (nama.empty()) {
        cout << "Nama tidak boleh kosong.\n";
        return;
    }
    int kategori = bacaAngka("Kategori (1=Dewasa, 2=Anak-anak): ");
    if (kategori != 1 && kategori != 2) {
        cout << "Kategori tidak valid.\n";
        return;
    }
    int jumlah = bacaAngka("Jumlah tiket      : ");
    if (jumlah <= 0) {
        cout << "Jumlah harus lebih dari 0.\n";
        return;
    }
    int harga = (kategori == 1) ? HARGA_DEWASA : HARGA_ANAK;
    int total = harga * jumlah;
    cout << "Total harga      : Rp" << total << "\n";
    int bayar = bacaAngka("Uang pembayaran  : Rp");
    if (bayar < total) {
        cout << "Pembayaran kurang. Transaksi dibatalkan.\n";
        return;
    }

    infotypeTiket dataTiketBaru;
    dataTiketBaru.nomor = nomorBerikut++;
    dataTiketBaru.nama = nama;
    dataTiketBaru.kategori = kategori;
    dataTiketBaru.jumlah = jumlah;
    dataTiketBaru.total = total;
    dataTiketBaru.terpakai = false;

    address pTiket = alokasi(dataTiketBaru);
    insertLast(L, pTiket);

    cout << "Pembayaran berhasil! Kembalian: Rp" << (bayar - total) << "\n";
    cout << "Nomor tiket Anda: " << dataTiketBaru.nomor << "\n";
}

void pencarianTiket(ListTiket L) {
    cout << "\n=== PENCARIAN TIKET ===\n";
    int nomor = bacaAngka("Masukkan nomor tiket: ");
    address t = findElm(L, nomor);
    if (t == Nil) {
        cout << "Tiket tidak ditemukan.\n";
        return;
    }
    cout << "Tiket ditemukan!\n";
    cout << "Nomor    : " << t->info.nomor << "\n";
    cout << "Nama     : " << t->info.nama << "\n";
    cout << "Kategori : " << namaKategori(t->info.kategori) << "\n";
    cout << "Jumlah   : " << t->info.jumlah << "\n";
    cout << "Total    : Rp" << t->info.total << "\n";
    cout << "Status   : " << (t->info.terpakai ? "Sudah dipakai" : "Belum dipakai") << "\n";
}

void dataTiket(ListTiket &L) {
    cout << "\n=== DATA TIKET ===\n";
    cout << "Urutkan berdasarkan:\n";
    cout << "1. Nomor tiket\n";
    cout << "2. Nama pengunjung\n";
    cout << "3. Kategori tiket\n";
    cout << "0. Tampilkan tanpa diurutkan\n";
    int mode = bacaAngka("Pilih: ");
    if (mode >= 1 && mode <= 3) {
        urutkanTiket(L, mode);
    }
    printInfo(L);
}
