#include "RekeningGiro.h"

RekeningGiro::RekeningGiro(double saldo, double sukuBunga) : Rekening(saldo)
{
    this->sukuBunga = sukuBunga;
}

void RekeningGiro::setSukuBunga(double sukuBunga)
{
    this->sukuBunga = sukuBunga;
}

double RekeningGiro::getSukuBunga() const
{
    return this->sukuBunga;
}

double RekeningGiro::hitungBunga()
{
    return this->getSaldo() * this->sukuBunga;
}