#include "RekeningTabungan.h"

RekeningTabungan::RekeningTabungan(double saldo, double biayaTransaksi) : Rekening(saldo)
{
    this->biayaTransaksi = biayaTransaksi;
}

void RekeningTabungan::setBiayaTransaksi(double biayaTransaksi)
{
    this->biayaTransaksi = biayaTransaksi;
}

double RekeningTabungan::getBiayaTransaksi() const
{
    return this->biayaTransaksi;
}

void RekeningTabungan::simpanUang(double uang)
{
    Rekening::simpanUang(uang);
    Rekening::setSaldo(getSaldo() - this->biayaTransaksi);
}

bool RekeningTabungan::tarikUang(double uang)
{
    if (Rekening::tarikUang(uang))
    {
        Rekening::setSaldo(Rekening::getSaldo() - this->biayaTransaksi);
        return true;
    }
    return false;
}