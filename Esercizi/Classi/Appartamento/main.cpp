#include <iostream>
using namespace std;

class abitazione
{
    protected:
        int n_stanze;
        double metratura;
    public:
        abitazione(int n_stanze = 0, double metratura = 0)
        {
            this->n_stanze = n_stanze;
            this->metratura = metratura;
        }
};

class appartamento : public abitazione
{
    protected:
        int piano;
    public:
        double costo(double euro_al_m2)
        {
            return euro_al_m2*metratura;
        }
        appartamento(int piano = 1, int n_stanze = 0, double metratura = 0)
        {
            this->piano = piano;
            this->n_stanze = n_stanze;
            this->metratura = metratura;
        }
};

class villetta : public abitazione
{
    public:
        double costo(double euro_al_m2)
        {
            return (euro_al_m2*1.1)*metratura;
        }
        villetta(int n_stanze = 0, double metratura = 0)
        {
            this->n_stanze = n_stanze;
            this->metratura = metratura;
        }
};

int main()
{

    villetta villa1 = villetta(3, 60);
    cout << villa1.costo(1) << endl;
    return 0;
}