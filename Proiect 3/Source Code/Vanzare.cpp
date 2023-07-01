//
// Created by Mario on 15/05/2023.
//

#include <iostream>
#include<set>
#include<utility>

#include "Vanzare.h"
#include "masina.h"
#include "Mini.h"
#include "Mica.h"
#include "Compacta.h"
#include "Monovolum.h"


/////////////////////////////////////////Explicatie////////////////////////////////////////////////////////

//Anumite implementari sunt in source file, altele sunt inline. Motivul este dat de problemele de linkare cauzate de
//functiile friend si de specializare Vanzare<Monovolum>. Acest post pe StackOverlow indica faptul ca implementarea
//inline pentru clasele template, atunci cand sunt scrise intr-un header file, este singura cu adevarat viabila
//https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file.
//Am pastrat totusi implementarea din source file deoarece voiam sa am codul cat de separat posibil.


///////////////////////////////////////////////////////////////////////////////////////////////////////////


//Constructorii

template<class T>
Vanzare<T>::Vanzare() : numarMasiniStoc(0),
                        numarMasiniVandute(0) {//Constructorul fara parametrii. Initalizez array-urile
    //cu 0 elemente
    try {
        this->masiniStoc = new T *[0];
        this->masiniVandute = new T *[0];
    }
    catch (bad_alloc &e) {
        cout << "Allocation failed" << '\n';
        exit(1);
    }
}

//Constructorul de copiere

template<class T>
Vanzare<T>::Vanzare(const Vanzare &masini):numarMasiniStoc(masini.numarMasiniStoc),
                                           numarMasiniVandute(masini.numarMasiniVandute) {
    try {
        this->masiniStoc = new T *[masini.stocMasini.size()];   //masiniStoc si masinVandute sunt initializate cu numarul de
        //elemente din set-ul obiectului copiat
        this->masiniVandute = new T *[masini.stocMasini.size()];
    }
    catch (bad_alloc &e) {
        cout << "Allocation failed" << '\n';
        exit(1);
    }

    typename set<pair<T *, bool> >::iterator i;//Iteratorul pentru set;

    int j = 0, k = 0;//Indicii pentru array-urle masiniStoc si Masini Vandute

    for (i = masini.stocMasini.begin(); i != masini.stocMasini.end(); i++) {    //Copiem elementele din obiectul copiat
        Mini *a = dynamic_cast<Mini *>(i->first);
        Mica *b = dynamic_cast<Mica *>(i->first);
        Compacta *c = dynamic_cast<Compacta *>(i->first);
        Monovolum *d = dynamic_cast<Monovolum *>(i->first);
        try {
            // Pentru fiecare element copiat, construim un alt element cu aceleasi valori, dar cu o locatie diferita
            // in memorie. In schimb elementele din masiniStoc si masiniVandute pastreaza aceeasi locatie din memorie
            // cu elementele din set-ul obiectului lor. Acest lucru ajuta la dezalocare si la implementare operatorului -=

            if (a != NULL) {
                Mini *copie = new Mini(*a);
                if (masini.esteInStoc(a)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.insert(make_pair(copie, true));
            } else if (b != NULL) {
                Mica *copie = new Mica(*b);
                if (masini.esteInStoc(b)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.insert(make_pair(copie, true)
                );
            } else if (c != NULL) {
                Compacta *copie = new Compacta(*c);
                if (masini.esteInStoc(c)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.
                        insert(make_pair(copie, true)
                );
            } else if (d != NULL) {
                Monovolum *copie = new Monovolum(*d);
                if (masini.esteInStoc(d)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.
                        insert(make_pair(copie, false)
                );
            }
        }
        catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
    }

};


//Implementare foarte asemanatoare cu cea a constructorului de copiere, singura diferenta este ca toate valorile din set-ul
//copiat sunt considerate in stoc

template<class T>
Vanzare<T>::Vanzare(const set<pair<T *, bool> > &masini):numarMasiniVandute(0), numarMasiniStoc(masini.size()) {

    try {
        this->masiniStoc = new T *[masini.size()];

        this->masiniVandute = new T *[masini.size()];
    } catch (bad_alloc &e) {
        cout << "Allocation failed" << '\n';
        exit(1);
    }

    typename set<pair<T *, bool> >::iterator i;
    int j = 0;

    for (i = masini.begin(); i != masini.end(); i++) {
        Mini *a = dynamic_cast<Mini *>(i->first);
        Mica *b = dynamic_cast<Mica *>(i->first);
        Compacta *c = dynamic_cast<Compacta *>(i->first);
        Monovolum *d = dynamic_cast<Monovolum *>(i->first);
        try {
            if (a != NULL) {
                Mini *copie = new Mini(*a);
                masiniStoc[j] = copie;
                j++;
                this->stocMasini.insert(make_pair(copie, true));
            } else if (b != NULL) {
                Mica *copie = new Mica(*b);
                masiniStoc[j] = copie;
                j++;
                this->stocMasini.
                        insert(make_pair(copie, true)
                );
            } else if (c != NULL) {
                Compacta *copie = new Compacta(*c);
                masiniStoc[j] = copie;
                j++;
                this->stocMasini.
                        insert(make_pair(copie, true)
                );
            } else if (d != NULL) {
                Monovolum *copie = new Monovolum(*d);
                masiniStoc[j] = copie;
                j++;
                this->stocMasini.insert(make_pair(copie, false));
            }
        } catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
    }
}

//Metoda care verifica daca masina este in stoc
template<class T>
bool Vanzare<T>::esteInStoc(const T *masini) const {
    for (int i = 0; i < numarMasiniStoc; i++)
        if (masiniStoc[i] == masini)
            return true;
    return false;
}

//Getteri

template<class T>
int Vanzare<T>::getNumarMasiniStoc() const { return numarMasiniStoc; }

template<class T>
int Vanzare<T>::getNumarMasiniVandute() const { return numarMasiniVandute; }

template<class T>

//Metoda care afiseaza masinile vandute
void Vanzare<T>::afiseazaMasinileVandute() const {

    for (int i = 0; i < numarMasiniVandute; i++) {
        Mini *a = dynamic_cast<Mini *>(masiniVandute[i]);
        Mica *b = dynamic_cast<Mica *>(masiniVandute[i]);
        Compacta *c = dynamic_cast<Compacta *>(masiniVandute[i]);
        Monovolum *d = dynamic_cast<Monovolum *>(masiniVandute[i]);
        if (a != NULL) {
            cout << *a << endl;

        } else if (b != NULL) {
            cout << *b << endl;

        } else if (c != NULL) {
            cout << *c << endl;

        } else if (d != NULL) {
            cout << *d << endl;
        }
    }
}

//Metoda care afiseaza masinile in stoc

template<class T>
void Vanzare<T>::afiseazaMasinilieInStoc() const {

    for (int i = 0; i < numarMasiniStoc; i++) {
        Mini *a = dynamic_cast<Mini *>(masiniStoc[i]);
        Mica *b = dynamic_cast<Mica *>(masiniStoc[i]);
        Compacta *c = dynamic_cast<Compacta *>(masiniStoc[i]);
        Monovolum *d = dynamic_cast<Monovolum *>(masiniStoc[i]);
        if (a != NULL) {
            cout << *a << endl;

        } else if (b != NULL) {
            cout << *b << endl;

        } else if (c != NULL) {
            cout << *c << endl;

        } else if (d != NULL) {
            cout << *d << endl;
        }
    }
}

//Overlaod pe operatorul -=

template<class T>
Vanzare<T> &Vanzare<T>::operator-=(Masina &masini) {

    int k = 0;
    while (masiniStoc[k] != &masini && k < numarMasiniStoc)     //verifica daca exista masina stoc prin a verifica daca
                                                                //exista locatia din memorie a obiectului in masiniStoc
        k++;

    if (k < numarMasiniStoc) {                                  //Daca gaseste obicetul, il adauga in masiniVandute
                                                                //Si il sterge din masiniStoc fara a-l dezaloca.
        masiniVandute[numarMasiniVandute] = &masini;
        numarMasiniVandute++;
        for (k; k < numarMasiniStoc - 1; k++) {
            masiniStoc[k] = masiniStoc[k + 1];
        }
        numarMasiniStoc--;
    }

    return *this;
}

//Overload pe operatorul =. Identic cu cosntructorul de copiere
template<class T>
Vanzare<T> &Vanzare<T>::operator=(const Vanzare<T> &masini) {

    if (numarMasiniStoc != 0 || numarMasiniVandute != 0) {
        typename set<pair<T *, bool> >::iterator i;
        i = stocMasini.begin();
        for (i; i != stocMasini.end(); i++) {
            delete i->first;
        }
        stocMasini.clear();
        delete[]masiniStoc;
        delete[]masiniVandute;
    }
    numarMasiniStoc = masini.numarMasiniStoc;
    numarMasiniVandute = masini.numarMasiniVandute;
    try {
        this->masiniStoc = new T *[masini.stocMasini.size()];
        this->masiniVandute = new T *[masini.stocMasini.size()];
    }
    catch (bad_alloc &e) {
        cout << "Allocation failed" << '\n';
        exit(1);
    }
    typename set<pair<T *, bool> >::iterator i;
    int j = 0, k = 0;
    for (i = masini.stocMasini.begin(); i != masini.stocMasini.end(); i++) {
        Mini *a = dynamic_cast<Mini *>(i->first);
        Mica *b = dynamic_cast<Mica *>(i->first);
        Compacta *c = dynamic_cast<Compacta *>(i->first);
        Monovolum *d = dynamic_cast<Monovolum *>(i->first);
        try {
            if (a != NULL) {
                Mini *copie = new Mini(*a);
                if (masini.esteInStoc(a)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.insert(make_pair(copie, true));
            } else if (b != NULL) {
                Mica *copie = new Mica(*b);
                if (masini.esteInStoc(b)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.insert(make_pair(copie, true)
                );
            } else if (c != NULL) {
                Compacta *copie = new Compacta(*c);
                if (masini.esteInStoc(c)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.
                        insert(make_pair(copie, true)
                );
            } else if (d != NULL) {
                Monovolum *copie = new Monovolum(*d);
                if (masini.esteInStoc(d)) {
                    masiniStoc[j] = copie;
                    j++;
                } else {
                    masiniVandute[k] = copie;
                    k++;
                }
                this->stocMasini.
                        insert(make_pair(copie, false)
                );
            }
        } catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
    }
    return *this;
}

//Overload pe operatorul '[]'
//Intoarce masina aflata la indicele 'index' din array-ul masiniStoc

template<class T>
Masina &Vanzare<T>::operator[](int index) const {
    return *masiniStoc[index];
}
//Destructorul

template<class T>
Vanzare<T>::~Vanzare() {
    typename set<pair<T *, bool> >::iterator i; //Iteratorul pentru set
    i = stocMasini.begin();
    for (i; i != stocMasini.end(); i++) {   //Dezalocam pointerii Masina* tinuti in set.
        delete i->first;
    }
    stocMasini.clear();//Dam clear set-ului
    //Dezalocam masiniStoc si masiniVandute fara a dezaloca valorile tinute de elementele acestora deoarce deja am facut-o
    //cand am dezalocat elementele din set.
    delete[]masiniStoc;
    delete[]masiniVandute;
}
