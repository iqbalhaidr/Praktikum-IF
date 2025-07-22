#ifndef KEYVALUE_H
#define KEYVALUE_H

#define MAX_CAPACITY 10

#include <cmath>
#include <iostream>
using namespace std;

// Deklarasi
template <class TK, class TV>
class KeyValue {
   private:
    TK* keys;
    TV* values;
    int nEff;

   public:
    KeyValue();
    KeyValue(const KeyValue&);
    ~KeyValue();
    KeyValue& operator=(const KeyValue&);
    void set(TK key, TV value);
    void display(TK key);
    int indexOf(TK key);
    void printKeys();
    void printValues();
};

// Implementasi
template <typename TK>
inline bool isEqual(const TK& a, const TK& b) {
    return a == b;  // Perbandingan default untuk tipe selain double
}

// Spesialisasi template untuk tipe double (menggunakan toleransi)
template <>
inline bool isEqual<double>(const double& a, const double& b) {
    return std::abs(a - b) < 0.01;
}

template <class TK, class TV>
KeyValue<TK, TV>::KeyValue() {
    nEff = 0;
    keys = new TK[MAX_CAPACITY];
    values = new TV[MAX_CAPACITY];
}

template <class TK, class TV>
KeyValue<TK, TV>::KeyValue(const KeyValue& kv) {
    nEff = kv.nEff;
    keys = new TK[MAX_CAPACITY];
    values = new TV[MAX_CAPACITY];

    for (int i = 0; i < nEff; i++) {
        keys[i] = kv.keys[i];
        values[i] = kv.values[i];
    }
}

template <class TK, class TV>
KeyValue<TK, TV>::~KeyValue() {
    delete[] this->keys;
    delete[] this->values;
}

template <class TK, class TV>
KeyValue<TK, TV>& KeyValue<TK, TV>::operator=(const KeyValue& kv) {
    delete[] this->keys;
    delete[] this->values;

    nEff = kv.nEff;
    keys = new TK[MAX_CAPACITY];
    values = new TV[MAX_CAPACITY];

    for (int i = 0; i < nEff; i++) {
        keys[i] = kv.keys[i];
        values[i] = kv.values[i];
    }

    return *this;
}

template <class TK, class TV>
int KeyValue<TK, TV>::indexOf(TK key) {
    int indexFound = -1;

    for (int i = 0; i < nEff; i++) {
        if (isEqual(key, keys[i])) {
            indexFound = i;
        }
    }

    return indexFound;
}

template <class TK, class TV>
void KeyValue<TK, TV>::display(TK key) {
    int index = indexOf(key);

    if (index != -1) {
        cout << values[index] << endl;
    } else {
        cout << "Key tidak ditemukan!" << endl;
    }
}

template <class TK, class TV>
void KeyValue<TK, TV>::set(TK key, TV value) {
    int index = indexOf(key);

    if (index != -1) {
        values[index] = value;
    } else {
        if (nEff == MAX_CAPACITY) {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi."
                 << endl;
        } else {
            keys[nEff] = key;
            values[nEff] = value;
            nEff++;
        }
    }
}

template <class TK, class TV>
void KeyValue<TK, TV>::printKeys() {
    for (int i = 0; i < nEff; i++) {
        cout << keys[i] << " ";
    }
    cout << endl;
}

template <class TK, class TV>
void KeyValue<TK, TV>::printValues() {
    for (int i = 0; i < nEff; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

#endif
