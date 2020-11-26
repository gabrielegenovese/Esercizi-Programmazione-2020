#include <iostream>
using namespace std;

class frazione{
    protected:
        int divisore;
        int dividendo;
    public:
        void stampa();
        int moltiplica(frazione f1, frazione f2);
        int inverso();
        frazione(int divisore, int dividendo);
};



int main()
{

    return 0;
}