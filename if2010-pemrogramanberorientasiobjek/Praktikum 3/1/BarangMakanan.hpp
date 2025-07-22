#ifndef BARANG_MAKANAN_HPP
#define BARANG_MAKANAN_HPP

#include "Barang.hpp"

class BarangMakanan : public Barang
{
private:
    int hariKedaluwarsa; // hari sampai kadaluwarsa
public:
    /*
        Constructor BarangMakanan
        nama: nama barang
        berat: berat barang
        hariKedaluwarsa: berapa hari lagi sampai kedaluwarsa
    */
    BarangMakanan(string nama, int berat, int hariKedaluwarsa);

    int getHariKedaluwarsa() const;
    string getJenis() const override;
};

#endif