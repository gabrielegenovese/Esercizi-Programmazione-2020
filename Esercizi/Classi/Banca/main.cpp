#include <iostream>
using namespace std;

class contoBanca
{
    protected:
        double saldo;
    public:
        bool versa(int soldi)
        {
            if (soldi < 0) return false;
            saldo += soldi;
            return true;
        }
        bool preleva(int soldi)
        {
            if (saldo - soldi < 0 || soldi < 0)
                return false;
            
            saldo -= soldi;
            return true;
        }
        double getSaldo()
        {
            return saldo;
        }
        contoBanca(int soldi = 0)
        {
            saldo = soldi;
        }
};

class contoInteressi : public contoBanca
{
    public:
        void interesse()
        {
            saldo += (saldo/100)*2;
        }
        contoInteressi(int soldi = 0)
        {
            saldo = soldi;
        }
};

int main()
{
    contoBanca myConto = contoBanca(200);
    cout << "Saldo: " << myConto.getSaldo() << endl;
    myConto.versa(200);
    cout << "Saldo: " << myConto.getSaldo() << endl;
    myConto.preleva(300);
    cout << "Saldo: " << myConto.getSaldo() << endl;
    myConto.preleva(300);
    cout << "Saldo: " << myConto.getSaldo() << endl;
    cout << "-----------" << endl;
    contoInteressi myInteressi = contoInteressi();
    myInteressi.versa(200);
    myInteressi.interesse();
    cout << "Saldo: " << myInteressi.getSaldo() << endl;
    return 0;
}