#include "Kompleks.hpp"

Kompleks::Kompleks() : real(0), imag(0) {}                    // Nilai default 0 + 0i
Kompleks::Kompleks(double r, double i) : real(r), imag(i) {}  // r + i*i
Kompleks::Kompleks(const Kompleks& other) : real(other.getReal()), imag(other.getImag()) {}

double Kompleks::getReal() const { return real; }
double Kompleks::getImag() const { return imag; }

double Kompleks::setReal(double r) { this->real = r; }
double Kompleks::setImag(double i) { this->imag = i; }

Kompleks Kompleks::operator+(const Kompleks& other) const {
    return Kompleks((real + other.getReal()), (imag + other.getImag()));
}
// Menambahkan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a + b = (1+3) + (2+4)i = 4 + 6i

Kompleks Kompleks::operator-(const Kompleks& other) const {
    return Kompleks((real - other.getReal()), (imag - other.getImag()));
}
// Mengurangi dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a - b = (1-3) + (2-4)i = -2 - 2i

Kompleks Kompleks::operator*(const Kompleks& other) const {
    double re = (real * other.getReal()) - (imag * other.getImag());
    double im = (real * other.getImag()) + (imag * other.getReal());
    return Kompleks(re, im);
}
// Mengalikan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a * b = 1*3 + 1*4i + 2i*3 + 2i*4i = 3 + 4i + 6i - 8 = -5 + 10i

bool Kompleks::operator==(const Kompleks& other) const {
    return (imag == other.getImag()) && (real == other.getReal());
}
// Membandingkan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a == b = (1==3) && (2==4) = false
// Misal: a = 1 + 2i, b = 1 + 2i;
// a == b = (1==1) && (2==2) = true

Kompleks& Kompleks::operator=(const Kompleks& other) {
    real = other.getReal();
    imag = other.getImag();
    return *this;
}
// Menyalin dua bilangan kompleks

ostream& operator<<(ostream& os, const Kompleks& c) {
    if (c.getImag() > 0) {
        os << c.getReal() << " + " << c.getImag() << "i";
    } else if (c.getImag() < 0) {
        os << c.getReal() << " - " << c.getImag() * -1 << "i";
    } else if (c.getImag() == 0) {
        os << c.getReal();
    }

    return os;
}
// Menampilkan bilangan kompleks
// Note: Tidak menggunakan endl
// Misal: Kompleks(1, 2)
// cout << a << endl; // Output: 1 + 2i
// Jika imajiner < 0; Misal: Kompleks(1, -2)
// cout << a << endl; // Output: 1 - 2i
// Jika nilai imajiner 0, jangan tampilkan i; Misal: Kompleks(1, 0)
// cout << a << endl; // Output: 1

