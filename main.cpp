#include <iostream>
#include "util.h"
#include "daftartiket.h"
#include "fitur.h"

int main()
{
    ListTiket daftar;
    createList(daftar);

    int pilihan = 0;
    do
    {
        cout << "\n==============================\n";
        cout << "   GOWISATA - MANAJEMEN TIKET   \n";
        cout << "     (Tahap 1: Linked List)     \n";
        cout << "==============================\n";
        cout << "1. Pembelian Tiket\n";
        cout << "2. Pencarian Tiket\n";
        cout << "3. Data Tiket & Pengurutan\n";
        cout << "4. Tutup Aplikasi\n";
        pilihan = bacaAngka("Pilih menu (1-4): ");

        if (pilihan == 1)
        {
            pembelianTiket(daftar);
        }
        else if (pilihan == 2)
        {
            pencarianTiket(daftar);
        }
        else if (pilihan == 3)
        {
            dataTiket(daftar);
        }
        else if (pilihan == 4)
        {
            cout << "Terima kasih telah menggunakan GoWisata!\n";
        }
        else
        {
            cout << "Menu tidak valid, coba lagi.\n";
        }
    } while (pilihan != 4);

    dealokasiSemua(daftar);

    return 0;
}
