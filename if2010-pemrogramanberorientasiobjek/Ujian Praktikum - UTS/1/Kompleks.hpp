// Kelas Kompleks
// File: Kompleks.cpp
#ifndef _KOMPLEKS_HPP_
#define _KOMPLEKS_HPP_

#include <iostream>

using namespace std;

class Kompleks {
   private:
    double real;  // Nilai real
    double imag;  // Nilai imajiner
   public:
    Kompleks();                    // Nilai default 0 + 0i
    Kompleks(double r, double i);  // r + i*i
    Kompleks(const Kompleks& other);

    double getReal() const;
    double getImag() const;

    double setReal(double r);
    double setImag(double i);

    Kompleks operator+(const Kompleks& other) const;
    // Menambahkan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a + b = (1+3) + (2+4)i = 4 + 6i

    Kompleks operator-(const Kompleks& other) const;
    // Mengurangi dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a - b = (1-3) + (2-4)i = -2 - 2i

    Kompleks operator*(const Kompleks& other) const;
    // Mengalikan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a * b = 1*3 + 1*4i + 2i*3 + 2i*4i = 3 + 4i + 6i - 8 = -5 + 10i

    bool operator==(const Kompleks& other) const;
    // Membandingkan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a == b = (1==3) && (2==4) = false
    // Misal: a = 1 + 2i, b = 1 + 2i;
    // a == b = (1==1) && (2==2) = true

    Kompleks& operator=(const Kompleks& other);
    // Menyalin dua bilangan kompleks

    friend ostream& operator<<(ostream& os, const Kompleks& c);
    // Menampilkan bilangan kompleks
    // Note: Tidak menggunakan endl
    // Misal: Kompleks(1, 2)
    // cout << a << endl; // Output: 1 + 2i
    // Jika imajiner < 0; Misal: Kompleks(1, -2)
    // cout << a << endl; // Output: 1 - 2i
    // Jika nilai imajiner 0, jangan tampilkan i; Misal: Kompleks(1, 0)
    // cout << a << endl; // Output: 1
};
#endif
