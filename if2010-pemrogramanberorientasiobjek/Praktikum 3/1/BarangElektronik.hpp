#ifndef BARANG_ELEKTRONIK_HPP
#define BARANG_ELEKTRONIK_HPP

#include "Barang.hpp"

class BarangElektronik : public Barang
{
private:
    int voltase;

public:
    BarangElektronik(string nama, int berat, int voltase);

    int getVoltase() const;
    string getJenis() const override;
};

#endif