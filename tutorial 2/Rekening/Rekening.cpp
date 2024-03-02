#include "Rekening.h"

Rekening::Rekening(double saldo)
{
    if (saldo < 0.0)
    {
        this->saldo = 0.0;
    }
    else
    {
        this->saldo = saldo;
    }
}

void Rekening::setSaldo(double saldo)
{
    this->saldo = saldo;
}

double Rekening::getSaldo() const
{
    return saldo;
}

void Rekening::simpanUang(double nominal)
{
    saldo += nominal;
}

bool Rekening::tarikUang(double nominal)
{
    if (saldo - nominal >= 0)
    {
        this->saldo -= nominal;
        return true;
    }
    return false;
}