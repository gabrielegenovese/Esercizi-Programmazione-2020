#include <iostream>
#include <cstring>
using namespace std;

class Orologio
{
    protected:
        int ore, minuti, secondi;
    public:
        void impostare(int ore, int minuti, int secondi)
        {
            if(ore > 23 || ore < 0 || minuti > 59 || minuti < 0 || secondi > 59 || secondi < 0 )
                cout << "Valori inseriti sbagliati\n";
            else
            {
                this->ore = ore;
                this->minuti = minuti;
                this->secondi = secondi;
            }
        }
        void tick()
        {
            this->secondi++;
            if(secondi == 60)
            {
                this->minuti++;
                this->secondi = 0;
                if(minuti == 60)
                {
                    this->ore++;
                    this->minuti = 0;
                    if(this->ore == 24)
                        this->ore = 0;
                }
            }
        }
        int seconds()
        {
            int tmp = ((this->ore*3600)+(this->minuti*60)+this->secondi);
            return tmp;
        }
        Orologio()
        {
            this->secondi = 0;
            this->minuti = 0;
            this->ore = 0;
        }
};

class OrologioConDoppioFormato : public Orologio
{
    public:
        void stampa24h()
        {
            cout << "Ora: " << this->ore << ":" << this->minuti << ":" << this->secondi << endl;
        }
        void stampa12h()
        {
            if(this->ore <= 12)
            {
                if(this->ore == 0) cout << "Ora: 12" << ":" << this->minuti << ":" << this->secondi << " PM" << endl;
                else cout << "Ora: " << this->ore << ":" << this->minuti << ":" << this->secondi << " AM" << endl;
            }
            else
                cout << "Ora: " << (this->ore-12) << ":" << this->minuti << ":" << this->secondi << " PM" << endl;
        }
        OrologioConDoppioFormato() :  Orologio(){}
};

int main()
{
    
    Orologio o = Orologio();
    o.impostare(15,34,43);
    cout << "Secondi: " << o.seconds() << endl;
    o.tick();
    cout << "Secondi: " << o.seconds() << endl;

    for (int i = 0; i < 60; i++)
    {
        o.tick();
    }

    cout << "Secondi: " << o.seconds() << endl;
    
    OrologioConDoppioFormato t = OrologioConDoppioFormato();
    t.impostare(18,34,43);
    t.stampa24h();
    t.stampa12h();
    
    return 0;
}