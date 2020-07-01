#include "Kostiumas.h"

 string MedziagosP;
        string ModelioP;
        double Ilgis;
        double Plotis;
        double Proc;
        int Minutes;

Kostiumas:: Kostiumas(string Mep, string Mop, double I, double Pl, double Pr, int Min)
{
    MedziagosP=Mep;
    ModelioP=Mop;
    Ilgis=I;
    Plotis=Pl;
    Proc=Pr;
    Minutes=Min;
}
Kostiumas:: Kostiumas(){}
        string Kostiumas::GautiMedziagosP(){
            return MedziagosP;
        }
        string Kostiumas::GautiModelioP(){
            return ModelioP;
        }
        double Kostiumas::GautiIlgi(){
            return Ilgis;
        }
        double Kostiumas::GautiPloti(){
            return Plotis;
        }
        double Kostiumas::GautiProc(){
            return Proc;
        }
        int Kostiumas::GautiMin(){
            return Minutes;
        }
        double Kostiumas::GautiPlota()
        {
            return Ilgis*Plotis;
        }
        double Kostiumas::GautiAtraizas(){
        return GautiPlota()*GautiProc();
        }
