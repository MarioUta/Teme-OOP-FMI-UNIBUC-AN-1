//
// Created by Mario on 13/05/2023.
//
#include "Mica.h"
#include "masina.h"
#include <iostream>
#include<string>

using namespace std;

//Constructorii. Sunt la fel ca in clasa Masina, singura diferenta este tipul masinii care este initializat


Mica::Mica(int capacitate, const std::string &brand, float lungime, int pret) : Masina(capacitate, brand, lungime,
                                                                                       pret), tipMasina("Mica") {};

Mica::Mica(const Mica &c) : Masina(c.capacitateMotor, c.numeBrand, c.lungime, c.pret), tipMasina("Mica") {};

//Getter

string Mica::getTipMasina() { return "Mica"; }


//Overload pentru operatorii '=', '>>'  si '<<'


Mica &Mica::operator=(const Mica &c) {
    this->lungime = c.lungime;
    this->numeBrand = c.numeBrand;
    this->capacitateMotor = c.capacitateMotor;
    this->tipMasina = c.tipMasina;
    this->pret = c.pret;
    return *this;
}

istream &operator>>(istream &in, Mica &c) {
    cin>>dynamic_cast<Masina&>(c);
    cin.get();
    return in;
}

ostream &operator<<(ostream &out, const Mica &c) {
    cout << "Numele Masinii:" << c.numeBrand << endl;
    cout << "Tip masina:" << c.tipMasina << endl;
    cout << "Capacitatea Motorului:" << c.capacitateMotor << endl;
    cout << "Lungimea masinii:" << c.lungime << endl;
    cout << "Pretul masinii:" << c.pret << endl;
    return out;

}

//Destructorul. Nu este nimic alocat dinamic
Mica::~Mica() {}