#include <iostream>
#include <cstring>
using namespace std;

# define cono 2.70
# define cestina  2.50
# define coppetta 2

struct gusto
{
    char nome[10];
};

typedef gusto *p_gusto;

class Gelato
{
    protected:
        p_gusto gusti[3];
        int cursor;
        double tipo;
    public:
        void aggiungiGelato(char g[])
        {
            int i = 0;
            while(this->gusti[i] != NULL && i < 3)
                i++;
            
            if(i == 3)
                cout << "Limite di gusti raggiunto\n";
            else
            {
                this->gusti[i] = new gusto;
                strcpy(this->gusti[i]->nome,g);
            }
            
        }
        double calcolaPrezzo()
        {
            return tipo;
        }
        Gelato(double tipo = 0)
        {
            for (int i = 0; i < 3; i++)
                this->gusti[i] = NULL;
            this->cursor = 0;
            this->tipo = tipo;
        }
};

class Cono : public Gelato
{
    public:
        Cono() : Gelato(cono){}
};
class Cestina : public Gelato
{
    public:
        Cestina() : Gelato(cestina){}
};
class Coppetta : public Gelato
{
    Coppetta() : Gelato(coppetta){}
};

int main()
{
    Cono g1 = Cono();

    g1.aggiungiGelato((char*)"Fragola");
    g1.aggiungiGelato((char*)"Cioccolato");
    g1.aggiungiGelato((char*)"Pesca");
    //g1.aggiungiGelato((char*)"Stracciatella");

    cout << "Costo del gelato: " << g1.calcolaPrezzo() << endl;
    return 0;
}