#include <iostream>
#include <cmath>
using namespace std;

class Segmento
{
    protected:
        float x1, x2, y1, y2;
    public:
        Segmento(float x1 = 0, float x2 = 0, float y1 = 0, float y2 = 0)
        {
            if(x1 < 0)
                this->x1 = 0;
            else
                this->x1 = x1;
            if(x2 < 0)
                this->x2 = 0;
            else
                this->x2 = x2;
            if(y1 < 0)
                this->y1 = 0;
            else
                this->y1 = y1;
            if(y2 < 0)
                this->y2 = 0;
            else
                this->y2 = y2;
        }
        float lunghezza()
        {
            return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        }
};

class Segmenti_Adiacenti : public Segmento
{
    protected:
        float x3, y3;
    public:
        Segmenti_Adiacenti(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0, float x3 = 0, float y3 = 0) : Segmento(x1,x2,y1,y2)
        {
            if(x3 < 0)
                this->x3 = 0;
            else
                this->x3 = x3;
            if(y3 < 0)
                this->y3 = 0;
            else
                this->y3 = y3;
        }
        
        float lunghezza_primo()
        {
            return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        }
        float lunghezza_secondo()
        {
            return sqrt(pow(x3-x2,2)+pow(y3-y2,2));
        }
        float lunghezza()
        {
            return sqrt(pow(x2-x1,2)+pow(y2-y1,2)) + sqrt(pow(x3-x2,2)+pow(y3-y2,2));
        }

};


int main()
{

    Segmento s1 = Segmento(1,5,1,5);
    cout << s1.lunghezza() << endl;

    Segmenti_Adiacenti s2 = Segmenti_Adiacenti(0,0,4,0,4,3);
    cout << s2.lunghezza_primo() << endl;
    cout << s2.lunghezza_secondo() << endl;
    cout << s2.lunghezza() << endl;

}