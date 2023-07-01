//
// Created by Mario on 13/05/2023.
//
#include "Mini.h"
#include "masina.h"
#include <iostream>
#include<string>

using namespace std;

//Constructorii. Sunt la fel ca in clasa Masina, singura diferenta este tipul masinii care este initializat


Mini::Mini(int capacitate, const std::string& brand, float lungime,int pret) : Masina(capacitate, brand, lungime,pret), tipMasina("Mini") {};

Mini::Mini(const Mini &c) : Masina(c.capacitateMotor, c.numeBrand, c.lungime,c.pret), tipMasina("Mini") {};

//Getter

string Mini::getTipMasina() { return "Mini"; }

//Overload pentru operatorii '=', '>>'  si '<<'

Mini &Mini::operator=(const Mini &c) {
    this->lungime = c.lungime;
    this->numeBrand = c.numeBrand;
    this->capacitateMotor = c.capacitateMotor;
    this->tipMasina = c.tipMasina;
    return *this;
}

istream &operator>>(istream &in, Mini &c) {
    cout << "Introduce numele masinii\n";
    getline(cin, c.numeBrand);
    cout << "Introduce capacitatea motorului\n";
    in >> c.capacitateMotor;
    cout << "Introduce lungimea masinii\n";
    in >> c.lungime;
    c.tipMasina = "Mini";
    cout << "Introduce pretul masinii\n";
    cin >> c.pret;
    cin.get();
    return in;
}

ostream &operator<<(ostream &out, const Mini &c) {
    cout << "Numele Masinii:" << c.numeBrand << endl;
    cout << "Tip masina:" << c.tipMasina << endl;
    cout << "Capacitatea Motorului:" << c.capacitateMotor << endl;
    cout << "Lungimea masinii:" << c.lungime << endl;
    cout << "Pretul masinii:" << c.pret << endl;
    return out;

}

//Destructorul. Nu este nimic alocat dinamic
Mini::~Mini() {}