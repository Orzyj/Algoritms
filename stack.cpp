#include <iostream>

using namespace std;

struct stos{
    int x;
    stos * poprzedni_element;
};

void dodanie(stos ** poczatek){
    stos * nowy = new stos;
    if(nowy == NULL) return;

    cout << "Podaj liczbe: ";
    cin >> nowy->x;

    nowy->poprzedni_element = *poczatek;
    *poczatek = nowy;
}

void usun(stos ** poczatek){
    if(*poczatek == NULL) return;
    stos * pomoc = *poczatek;
    *poczatek = (*poczatek)->poprzedni_element;
    delete pomoc;
}

void wypis(stos * poczatek){
    if(poczatek == NULL) return;
    stos * pomoc = poczatek;

    cout << "\n\nStos: \n";
    while(pomoc){
        cout << (*pomoc).x << endl;
        pomoc = (*pomoc).poprzedni_element;
    }

    cout << endl;
}

//-------------------

bool czyPusty(stos * poczatek){
    if(poczatek == NULL) return true;
    return false;
}

void zliczanie(stos * poczatek){
    int i = 0;
    if(poczatek == NULL) return;
    stos * pomoc = poczatek;

    cout << "\n\nStos: \n";
    while(pomoc){
        pomoc = (*pomoc).poprzedni_element;
        i++;
    }

    cout << "Elementów: " << i << endl;

    cout << endl;
}

//------------------

int main(){
     stos * poczatek = NULL; 
    char wybor;

    do {
        cout << "\n1.Dodanie\n2.Usuwanie\n3.Wypis\nPodaj opcje: ";
        cin >> wybor;
        switch(wybor){
            case '1': dodanie(&poczatek); break;
            case '2': usun(&poczatek); break;
            case '3': wypis(poczatek); break;
        }
    } while (wybor != '5');

    return 0;
}