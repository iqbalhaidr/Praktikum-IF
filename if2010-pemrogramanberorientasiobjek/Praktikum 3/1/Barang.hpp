#ifndef BARANG_HPP
#define BARANG_HPP

#include <string>
using namespace std;

class Barang
{
protected:
    string nama;
    int berat; // dalam kg
public:
    /*
        Constructor Barang
        nama: nama barang
        berat: berat barang
    */
    Barang(string nama, int berat);

    virtual ~Barang();

    string getNama() const;
    int getBerat() const;

    /*
        Mendapatkan jenis barang. Di-override oleh kelas turunan.
    */
    virtual string getJenis() const = 0;
};

#endif