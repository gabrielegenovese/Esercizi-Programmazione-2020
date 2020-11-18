#include <iostream>
using namespace std;

struct bilista
{
    int val;
    bilista *next;
    bilista *prec;
};

int length = 10;
typedef bilista* p_bilista ;

struct bilista_p {
	p_bilista head ;
	p_bilista tail ;
};

bilista_p init_bilista(int n) {
	bilista_p H;
	p_bilista p = new bilista, prec = NULL;
    int i = 0;
	H.head = p;
	
	for (i = 0; i < length-1; i++)
    {
        p_bilista tmp = new bilista;
        p->val = rand()%100;
        p->next = tmp;
        p->prec = prec;
        prec = p;
        p = tmp;
    }
    
    p->val = i;
    p->next = NULL;
	p->prec = prec;

	H.tail = p;

	return(H);
}

void stampa_tail (bilista_p H)
{
	p_bilista tail = H.tail ;

	while (tail != NULL){
		cout << tail->val << '\t' ;
		tail = tail->prec ;
	}

    cout << endl;
}

void stampa_head (bilista_p H)
{
	p_bilista head = H.head ;

	while (head != NULL){
		cout << head->val << '\t' ;
		head = head->next ;
	}

    cout << endl;
}

int main()
{
	srand(time(NULL));
    bilista_p h1 = init_bilista(length);
    stampa_head(h1);
    stampa_tail(h1);
	return(0);
}
