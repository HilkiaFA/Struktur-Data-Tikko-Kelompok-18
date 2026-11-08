#include "util.h"
#include <iostream>
#include <cstdlib>

int bacaAngka(const string& pesan) {
    while (true) {
        cout << pesan;
        string s;
        if (!getline(cin, s)) exit(0);
        try {
            size_t pos;
            int v = stoi(s, &pos);
            if (pos == s.size()) return v;
        } catch (...) {}
        cout << "Input harus berupa angka!\n";
    }
}

string namaKategori(int k) {
    return (k == 1) ? "Dewasa" : "Anak-anak";
}
