#ifndef KOSTIUMAS_H
#define KOSTIUMAS_H
#include <string>
using namespace std;
class Kostiumas
{
    public:
        Kostiumas(string Mep, string Mop, double I, double Pl, double Pr, int Min);
        Kostiumas();
        string GautiMedziagosP();
        string GautiModelioP();
        double GautiIlgi();
        double GautiPloti();
        double GautiProc();
        int GautiMin();
        double GautiPlota();
        double GautiAtraizas();
    protected:

    private:
        string MedziagosP;
        string ModelioP;
        double Ilgis;
        double Plotis;
        double Proc;
        int Minutes;
};

#endif // KOSTIUMAS_H
