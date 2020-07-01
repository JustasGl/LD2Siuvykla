#include "Siuvykla.h"
#include <Kostiumas.h>
Siuvykla::Siuvykla(string P, int D)
{
      Pavadinimas = P;
      DarbuotojuSk = D;
      KKiekis=0;
}
Siuvykla::Siuvykla()
{
}
 string Pavadinimas;
 int DarbuotojuSk;
 int DarboLaikas;
 Kostiumas K[50];
 int KKiekis;

 string Siuvykla::GautiPavadinimas(){
    return Pavadinimas;
 }
 int Siuvykla::GautiDSk(){
    return DarbuotojuSk;
 }
 int Siuvykla::GautiDarboLaika()
 {
     return DarboLaikas;
 }
 void Siuvykla::PriskirtiDarboLaika(int d)
 {
    DarboLaikas=d;
 }
 Kostiumas Siuvykla::GautiKostiuma(int pos)
 {
     return K[pos];

 }
void Siuvykla::DetiKostiuma(Kostiumas k)
{
    K[KKiekis++]=k;

}
int Siuvykla::GautiKKieki()
{
    return KKiekis;
}
