//
// Created by Mario on 13/05/2023.
//

#include "masina.h"
#include "Monovolum.h"
#include "Mica.h"
#include "Mini.h"
#include "Compacta.h"
#include <iostream>
#include <string>

using namespace std;

vector<Masina*> Masina::obiecte;    //Initializam vectorul static

//Constructorii

Masina::Masina(int capacitate, const std::string &brand, float lungime, int pret) : capacitateMotor(capacitate),
                                                                                    numeBrand(brand), lungime(lungime),
                                                                                    pret(pret) {};

Masina::Masina(const Masina &c) : capacitateMotor(c.capacitateMotor), numeBrand(c.numeBrand), lungime(c.lungime),
                                  pret(c.pret) {}


void Masina::citesteNObiecte() {    //Functia care citeste N obiecte

    cout << "Cate obiecte vrei sa citesti?" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
         {
            cout << "Ce tip de masina vrei sa citesti?\n";
            cout << "1.Mini\n2.Mica\n3.Compacta\n4.Monovolum\n";
            int x;
            cin >> x;
            cin.get();
            switch (x) {
                case 1: {
                    Mini *a = new Mini;
                    cin >> *a;
                    obiecte.push_back(a);
                }
                    break;
                case 2: {
                    Mica *b = new Mica;
                    cin >> *b;
                    obiecte.push_back(b);
                }
                    break;
                case 3: {
                    Compacta *c = new Compacta;
                    cin >> *c;
                    obiecte.push_back(c);

                }
                    break;
                case 4: {
                    Monovolum *d = new Monovolum;
                    cin >> *d;
                    obiecte.push_back(d);

                }
                    break;
                default:
                    break;
            }
        }
}

void Masina::afiseazaNObiecte() {   //Functia care afiseaza N obiecte
    for (int i = 0; i < obiecte.size(); i++) {
        Mini *a = dynamic_cast<Mini *>(obiecte[i]);
        Mica *b = dynamic_cast<Mica *>(obiecte[i]);
        Compacta *c = dynamic_cast<Compacta *>(obiecte[i]);
        Monovolum *d = dynamic_cast<Monovolum *>(obiecte[i]);
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

void Masina::dezaloca() {   //Functia care dezaloca n obiecte
    for (int i = 0; i < obiecte.size(); i++) {
        delete obiecte[i];
    }
    obiecte.clear();
}

//Setteri
void Masina::setCapacitateMotor(int x) {
    this->capacitateMotor = x;
}

void Masina::setNumeMasina(const string &x) {
    this->numeBrand = x;
}

void Masina::setLungime(float x) {
    this->lungime = x;
}

void Masina::setPret(int x) {
    this->pret = x;
}

//Getteri

int Masina::getPret() const { return pret; }

string Masina::getTipMasina() const {
    return "masina";
}

int Masina::getCapacitateMotor() const {
    return capacitateMotor;
}

string Masina::getNumeMasina() const {
    return numeBrand;
}

float Masina::getLungime() const {
    return lungime;
}

//Deztructorul. Nu este nimic alocat dinamic si nu am ce sa dezaloc
Masina::~Masina() {}


