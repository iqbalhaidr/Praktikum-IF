#include "Weed.hpp"

#include <iostream>

using namespace std;

Weed::Weed() { this->many = 1; }

Weed::Weed(int n) { this->many = n; }

Weed::Weed(const Weed &b) { this->many = b.many; }

Weed::~Weed() {}

void Weed::step() {
    for (int i = 0; i < many; i++) {
        cout << "kresek...";
    }
    cout << endl;
}