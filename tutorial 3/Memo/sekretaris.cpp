#include "sekretaris.h"
#include <iostream>

using namespace std;

Sekretaris::Sekretaris()
{
    this->kertas = KERTAS_DEFAULT;
    this->tinta = TINTA_DEFAULT;
    this->energi = ENERGI_MAX;
    this->memoLength = 0;
    memo = new Memo[0];
}

Sekretaris::Sekretaris(int kertas, int tinta)
{
    this->kertas = kertas;
    this->tinta = tinta;
    this->energi = ENERGI_MAX;
    this->memoLength = 0;
    memo = new Memo[0];
}

Sekretaris::~Sekretaris()
{
}

void Sekretaris::buatMemo(string pesan, string untuk)
{
    try
    {
        Memo memo(pesan, untuk);
        pakaiKertas();
        pakaiTinta(pesan.length());
        pakaiEnergi();
        this->memoLength++;
        Memo *temp = new Memo[this->memoLength];
        for (int i = 0; i < this->memoLength - 1; i++)
        {
            temp[i] = this->memo[i];
        }
        temp[this->memoLength - 1] = memo;
        delete[] this->memo;
        this->memo = temp;
        cout << "Memo [" << this->memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;
    }
    catch (KertasHabisException e)
    {
        cout << e.what() << ", segera isi kertas" << endl;
    }
    catch (TintaKurangException e)
    {
        batalPakaiKertas();
        cout << e.what() << ", segera isi tinta" << endl;
    }
    catch (EnergiHabisException e)
    {
        batalPakaiKertas();
        batalPakaiTinta(pesan.length());
        cout << e.what() << ", segera istirahat" << endl;
    }
    catch (PesanKepanjanganException e)
    {
        cout << e.what() << ", perpendek pesannya" << endl;
    }
}

void Sekretaris::pakaiKertas()
{
    if (this->kertas <= 0)
    {
        throw KertasHabisException();
    }
    this->kertas--;
}

void Sekretaris::pakaiTinta(int num)
{
    if (this->tinta < num)
    {
        throw TintaKurangException();
    }
    this->tinta -= num;
}

void Sekretaris::pakaiEnergi()
{
    if (this->energi <= 0)
    {
        throw EnergiHabisException();
    }
    this->energi--;
}

void Sekretaris::batalPakaiKertas()
{
    this->kertas++;
}

void Sekretaris::batalPakaiTinta(int num)
{
    this->tinta += num;
}

void Sekretaris::batalPakaiEnergi()
{
    this->energi++;
}

void Sekretaris::isiTinta(int num)
{
    this->tinta += num;
}

void Sekretaris::isiKertas(int num)
{
    this->kertas += num;
}

void Sekretaris::istirahat()
{
    this->energi = ENERGI_MAX;
}

void Sekretaris::printStatus()
{
    cout << "Status" << endl;
    cout << "  Energi : " << energi << endl;
    cout << "  Tinta : " << tinta << endl;
    cout << "  Kertas : " << kertas << endl;
    cout << "  Memo : " << memoLength << endl;
    for (int i = 0; i < memoLength; i++)
    {
        cout << "    Memo [" << i + 1 << "]" << endl;
        cout << "      Pesan : " << memo[i].getPesan() << endl;
        cout << "      Untuk : " << memo[i].getUntuk() << endl;
    }
}