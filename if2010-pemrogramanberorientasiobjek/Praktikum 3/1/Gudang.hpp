#ifndef GUDANG_HPP
#define GUDANG_HPP

#include <vector>
#include "Barang.hpp"
using namespace std;

#define DEFAULT_KAPASITAS 100
#define DEFAULT_TENAGA_KERJA 5
#define DEFAULT_UANG 1000

class Gudang
{
private:
    vector<Barang *> daftarBarang;
    int kapasitasTotal; // kapasitas maksimum dalam kg
    int kapasitasTerpakai;
    int tenagaKerja; // jumlah pekerja yang tersedia
    int uang;        // dalam satuan ribuan (misal ribu rupiah)

public:
    /*
        Membuat objek Gudang dengan kapasitas, uang, tenaga kerja default.
    */
    Gudang();

    /*
        Membuat objek Gudang dengan kapasitas, uang, tenaga kerja sesuai argumen.
    */
    Gudang(int kapasitas, int uang, int tenagaKerja);

    /*
        Menghancurkan Gudang. Pastikan semua pointer barang dihapus (delete).
    */
    ~Gudang();

    /*
        Menambahkan barang ke dalam gudang.
        - Setiap barang membutuhkan:
            kapasitas = berat barang
            uang = 100 per barang
            1 tenaga kerja

        - Jika barang makanan dan sudah kedaluwarsa (hariKedaluwarsa <= 0), lempar BarangKedaluwarsaException, dan tampilkan pesan: "Barang makanan sudah kedaluwarsa, buang dulu."
        - Jika kapasitas tidak cukup, lempar KapasitasPenuhException, tampilkan: "Kapasitas gudang tidak mencukupi, perluas gudang dulu."
        - Jika uang tidak cukup, lempar UangTidakCukupException, tampilkan: "Uang tidak cukup, cari pemasukan dulu."
        - Jika tidak ada tenaga kerja, lempar TenagaKerjaTidakCukupException, tampilkan: "Tidak ada tenaga kerja, rekrut dulu."

        - Jika gagal, sumber daya tidak berkurang.

        - Jika berhasil, barang ditambahkan dan tampilkan:
          "Barang [<index>] <nama> berhasil disimpan"

        - Index dimulai dari 0
        - Gunakan dynamic cast untuk mendapatkan kadaluarsa dari BarangMakanan
        contoh: Class *x = dynamic_cast<Class *>(input)

        (semua output diakhiri newline)
    */
    void simpanBarang(Barang *barang);

    /*
        Menambahkan kapasitas gudang
    */
    void tambahKapasitas(int kg);

    /*
        Menambahkan tenaga kerja
    */
    void tambahTenagaKerja(int jumlah);

    /*
        Menambahkan uang
    */
    void tambahUang(int jumlah);

    /*
        Menggunakan kapasitas (lempar KapasitasPenuhException jika tidak cukup)
    */
    void pakaiKapasitas(int kg);

    /*
        Menggunakan uang (lempar UangTidakCukupException jika tidak cukup)
    */
    void pakaiUang(int jumlah);

    /*
        Menggunakan tenaga kerja (1 pekerja), lempar TenagaKerjaTidakCukupException jika tidak cukup
    */
    void pakaiTenagaKerja();

    /*
        Menyebut barang di index tertentu. Tampilkan:
        "<nama> - <jenis> - <berat>kg"

        Jika index tidak valid, tampilkan exception bawaan C++ diakhiri newline.
    */
    void sebutBarang(int idx);

    /*
        Menampilkan status gudang seperti:

        Status gudang:
          Kapasitas total: <kapasitasTotal> kg
          Kapasitas terpakai: <kapasitasTerpakai> kg
          Uang: <uang>
          Tenaga kerja: <tenagaKerja>
          Barang:
            [0] <nama> - <jenis> - <berat>kg
            ...
    */
    void statusGudang() const;
};

#endif