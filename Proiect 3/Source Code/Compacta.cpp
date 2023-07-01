//
// Created by Mario on 13/05/2023.
//
#include "Compacta.h"
#include "masina.h"
#include <iostream>
#include<string>

using namespace std;

//Constructorii. Sunt la fel ca in clasa Masina, singura diferenta este tipul masinii care este initializat

Compacta::Compacta(int capacitate, const std::string &brand, float lungime, int pret) : Masina(capacitate, brand,
                                                                                               lungime, pret),
                                                                                        tipMasina("Compacta") {};

Compacta::Compacta(const Compacta &c) : Masina(c.capacitateMotor, c.numeBrand, c.lungime, c.pret),
                                        tipMasina("Compacta") {};

//Getter

string Compacta::getTipMasina() { return "Compacta"; }

//Overload pentru operatorii '=', '>>'  si '<<'

Compacta &Compacta::operator=(const Compacta &c) {
    this->lungime = c.lungime;
    this->numeBrand = c.numeBrand;
    this->capacitateMotor = c.capacitateMotor;
    this->tipMasina = c.tipMasina;
    this->pret = c.pret;
    return *this;
}

istream &operator>>(istream &in, Compacta &c) {
    cout << "Introduce numele masinii\n";
    getline(cin, c.numeBrand);
    cout << "Introduce capacitatea motorului\n";
    in >> c.capacitateMotor;
    cout << "Introduce lungimea masinii\n";
    in >> c.lungime;
    c.tipMasina = "Compacta";
    cout << "Introduce pretul masinii\n";
    in >> c.pret;
    cin.get();
    return in;
}

ostream &operator<<(ostream &out, const Compacta &c) {
    cout << "Numele Masinii:" << c.numeBrand << endl;
    cout << "Tip masina:" << c.tipMasina << endl;
    cout << "Capacitatea Motorului:" << c.capacitateMotor << endl;
    cout << "Lungimea masinii:" << c.lungime << endl;
    cout << "Pretul masinii" << c.pret << endl;
    return out;

}

//Destructorul. Nu este nimic alocat dinamic
Compacta::~Compacta() {}