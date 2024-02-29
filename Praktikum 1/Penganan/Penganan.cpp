#include "Penganan.hpp"
#include <iostream>
using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan() {
    keik = 0;
    panekuk = 0;
}

Penganan::Penganan(int keik, int panekuk) {
    this->keik = keik;
    this->panekuk = panekuk; 
}

int Penganan::GetKeik() const{
    return this->keik;
}

int Penganan::GetPanekuk() const {
    return this->panekuk;
}

void Penganan::SetKeik(int a) {
    this->keik = a;
}

void Penganan::SetPanekuk(int a) {
    this->panekuk = a;
}

Penganan operator+ (const Penganan&a, const Penganan&b) {
    Penganan res;
    res.SetKeik(a.GetKeik() + b.GetKeik());
    res.SetPanekuk(a.GetPanekuk() + b.GetPanekuk());
    Penganan::n_rumah++;
    return res;
}

Penganan operator- (const Penganan&a, const Penganan&b) {
    Penganan res;
    if (a.GetKeik() >= b.GetKeik()){ //stok lebih banyak
        res.SetKeik(a.GetKeik() - b.GetKeik());
        Penganan::uang += b.GetKeik() * 51;
    } else {
        Penganan::uang += a.GetKeik() * 51;
        res.SetKeik(0);
    }
    if (a.GetPanekuk() >= b.GetPanekuk()){ //stok lebih banyak
        res.SetPanekuk(a.GetPanekuk() - b.GetPanekuk());
        Penganan::uang += b.GetPanekuk() * 37;
    } else {
        Penganan::uang += a.GetPanekuk() * 37;
        res.SetPanekuk(0);
    }
    return res;
}

Penganan operator^ (const Penganan&a, const int n) {
    Penganan res;
    if (a.GetKeik() >= n){ //stok lebih banyak
        res.SetKeik(a.GetKeik() - n);
    } else {
        res.SetKeik(0);
        Penganan::uang += (a.GetKeik() - n) *51;
    }
    if (a.GetPanekuk() >= n){ //stok lebih banyak
        res.SetPanekuk(a.GetPanekuk() - n);
    } else {
        res.SetKeik(0);
        Penganan::uang += (a.GetPanekuk() - n) *51;
    }
    return res;
}

Penganan operator^ (const int n, const Penganan&a) {
    return a^n;
}

int Penganan::JumlahUang() {
    return Penganan::uang;
}

int Penganan::HitungNRumah() {
    return Penganan::n_rumah;
}

void Penganan::Print(){
    cout << this->keik << "keik-" << this->panekuk << "panekuk" << endl;
} 