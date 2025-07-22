#include <iostream>

using namespace std;

template <class A>
void func(A param1, A param2) {
    cout << "Masukan Anda: " << param1 << " dan " << param2
         << ", memiliki tipe yang sama" << endl;
}

template <class B, class C>
void func(B param1, C param2) {
    cout << "Masukan Anda: " << param1 << " dan " << param2
         << ", mungkin memiliki tipe yang berbeda" << endl;
}

template <>
void func<char, int>(char a, int b) {
    for (int i = 0; i < b; i++) {
        cout << a << endl;
    }
}