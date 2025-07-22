#include <iostream>

#include "BarangElektronik.hpp"
#include "BarangMakanan.hpp"
#include "Gudang.hpp"

using namespace std;

int main() {
    Gudang g;
    BarangMakanan bm("roti", 10, 0);
    BarangElektronik be("laptop", 5, 6);
    BarangElektronik s("besar", 10000, 200);

    cout << "bm kad: " << bm.getHariKedaluwarsa() << endl;
    cout << "bm ber: " << bm.getBerat() << endl;
    cout << "bm jenis: " << bm.getJenis() << endl;
    cout << "bm nama: " << bm.getNama() << endl;

    cout << "be kad: " << be.getVoltase() << endl;
    cout << "be ber: " << be.getBerat() << endl;
    cout << "be jenis: " << be.getJenis() << endl;
    cout << "be nama: " << be.getNama() << endl;

    g.simpanBarang(&bm);
    // g.pakaiUang(900);
    // g.pakaiTenagaKerja();
    // g.pakaiTenagaKerja();
    // g.pakaiTenagaKerja();
    // g.pakaiTenagaKerja();
    g.simpanBarang(&be);
    g.tambahKapasitas(100);
    g.tambahTenagaKerja(10);
    g.tambahUang(1800);
    // g.simpanBarang(&s);
    g.sebutBarang(0);
    g.~Gudang();
    g.statusGudang();

    return 0;
}