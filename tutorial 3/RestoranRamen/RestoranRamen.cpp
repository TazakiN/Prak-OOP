#include "RestoranRamen.hpp"
using namespace std;

void RestoranRamen::tambahOrder(int n, int p)
{
    daftarMeja[n] += p;
}

int RestoranRamen::tutupOrder(int n)
{
    int temp = daftarMeja[n];
    daftarMeja.erase(n);
    return temp;
}

int RestoranRamen::cekTotal(int n)
{
    return daftarMeja[n];
}

int RestoranRamen::totalMeja()
{
    return daftarMeja.size();
}

void RestoranRamen::cetakMeja()
{
    map<int, int>::iterator itr = daftarMeja.begin();
    if (daftarMeja.size() == 0)
    {
        cout << "Restoran kosong" << endl;
    }
    else
    {
        for (itr = daftarMeja.begin(); itr != daftarMeja.end(); itr++)
        {
            cout << "Meja " << itr->first << " = " << itr->second << endl;
        }
    }
}