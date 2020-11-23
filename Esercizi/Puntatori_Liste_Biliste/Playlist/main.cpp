#include <iostream>
#include <cstring>
using namespace std;

struct playlist
{
    char titolo[100];
    int durata; // in secondi
    int total_play;
    int user_play;
    playlist *next;
};

typedef playlist * p_playlist;

p_playlist insert(p_playlist head, char titolo[], int durata, int total_play, int user_play)
{
    p_playlist p = head;
    if (head == NULL)
    {
        head = new playlist;
        strcpy(head->titolo, titolo);
        head->durata = durata;
        head->total_play = total_play;
        head->user_play = user_play;
        head->next = NULL;
        return(head);
    }
    
    while (head->next != NULL) head = head->next;

    p_playlist tmp = new playlist;
    strcpy(tmp->titolo, titolo);
    tmp->durata = durata;
    tmp->total_play = total_play;
    tmp->user_play = user_play;
    tmp->next = NULL;
    head->next = tmp;
    return(p);
}

p_playlist only_3min(p_playlist head)
{
    p_playlist tmp = NULL;
    while (head != NULL)
    {
        if(head->durata > 180) tmp = insert(tmp, head->titolo, head->durata, head->total_play, head->user_play);
        head = head->next;
    }
    return(tmp);
}

void stampa_lista(p_playlist head)
{
    cout << "Lista:\n";
    while (head != NULL)
    {
        cout << head->titolo << ' ' << head->durata << ' ' << head->total_play << ' ' << head->user_play << endl;
        head = head->next;
    }
    cout << endl;
}


int main()
{
    p_playlist head = NULL;
    
    head = insert(head, (char*)"Ti amo", 280, 1000, 60);
    head = insert(head, (char*)"Bella ciao", 150, 10000, 800);
    head = insert(head, (char*)"We are the world", 50, 500000, 600);
    head = insert(head, (char*)"Beat it", 356, 120914, 461);
    
    stampa_lista(head);

    p_playlist tmp = only_3min(head);

    stampa_lista(tmp);


}