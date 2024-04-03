#include "Walikota.hpp"
#include "Exception.hpp"
#include <iostream>

using namespace std;

Walikota::Walikota() {
    this->kayu = DEFAULT_KAYU;
    this->gulden = DEFAULT_GULDEN;
    this->pekerja = DEFAULT_PEKERJA;
}

Walikota::Walikota(int kayu, int gulden, int pekerja)
{
    this->kayu = kayu;
    this->gulden = gulden;
    this->pekerja = pekerja;
}

Walikota::~Walikota() {}

void Walikota::bangunBangunan(string namaBangunan, int kayu, int gulden) {
    try {
        this->pakaiKayu(kayu);
        this->pakaiGulden(gulden);
        this->pekerjakanPekerja();
        Bangunan baru(namaBangunan);
        this->bangunan.push_back(baru);
        cout << "Bangunan [" << this->bangunan.size() << "] " << namaBangunan << " berhasil dibangun" << endl;
    } catch (KayuTidakCukupException e) {
        cout << e.what() << ", beli kayu dulu." << endl;
    } catch (GuldenTidakCukupException e) {
        cout << e.what() << ", tagih pajak dulu." << endl;
        this->batalPakaiKayu(kayu);
    } catch (PekerjaTidakCukupException e) {
        cout << e.what() << ", rekrut pekerja dulu." << endl;
        this->batalPakaiKayu(kayu);
        this->batalPakaiGulden(gulden);
    }
}

void Walikota::tambahKayu(int num) {
    this->kayu += num;
}

void Walikota::tambahGulden(int num) {
    this->gulden += num;
}

void Walikota::tambahPekerja(int num) {
    this->pekerja += num;
}

void Walikota::pakaiKayu(int num) {
    if (this->kayu < num) {
        KayuTidakCukupException e;
        throw e;
    }
    this->kayu -= num;
}

void Walikota::pakaiGulden(int num) {
    if (this->gulden < num) {
        GuldenTidakCukupException e;
        throw e;
    }
    this->gulden -= num;
}

void Walikota::pekerjakanPekerja() {
    if (this->pekerja == 0) {
        PekerjaTidakCukupException e;
        throw e;
    }
    this->pekerja--;
}

void Walikota::batalPakaiKayu(int num) {
    this->kayu += num;
}

void Walikota::batalPakaiGulden(int num) {
    this->gulden += num;
}

void Walikota::batalkanPekerja() {
    this->pekerja++;
}

void Walikota::sebutBangunan(int idx) {
    try {
        cout << this->bangunan.at(idx).getNamaBangunan() << endl;
    } catch (exception e) {
        cout << e.what() << endl;
    }
}

void Walikota::statusKota() {
    cout << "Kayu: " << this->kayu << endl;
    cout << "Gulden: " << this->gulden << endl;
    cout << "Pekerja: " << this->pekerja << endl;
    cout << "Bangunan:" << endl;
    for (int i = 0; i < this->bangunan.size(); i++) {
        cout << "  Bangunan[" << i << "]: " << this->bangunan.at(i).getNamaBangunan() << endl;
    }
}