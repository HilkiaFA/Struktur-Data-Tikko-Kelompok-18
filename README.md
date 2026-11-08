# GoWisata - Sistem Manajemen Tiket Pengunjung Tempat Wisata

**Tahap 1: Struktur Data Linier (Single Linked List, Sequential Search, & Selection Sort)**  
_Mata Kuliah: Struktur Data | Kelompok 18 (Kelas IF-13)_  
_Dosen Pengampu: Rakhmad Maulidi, S.Kom., M.Kom_

---

## Deskripsi Proyek

Aplikasi konsol **GoWisata** dikembangkan menggunakan bahasa C++ dengan menerapkan pola **Abstract Data Type (ADT) Prosedural** sesuai standar Modul Praktikum Struktur Data Fakultas Informatika (School of Computing) Telkom University.

Pada **Tahap 1**, sistem berfokus pada struktur data **Single Linked List** untuk menyimpan data tiket dan pengunjung, dilengkapi algoritma pencarian **Sequential Search** ($O(n)$) dan pengurutan **Selection Sort** ($O(n^2)$).

---

## Penerapan ADT Single Linked List

1. **`infotypeTiket`**: Record pembungkus data tiket:
   - `nomor` : nomor tiket unik (mulai dari 1001)
   - `nama` : nama pengunjung
   - `kategori` : 1 (Dewasa) atau 2 (Anak-anak)
   - `jumlah` : jumlah tiket yang dibeli
   - `total` : total nominal pembayaran
   - `terpakai` : boolean status tiket
2. **`address`**: Pointer ke elemen list (`typedef struct elmlist *address;`).
3. **`elmlist`**: Elemen simpul berisi `infotypeTiket info;` dan `address next;`.
4. **`ListTiket`**: Tipe pembungkus list dengan pointer `first` dan `last`.
5. **Primitif ADT Standar**:
   - `createList(ListTiket &L)` : inisialisasi list kosong (`first = Nil`, `last = Nil`).
   - `alokasi(infotypeTiket X)` : mengalokasikan memori dinamis untuk elemen baru menggunakan `new`.
   - `dealokasi(address P)` : membebaskan memori simpul dengan `delete`.
   - `insertLast(ListTiket &L, address P)` : menyisipkan simpul di akhir list ($O(1)$).
   - `findElm(ListTiket L, int nomor)` : Sequential Search menelusuri list ($O(n)$).
   - `urutkanTiket(ListTiket &L, int mode)` : Selection Sort berdasarkan Nomor, Nama, atau Kategori.
   - `printInfo(ListTiket L)` : penelusuran (traversal) untuk menampilkan seluruh isi list.
   - `dealokasiSemua(ListTiket &L)` : membebaskan seluruh elemen sebelum program keluar.

---

## Struktur Berkas

```text
./
│
├── main.cpp
├── fitur.h
├── fitur.cpp
├── daftartiket.h
├── daftartiket.cpp
├── util.h
├── util.cpp
└── README.md
```

---

## Cara Kompilasi & Menjalankan

```powershell
# Kompilasi
g++ -o gowisata.exe main.cpp util.cpp daftartiket.cpp fitur.cpp

# Jalankan
.\gowisata.exe
```

---

## Panduan Fitur Menu

```text
==============================
   GOWISATA - MANAJEMEN TIKET
     (Tahap 1: Linked List)
==============================
1. Pembelian Tiket
2. Pencarian Tiket
3. Data Tiket & Pengurutan
4. Tutup Aplikasi
Pilih menu (1-4):
```

1. **Menu 1 - Pembelian Tiket **:
   - Input nama pengunjung, pilih kategori (1=Dewasa: Rp 25.000 / 2=Anak: Rp 15.000), dan jumlah tiket.
   - Total harga dihitung otomatis dan uang pembayaran divalidasi.
   - Elemen dialokasikan (`alokasi`) dan disisipkan di akhir list (`insertLast`).
2. **Menu 2 - Pencarian Tiket (Sequential Search $O(n)$)**:
   - Mencari nomor tiket pada list dengan fungsi primitif `findElm`.
   - Menampilkan rincian tiket beserta statusnya.
3. **Menu 3 - Data Tiket & Pengurutan (Selection Sort $O(n^2)$)**:
   - Opsi 1: Nomor Tiket (Ascending).
   - Opsi 2: Nama Pengunjung (Alfabetis A-Z).
   - Opsi 3: Kategori Tiket (Dewasa didahulukan).
   - Opsi 0: Tampilkan data apa adanya.
4. **Menu 4 - Tutup Aplikasi**:
   - Membersihkan seluruh memori linked list dengan `dealokasiSemua` dan keluar dari program.
