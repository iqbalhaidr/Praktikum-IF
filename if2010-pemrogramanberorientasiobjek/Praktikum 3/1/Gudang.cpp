#include "Gudang.hpp"
#include "Exception.hpp"
#include "BarangMakanan.hpp"
#include <iostream>

/*
    Membuat objek Gudang dengan kapasitas, uang, tenaga kerja default.
*/
Gudang::Gudang() : kapasitasTotal(DEFAULT_KAPASITAS), kapasitasTerpakai(0), tenagaKerja(DEFAULT_TENAGA_KERJA), uang(DEFAULT_UANG) {}

/*
    Membuat objek Gudang dengan kapasitas, uang, tenaga kerja sesuai argumen.
*/
Gudang::Gudang(int kapasitas, int uang, int tenagaKerja) : kapasitasTotal(kapasitas), kapasitasTerpakai(0), tenagaKerja(tenagaKerja), uang(uang) {}

/*
    Menghancurkan Gudang. Pastikan semua pointer barang dihapus (delete).
*/
Gudang::~Gudang() {
  for (int i = 0; i < daftarBarang.size(); i++) {
    delete daftarBarang[i];
  }
}

/*
    Menambahkan barang ke dalam gudang.
    - Setiap barang membutuhkan:
        kapasitas = berat barang
        uang = 100 per barang
        1 tenaga kerja

    - Jika barang makanan dan sudah kedaluwarsa (hariKedaluwarsa <= 0), lempar BarangKedaluwarsaException, dan tampilkan pesan: "Barang makanan sudah kadaluwarsa, buang dulu."
    - Jika kapasitas tidak cukup, lempar KapasitasPenuhException, tampilkan: "Kapasitas tidak cukup, perluas gudang dulu."
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
void Gudang::simpanBarang(Barang *barang) {
  try {
    if (barang->getJenis() == "Makanan") {
      BarangMakanan *b = dynamic_cast<BarangMakanan*>(barang);
      if (b->getHariKedaluwarsa() <= 0) {
        throw BarangKedaluwarsaException();
      }
    }

    pakaiKapasitas(barang->getBerat());
    pakaiUang(100);
    pakaiTenagaKerja();

    daftarBarang.push_back(barang);
    cout << "Barang " << "[" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
  
  } catch (BarangKedaluwarsaException e) {
    cout << e.what() << ", buang dulu." << endl;
  } catch (KapasitasPenuhException k) {
    cout << k.what() << ", perluas gudang dulu." << endl;
  } catch (UangTidakCukupException u) {
    cout << u.what() << ", cari pemasukan dulu." << endl;
    kapasitasTerpakai -= barang->getBerat();
  } catch (TenagaKerjaTidakCukupException t) {
    cout << t.what() << ", rekrut dulu." << endl;
    kapasitasTerpakai -= barang->getBerat();
    tambahUang(100);
  }
}

/*
    Menambahkan kapasitas gudang
*/
void Gudang::tambahKapasitas(int kg) {
  kapasitasTotal += kg;
}

/*
    Menambahkan tenaga kerja
*/
void Gudang::tambahTenagaKerja(int jumlah) {
  tenagaKerja += jumlah;
}

/*
    Menambahkan uang
*/
void Gudang::tambahUang(int jumlah) {
  uang += jumlah;
}

/*
    Menggunakan kapasitas (lempar KapasitasPenuhException jika tidak cukup)
*/
void Gudang::pakaiKapasitas(int kg) {
  if ((kapasitasTerpakai + kg) > kapasitasTotal) {
    throw KapasitasPenuhException();
  }

  kapasitasTerpakai += kg;
}

/*
    Menggunakan uang (lempar UangTidakCukupException jika tidak cukup)
*/
void Gudang::pakaiUang(int jumlah) {
  if (jumlah > uang) {
    throw UangTidakCukupException();
  }

  uang -= jumlah;
}

/*
    Menggunakan tenaga kerja (1 pekerja), lempar TenagaKerjaTidakCukupException jika tidak cukup
*/
void Gudang::pakaiTenagaKerja() {
  if (tenagaKerja < 1) {
    throw TenagaKerjaTidakCukupException();
  }

  tenagaKerja--;
}

/*
    Menyebut barang di index tertentu. Tampilkan:
    "<nama> - <jenis> - <berat>kg"
    Jika index tidak valid, tampilkan exception bawaan C++ diakhiri newline.
*/
void Gudang::sebutBarang(int idx) {
  try {
    Barang* b = daftarBarang.at(idx);
    cout << b->getNama() << " - " << b->getJenis() << " - " << b->getBerat() << "kg" << endl;
  } catch (const out_of_range &err) {
    cout << err.what() << endl;
  }
}

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
void Gudang::statusGudang() const {
  cout << "Status gudang:" << endl;
  cout << "  Kapasitas total: " << kapasitasTotal << " kg" << endl;
  cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg" << endl;
  cout << "  Uang: " << uang << endl;
  cout << "  Tenaga kerja: " << tenagaKerja << endl;
  cout << "  Barang:" << endl;
  for (int i = 0; i < daftarBarang.size(); i++) {
    Barang* b = daftarBarang.at(i);
    cout << "    [" << i << "] ";
    cout << b->getNama() << " - " << b->getJenis() << " - " << b->getBerat() << "kg" << endl;
  }
}