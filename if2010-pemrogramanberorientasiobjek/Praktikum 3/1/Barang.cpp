#include "Barang.hpp"

Barang::Barang(string nama, int berat) : nama(nama), berat(berat) {}

Barang::~Barang() {}

string Barang::getNama() const { return nama; }

int Barang::getBerat() const { return berat; }
