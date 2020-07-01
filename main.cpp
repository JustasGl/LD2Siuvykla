#include <iostream>
#include <Kostiumas.h>
#include <Siuvykla.h>
#include <fstream>
#include <string>
#include <map>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;
void DirektorijosSkaitymas(string Direktorija,int &SKiekis, Siuvykla S[]);
Siuvykla skaito(string FailPav);
void VidKostiumai(Siuvykla S[],int SKiekis, Kostiumas k[], int &VidKiekis);
map<string, int> Skaiciavimas(Kostiumas k[],int & KKiekis);
double VidPlotas(Siuvykla S[] ,int Skiekis);
double AtraizuKiekis(Siuvykla S[],int SKiekis);
void spausdina(Siuvykla S[], int SKiekis,Kostiumas vidKostiumai[],int vidKKiekis);
int main()
{
    int SKiekis=0;
    Siuvykla S[10];
    DirektorijosSkaitymas(".",SKiekis,S);
    for(int i=0; i<SKiekis; i++)
    {
        cout<<"iveskite "<<S[i].GautiPavadinimas()<<" darbo valandas per savaite \n";
        int Dlk;
        cin >> Dlk;
        S[i].PriskirtiDarboLaika(Dlk);
    }
    Kostiumas VK[50];
    int VidKKiekis=0;
    VidKostiumai(S,SKiekis,VK,VidKKiekis);
    spausdina(S,SKiekis,VK,VidKKiekis);
    return 0;
}
void DirektorijosSkaitymas(string Direktorija,int &SKiekis, Siuvykla S[])
{
    SKiekis=0;
    DIR *d;
    char *p1,*p2;
    int ret;
    struct dirent *dir;
    d = opendir(Direktorija.c_str());
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            p1=strtok(dir->d_name,".");
            p2=strtok(NULL,".");
            if(p2!=NULL)
            {
                ret=strcmp(p2,"txt");
                if(ret==0)
                {
                    string s(p1);
                    s=s+".txt";
                     S[SKiekis++]=skaito(s);
                }
            }
        }
        closedir(d);
    }
}
Siuvykla skaito(string FailPav)
{
    string SPavadinimas;
    cout<<FailPav<<endl;
    ifstream dataIn(FailPav.c_str());
    dataIn>>SPavadinimas;
    int DarbuotojuSk,Min;
    dataIn>>DarbuotojuSk;
    Siuvykla S(SPavadinimas,DarbuotojuSk);
    double Ilgis,Plotis,Proc;

    string KPavadinimas,Mpavadinimas;

    while(!dataIn.eof())
    {
        dataIn>>KPavadinimas>>Mpavadinimas>>Ilgis>>Plotis>>Proc>>Min;
        Kostiumas k(KPavadinimas,Mpavadinimas,Ilgis,Plotis,Proc,Min);
        S.DetiKostiuma(k);
    }
    dataIn.close();
    return S;
}
map<string, int> Skaiciavimas(Kostiumas k[],int & KKiekis)//funkcija butu naudojama jei reiketu išgauti unikalios medziagos kostiumu plotus
{
    map<string, int> Medz;
    for(int i=0; i<KKiekis; i++)
    {
       std::map<string, int>::iterator it = Medz.find(k[i].GautiMedziagosP());
        if (it != Medz.end()){
        it->second = it->second+k[i].GautiPlota();
        }
        else
        {
            Medz.insert(pair<string, int>(k[i].GautiMedziagosP(),k[i].GautiPlota()));
        }
    }
    return Medz;
}
double AtraizuKiekis(Siuvykla S[],int SKiekis)
{
    double rez = 0;
    for(int i=0; i<SKiekis; i++)
    for(int j=0;j<S[i].GautiKKieki(); j++)
    {
        Kostiumas k = S[i].GautiKostiuma(j);
        rez +=k.GautiAtraizas();
    }
    return rez;
}
void spausdina(Siuvykla S[], int SKiekis,Kostiumas vidKostiumai[],int vidKKiekis)
{
    for(int i=0; i<SKiekis; i++){
    cout<<endl;
    cout<<S[i].GautiPavadinimas()<<endl;
    cout<<endl;
    for(int j=0; j<S[i].GautiKKieki(); j++)
    {
        Kostiumas k = S[i].GautiKostiuma(j);
        cout<<k.GautiModelioP()<<" kostiumu per savaite pasiutu "<<S[i].GautiDSk()*S[i].GautiDarboLaika()*60/k.GautiMin()<<endl;

    }
    }
    cout<<"Viso atraizu reikes "<<endl<<AtraizuKiekis(S,SKiekis)<<endl;
    cout<<setw(35)<<"Vidutiniai kostiumai"<<endl;
    cout<<setw(25)<<"Modelio pavadinimas "<<setw(20)<<"Kostiumo plotas"<<endl;
    for(int i=0; i<vidKKiekis; i++)
    {
        cout<<setw(25)<<vidKostiumai[i].GautiModelioP()<<setw(20)<<vidKostiumai[i].GautiPloti()<<endl;
    }
}
void VidKostiumai(Siuvykla S[],int SKiekis, Kostiumas k[], int &VidKiekis)
{
    double vid = VidPlotas(S,SKiekis);
    VidKiekis=0;
    double virsutineRiba = vid+vid*0.1;
    double apatineRiba=vid-vid*0.1;
    for(int i=0; i<SKiekis; i++)
    {
        for(int j=0; j<S[i].GautiKKieki(); j++)
        {
         Kostiumas temp = S[i].GautiKostiuma(j);
         double t= temp.GautiPlota();
         if(apatineRiba<t&&t<virsutineRiba){
            k[VidKiekis++]=temp;
         }
        }
    }

}
double VidPlotas(Siuvykla S[] ,int Skiekis)
{
    int VisoK=0;
    double VisiKPlotai=0;
    for(int i=0; i<Skiekis; i++){
     VisoK +=S[i].GautiKKieki();
        for(int j=0; j<S[i].GautiKKieki(); j++)
        {
            Kostiumas k = S[i].GautiKostiuma(j);
            VisiKPlotai+=k.GautiPlota();
        }
    }
    return VisiKPlotai/VisoK;
}
