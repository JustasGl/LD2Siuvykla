#ifndef SIUVYKLA_H
#define SIUVYKLA_H
#include <string>
#include <Kostiumas.h>

using namespace std;

class Siuvykla
{
    public:
        Siuvykla(string P, int D);
        Siuvykla();
        string GautiPavadinimas();
        int GautiDSk();
        int GautiDarboLaika();
        void PriskirtiDarboLaika(int d);
        Kostiumas GautiKostiuma(int pos);
        void DetiKostiuma(Kostiumas k);
        int GautiKKieki();
    protected:

    private:
        string Pavadinimas;
        int DarbuotojuSk;
        int DarboLaikas;
        Kostiumas K[50];
        int KKiekis;
};

#endif // SIUVYKLA_H
