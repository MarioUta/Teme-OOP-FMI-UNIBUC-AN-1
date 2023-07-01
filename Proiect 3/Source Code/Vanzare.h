//
// Created by Mario on 15/05/2023.
//



#ifndef TEMA_3_VANZARE_H
#define TEMA_3_VANZARE_H

#include <iostream>
#include<set>
#include<utility>
#include "masina.h"
#include "Mini.h"
#include "Mica.h"
#include "Compacta.h"
#include "Monovolum.h"


/////////////////////////////////////////Explicatie///////////////////////////////////////////////////

//Anumite implementari sunt in source file, altele sunt inline. Motivul este dat de problemele de linkare cauzate de
//functiile friend si de specializare Vanzare<Monovolum>. Acest post pe StackOverlow indica faptul ca implementarea
//inline pentru clasele template, atunci cand sunt scrise intr-un header file, este singura cu adevarat viabila
//https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file.
//Am pastrat totusi implementarea din source file deoarece voiam sa am codul cat de separat posibil.


//////////////////////////////////////////////////////////////////////////////////////////////////////

//Clasa template Vanzare


template<class T>
class Vanzare {
private:

    T **masiniStoc;             //Array-ul dinamic in care retinem masinile pe care inca le mai avem in stoc
    T **masiniVandute;          //Array-ul dinamic in care retinem masinile pe care le-am vandut
    int numarMasiniStoc;        //Numarul de masini pe care le avem in stoc
    int numarMasiniVandute;     //Numarul masini vandute
    set<pair<T *, bool> > stocMasini;//Set in care tinem toate masinile(vandute si in stoc) cu o varibila de tip bool care arata daca o masina este noua sau nu

    bool esteInStoc(const T *masini) const;//Metoda care verifica daca masina este in stoc

public:
    //Constructorii
    Vanzare();

    Vanzare(const set<pair<T *, bool> > &masini);

    Vanzare(const Vanzare &masini);

    //Getteri

    int getNumarMasiniStoc() const;

    int getNumarMasiniVandute() const;
    ///

    void afiseazaMasinileVandute() const; //Metoda care afiseaza lista masinilor vandute

    void afiseazaMasinilieInStoc() const;//Metoda care afiseaza lista masinilor in stoc

    //Overload pentru operatorii '=', '-=', '[]', '<<', '>>'

    Vanzare &operator=(const Vanzare<T> &masini);

    Vanzare &operator-=(Masina &masini);

    Masina &operator[](int index) const;

    friend ostream &operator<<(ostream &out, const Vanzare &masini) {

        out << "Masinilie in stoc:\n\n";
        masini.afiseazaMasinilieInStoc();     //Afisam elementele din array-ul masiniStoc

        out << "\nMasinile Vandute:\n\n";
        masini.afiseazaMasinileVandute(); //Afisam elementele din array-ul masiniVandute

        return out;
    }

    friend istream &operator>>(istream &in, Vanzare &masini) {

        if (masini.numarMasiniStoc != 0 || masini.numarMasiniVandute !=
                                           0) {    //Verificam daca in obiectul nostru au fost stocate anterior alte obiecte. Daca da, le dezalocam dinamic
            typename set<pair<T *, bool> >::iterator i;
            i = masini.stocMasini.begin();
            for (i; i != masini.stocMasini.end(); i++) {
                delete i->first;
            }
            masini.stocMasini.clear();
            delete[]masini.masiniStoc;
            delete[]masini.masiniVandute;
        }
        cout << "Cate masini vrei sa citesti?\n";
        int n;
        in >> n;
        cin.get();
        try {
            masini.masiniVandute = new T *[n];                              //Array-urile au ambele aceeasi marime, anume numarul total de masini
            masini.masiniStoc = new T *[n];
        }
        catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
        masini.numarMasiniStoc = n;
        masini.numarMasiniVandute = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            cout << "Ce tip de masina vrei sa citesti?\n";
            cout << "1.Mini\n2.Mica\n3.Compacta\n4.Monovolum\n";
            int x;
            in >> x;
            cin.get();
            try {
                switch (x) {                                                    //Toate masinile citite vor fi considerate in stoc. Daca masina nu este monovolum, este considetrata automat o masina noua
                    case 1: {
                        Mini *a = new Mini;
                        in >> *a;
                        masini.stocMasini.insert(make_pair(a, true));
                        masini.masiniStoc[j] = a;
                        j++;
                    }
                        break;
                    case 2: {
                        Mica *b = new Mica;
                        in >> *b;
                        masini.stocMasini.insert(make_pair(b, true));
                        masini.masiniStoc[j] = b;
                        j++;
                    }
                        break;
                    case 3: {
                        Compacta *c = new Compacta;
                        in >> *c;
                        masini.stocMasini.insert(make_pair(c, true));
                        masini.masiniStoc[j] = c;
                        j++;
                    }
                        break;
                    case 4: {
                        Monovolum *d = new Monovolum;
                        in >> *d;
                        masini.stocMasini.insert(make_pair(d, d->getMasinaNoua()));
                        masini.masiniStoc[j] = d;
                        j++;
                    }
                        break;
                    default:
                        break;
                }
            } catch (bad_alloc &e) {
                cout << "Allocation failed" << '\n';
                exit(1);
            }
        }
        return in;
    }

    //Destructorul
    ~Vanzare();

};

//Specializarea tempalate-ului pentru Monovolum, care gestioneaza numai Monovolume
//Implementarea este aproape identica cu cea default, diferenta este data de lipsa dynamic_cast - urilor pentru restul claselor de masini

template<>
class Vanzare<Monovolum> {

private:
    Monovolum **masiniStoc;
    Monovolum **masiniVandute;
    int numarMasiniStoc;
    int numarMasiniVandute;
    set<pair<Monovolum *, bool> > stocMasini;

    bool esteInStoc(const Monovolum *masini) const {
        for (int i = 0; i < numarMasiniStoc; i++)
            if (masiniStoc[i] == masini)
                return true;
        return false;
    };

public:
    Vanzare() : numarMasiniStoc(0), numarMasiniVandute(0) {
        try {
            this->masiniStoc = new Monovolum *[0];
            this->masiniVandute = new Monovolum *[0];
        }
        catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
    };

    Vanzare(const set<pair<Monovolum *, bool> > &masini) : numarMasiniVandute(0), numarMasiniStoc(masini.size()) {

        try {

            this->masiniStoc = new Monovolum *[masini.size()];

            this->masiniVandute = new Monovolum *[masini.size()];
        }
        catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
        typename set<pair<Monovolum *, bool> >::iterator i;
        int j = 0;

        for (i = masini.begin(); i != masini.end(); i++) {
            Monovolum *d = dynamic_cast<Monovolum *>(i->first);
            try {
                if (d != NULL) {
                    Monovolum *copie = new Monovolum(*d);
                    masiniStoc[j] = copie;
                    j++;
                    this->stocMasini.insert(make_pair(copie, false));
                } else
                    exit(1);
            }
            catch (bad_alloc &e) {
                cout << "Allocation failed" << '\n';
                exit(1);
            }
        }
    }

    Vanzare(const Vanzare &masini) : numarMasiniStoc(masini.numarMasiniStoc),
                                     numarMasiniVandute(masini.numarMasiniVandute) {
        try {
            this->masiniStoc = new Monovolum *[masini.stocMasini.size()];
            this->masiniVandute = new Monovolum *[masini.stocMasini.size()];
        }
        catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
        typename set<pair<Monovolum *, bool> >::iterator i;
        int j = 0, k = 0;
        for (i = masini.stocMasini.begin(); i != masini.stocMasini.end(); i++) {
            Monovolum *d = dynamic_cast<Monovolum *>(i->first);
            try {
                if (d != NULL) {
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
                } else
                    exit(1);
            } catch (bad_alloc &e) {
                cout << "Allocation failed" << '\n';
                exit(1);
            }
        }

    }

    int getNumarMasiniStoc() const { return numarMasiniStoc; }

    int getNumarMasiniVandute() const { return numarMasiniVandute; }

    void afiseazaMasinileVandute() const {

        for (int i = 0; i < numarMasiniVandute; i++) {
            Monovolum *d = dynamic_cast<Monovolum *>(masiniVandute[i]);
            if (d != NULL) {
                cout << *d << endl;
            }
        }
    }

    void afiseazaMasinilieInStoc() const {

        for (int i = 0; i < numarMasiniStoc; i++) {

            Monovolum *d = dynamic_cast<Monovolum *>(masiniStoc[i]);
            if (d != NULL) {
                cout << *d << endl;
            }
        }
    };

    Vanzare &operator=(const Vanzare<Monovolum> &masini) {

        if (numarMasiniStoc != 0 || numarMasiniVandute != 0) {
            typename set<pair<Monovolum *, bool> >::iterator i;
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
            this->masiniStoc = new Monovolum *[masini.stocMasini.size()];
            this->masiniVandute = new Monovolum *[masini.stocMasini.size()];
        } catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
        typename set<pair<Monovolum *, bool> >::iterator i;
        int j = 0, k = 0;
        for (i = masini.stocMasini.begin(); i != masini.stocMasini.end(); i++) {
            Monovolum *d = dynamic_cast<Monovolum *>(i->first);
            try {
                if (d != NULL) {
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
                } else
                    exit(1);
            } catch (bad_alloc &e) {
                cout << "Allocation failed" << '\n';
                exit(1);
            }
        }
        return *this;
    }

    Vanzare &operator-=(Monovolum &masini) {
        int k = 0;
        while (masiniStoc[k] != &masini &&k < numarMasiniStoc)
            k++;
        if (k < numarMasiniStoc) {
            masiniVandute[numarMasiniVandute] = &masini;
            numarMasiniVandute++;
            for (k; k < numarMasiniStoc - 1; k++) {
                masiniStoc[k] = masiniStoc[k + 1];
            }
            numarMasiniStoc--;
        }

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Vanzare<Monovolum> &masini) {
        out << "Masinilie in stoc:\n\n";
        masini.afiseazaMasinilieInStoc();
        out << "\nMasinile Vandute:\n\n";
        masini.afiseazaMasinileVandute();
        return out;
    }

    friend istream &operator>>(istream &in, Vanzare<Monovolum> &masini) {

        if (masini.numarMasiniStoc != 0 || masini.numarMasiniVandute != 0) {
            typename set<pair<Monovolum *, bool> >::iterator i;
            i = masini.stocMasini.begin();
            for (i; i != masini.stocMasini.end(); i++) {
                delete i->first;
            }
            masini.stocMasini.clear();
            delete[]masini.masiniStoc;
            delete[]masini.masiniVandute;
        }
        cout << "Cate masini vrei sa citesti?\n";
        int n;
        in >> n;
        cin.get();
        try {
            masini.masiniVandute = new Monovolum *[n];
            masini.masiniStoc = new Monovolum *[n];
        }
        catch (bad_alloc &e) {
            cout << "Allocation failed" << '\n';
            exit(1);
        }
        masini.numarMasiniStoc = n;
        masini.numarMasiniVandute = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            try {
                Monovolum *d = new Monovolum;
                in >> *d;
                masini.stocMasini.insert(make_pair(d, d->getMasinaNoua()));
                masini.masiniStoc[j] = d;
                j++;
            }
            catch (bad_alloc &e) {
                cout << "Allocation failed" << '\n';
                exit(1);
            }
        }
        return in;
    }

    Monovolum &operator[](int index) const {
        return *masiniStoc[index];
    };

    ~Vanzare() {
        typename set<pair<Monovolum *, bool> >::iterator i;
        i = stocMasini.begin();
        for (i; i != stocMasini.end(); i++) {
            delete i->first;
        }
        stocMasini.clear();
        delete[]masiniStoc;
        delete[]masiniVandute;
    };

};


#endif //TEMA_3_VANZARE_H
