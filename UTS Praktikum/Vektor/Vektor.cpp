#include "Vektor.hpp"

Vektor::Vektor() {
    this->n = 0;
    vector<int> vector;
}

Vektor::Vektor(int _n) {
    this->n = _n;
    vector<int> vector;
    for (int i = 0; i < _n; i++) {
        this->vektor.push_back(0);
    }
}

Vektor::Vektor(const Vektor &v) {
    this->n = v.n;
    vector<int> vector; 
    for (int i = 0; i < v.n; i++) {
        vector.push_back(v.vektor.at(i));
    }
}

Vektor::~Vektor(){}

void Vektor::setElmt(int idx, int x) {
    // vector<int>::iterator it = this->vektor.begin();
    // for(int i = 0; i < idx; i++) {
    //     it++;
    // }
    this->vektor.at(idx) = x;
}

int Vektor::getN() {
    return this->n;
}


Vektor operator+(const Vektor &v1, const Vektor &v2) {
    Vektor hasil = Vektor(v1.n);
    for (int i = 0; i < v1.n; i++) {
        hasil.setElmt(i, v1.vektor.at(i) + v2.vektor.at(i));
    }
    return hasil;
}

Vektor operator-(const Vektor &v1, const Vektor &v2) {
    Vektor hasil = Vektor(v1.n);
    for (int i = 0; i < v1.n; i++) {
        hasil.setElmt(i, v1.vektor.at(i) - v2.vektor.at(i));
    }
    return hasil;
}

int operator*(const Vektor &v1, const Vektor &v2) {
    int hasil = 0;
    for (int i = 0; i < v1.n; i++) {
        hasil += v1.vektor.at(i) * v2.vektor.at(i);
    }
    return hasil;
}

bool operator==(const Vektor &v1, const Vektor &v2) {
    bool hasil = v1.n == v2.n;
    if (hasil) {
        for (int i = 0; i < v1.n; i++) {
            bool temp = v1.vektor.at(i) == v2.vektor.at(i);
            if (!temp) return false;
        }
    }
    return hasil;
}

void Vektor::printVektor() {
    cout << "<";
    for(int i = 0; i < n; i++) {
        cout << vektor.at(i);
        if (i != n-1) {
            cout << ",";
        }
    }
    cout << ">" << endl;
}