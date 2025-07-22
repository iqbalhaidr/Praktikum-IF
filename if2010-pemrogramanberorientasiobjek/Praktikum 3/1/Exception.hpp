#ifndef CUSTOM_EXCEPTION_HPP
#define CUSTOM_EXCEPTION_HPP

#include <exception>
using namespace std;

struct KapasitasPenuhException : public exception
{
    const char *what() const throw()
    {
        return "Kapasitas gudang tidak mencukupi";
    }
};

struct BarangKedaluwarsaException : public exception
{
    const char *what() const throw()
    {
        return "Barang makanan sudah kedaluwarsa";
    }
};

struct TenagaKerjaTidakCukupException : public exception
{
    const char *what() const throw()
    {
        return "Tenaga kerja tidak cukup";
    }
};

struct UangTidakCukupException : public exception
{
    const char *what() const throw()
    {
        return "Uang tidak cukup";
    }
};

#endif