#include <iostream>
#include <cstring>
using namespace std;

class Automobile
{
    protected:
        char modello[20];
        double consumo_100km;
    public:
        Automobile(char modello[], double consumo_100km)
        {
            strcpy(this->modello, modello);
            this->consumo_100km = consumo_100km;
        }
        double calcola_consumi(int km)
        {
            return (this->consumo_100km/100) * km;
        }
        double calcola_costo(int km, int costo)
        {
            return costo*calcola_consumi(km);
        }
};

class Benzina : public Automobile
{
    protected:
        int l_serb;
    public:
        Benzina(char modello[], double consumo_100km, int l_serb) : Automobile(modello, consumo_100km)
        {
            this->l_serb = l_serb;
        }
        int calcola_autonomia()
        {
            return (this->l_serb*100)/this->consumo_100km;
        }
};

class Elettrica : public Automobile
{
    protected:
        int batteria;
    public:
        Elettrica(char modello[], double consumo_100km, int batteria) : Automobile(modello, consumo_100km)
        {
            this->batteria = batteria;
        }
        int calcola_autonomia()
        {
            return this->batteria*100/this->consumo_100km;
        }
};

class Ibrida : public Benzina
{
    protected:
        double risparimio;
    public:
        Ibrida(char modello[], double consumo_100km, int l_serb, int risparmio) : Benzina(modello, consumo_100km, l_serb)
        {
            if(risparimio > 0 && risparimio < 1)
                this->risparimio = risparimio;
            else
                this->risparimio = 0.1;
        }
        double calcola_consumi(int km)
        {
            return Benzina::calcola_consumi(km) - (this->risparimio * Benzina::calcola_consumi(km));
        }
        double calcola_costo(int km, double costo)
        {
            return costo * calcola_consumi(km);
        }
        int calcola_autonomia()
        {
            return (this->l_serb*100) / (this->consumo_100km - this->consumo_100km*this->risparimio);
        }
};

int main()
{
    Ibrida b = Ibrida((char *)"GIGIO", 2, 50, 0.5);
    cout << b.calcola_consumi(100) << endl;
    cout << b.calcola_costo(100,2) << endl;
    cout << b.calcola_autonomia() << endl;
    return 0;
}