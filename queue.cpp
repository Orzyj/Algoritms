#include <iostream>

using namespace std;

struct kolejka {
    int x;
    string nazwa;
    kolejka* nastepny;
};

void dodaj(kolejka** poczatek, kolejka** koniec) {
    kolejka* nowy = new kolejka;
    if (nowy == NULL)return;
    cout << "Podaj liczbe: ";

    cin >> nowy->x;
    cin >> nowy->nazwa;
    
    if (*poczatek == NULL) {
        nowy->nastepny = NULL;
        *poczatek = nowy;
        (*poczatek)->nastepny = NULL;

        *koniec = nowy;
    }
    else {
        nowy->nastepny = NULL;
        (*koniec)->nastepny = nowy;
        *koniec = nowy;
    }
}

void usun(kolejka** poczatek, kolejka** koniec) {
    if (*poczatek == NULL)return;
    if (*poczatek == *koniec) {
        delete* poczatek;
        *poczatek = NULL;
        *koniec = NULL;
    }
    else {
        kolejka* pomoc = *poczatek;
        *poczatek = (*poczatek)->nastepny;
        delete pomoc;
    }


}
void wypis(kolejka* poczatek, kolejka* koniec) {
    if (poczatek == NULL)return;
    kolejka* pomoc = poczatek;
    cout << "Kolejka: ";
    while (pomoc) {

        cout << (*pomoc).x << " ";
        pomoc = (*pomoc).nastepny;
    }
}

//----------------

bool czyPuste(kolejka* poczatek, kolejka* koniec){
    if (poczatek == NULL) return true;
    return false;
}

void zliczanie(kolejka* poczatek, kolejka* koniec) {
    int i = 0;
    if (poczatek == NULL)return;
    kolejka* pomoc = poczatek;
    cout << "Kolejka: ";
    while (pomoc) {
        pomoc = (*pomoc).nastepny;
        i++;
    }
    cout << "Elementow: " << i << endl;
}

//---------------

int main() {
    char wybor;
    kolejka* pocz = NULL, * kon = NULL;
    do
    {
        cout << "Wybierz co chcesz zrobic:\n1) Dodanie elementu do kolejki\n2) Usuniecie elementu z kolejki\n3) Wyprowadzenie zawartosci kolejki na ekran\nWybor: ";
        cin >> wybor;
        cout << endl;

        switch (wybor)
        {
        case '1':

            dodaj(&pocz, &kon);
            break;

        case '2':
            usun(&pocz, &kon);
            break;

        case '3':
            wypis(pocz, kon);
            std::cout << std::endl;
            break;
        }
    } while (wybor != '6');
    return 0;
}