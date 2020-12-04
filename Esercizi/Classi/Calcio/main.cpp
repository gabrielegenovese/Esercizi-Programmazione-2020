#include <iostream>
#include <string.h>
using namespace std;

class Squadra
{
    protected:
        char nome[50];
        int scudetti;
    public:
        int getScudetti()
        {
            return this->scudetti;
        }
        Squadra(char nome[] = NULL, int scudetti = 0)
        {
            strcpy(this->nome, nome);
            this->scudetti = scudetti;
        }
};

class Calciatore
{
    protected:
        char nome[50];
        Squadra * squadra;
        int goal_fatti;
    public:
        void inc_goal_fatti(int n)
        {
            if(n <= 0) cout << "Non puoi inserire un numero negativo\n";
            else this->goal_fatti += n;
        }
        bool hasNoScudetti()
        {
            if(this->squadra->getScudetti())
                return true;
            return false;
        }
        Calciatore(char nome[], Squadra *squadra)
        {
            strcpy(this->nome, nome);
            this->squadra = squadra;
            this->goal_fatti = 0;
        }
};

class Portiere : public Calciatore
{
    protected:
        int goal_subiti;
    public:
        void inc_goal_subiti(int n)
        {
            if(n <= 0) cout << "Non puoi inserire un numero negativo\n";
            else this->goal_subiti += n;
        }
        Portiere(char nome[], Squadra *sq) : Calciatore(nome, sq)
        {
            this->goal_subiti = 0;
        }
}; 

int main()
{
    char sq1[] = "Milan";
    char sq2[] = "Sassuolo";
    char nome1[] = "Pirlo";
    char nome2[] = "Buffon";
    Squadra Milan = Squadra(sq1, 9);
    Squadra Sassuolo = Squadra(sq2, 0);
    Calciatore Pirlo = Calciatore(nome1, &Milan);
    Portiere Buffon = Portiere(nome2, &Sassuolo);
    
    return 0;
}