#include "memo.h"

using namespace std;

Memo::Memo()
{
    this->pesan = "";
    this->untuk = "";
}

Memo::Memo(string pesan, string untuk)
{
    if (pesan.length() > PESAN_MAX)
    {
        throw PesanKepanjanganException();
    }
    this->pesan = pesan;
    this->untuk = untuk;
}

Memo &Memo::operator=(Memo &obj)
{
    this->pesan = obj.pesan;
    this->untuk = obj.untuk;
    return *this;
}

string Memo::getPesan()
{
    return pesan;
}

string Memo::getUntuk()
{
    return untuk;
}
