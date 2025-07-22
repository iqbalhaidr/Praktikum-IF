#include "BarangMakanan.hpp"

BarangMakanan::BarangMakanan(string nama, int berat, int hariKedaluwarsa) : Barang(nama, berat), hariKedaluwarsa(hariKedaluwarsa) {}

int BarangMakanan::getHariKedaluwarsa() const { return hariKedaluwarsa; }

string BarangMakanan::getJenis() const { return "Makanan"; }