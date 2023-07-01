//
// Created by Mario on 13/05/2023.
//
#include <iostream>
#include<string>
#include <ctime>
#include "masina.h"
#include "Monovolum.h"

using namespace std;
//Constructorii

Monovolum::Monovolum(int capacitate, const std::string &brand, float lungime, int ani, int pret) : Masina(capacitate,
                                                                                                          brand,
                                                                                                          lungime,
                                                                                                          pret),
                                                                                                   tipMasina(
                                                                                                           "Monovolum"),
                                                                                                   ani(ani) {

    if (ani == 0)//Verificam varsta masinii. Daca aceasta are 0 ani inseamna ca este noua, altfel nu
        nou = true;
    else
        nou = false;
};

Monovolum::Monovolum(const Monovolum &c) : Masina(c.capacitateMotor, c.numeBrand, c.lungime, c.pret),
                                           tipMasina("Monovolum"), nou(c.nou), ani(c.ani) {};


//Setter
void Monovolum::setVarstaMasina(int x) {
    this->ani = x;
    if (ani == 0)
        nou = true;
    else
        nou = false;
}

//Getteri

string Monovolum::getTipMasina() { return "Monovolum"; }

bool Monovolum::getMasinaNoua() const { return nou; }

int Monovolum::getVarstaMasina() const { return ani; }


int Monovolum::getPretActual() const {  //Variabila pret stocheaza valoarea masinii cand este noua,
    // cu ajutorul acesteii metode determinam pretul actual, luand in considerare varsta masinii si daca este vara

    int valoare = pret;

    if (5 * ani <
        90)                                           //Verificam cat de veche este masina. Daca masina are peste 18 ani, pretul ei ramane fix
        valoare = valoare *
                  ((100.0 - 5 * ani) / 100.0);        //Modificam valoarea masinii proportional cu varsta acesteia
    else
        valoare = (10.0 / 100.0) * valoare;

    time_t now = time(0);                                 //Determinam data sistemului
    tm *ltm = localtime(&now);
    int luna = 1 + ltm->tm_mon;

    if (luna == 6 || luna == 7 ||
        luna == 8) {                  //Daca este vara indicam valoarea masinii cu un discount de 10%
        valoare = valoare - ((10.0 / 100.0) * valoare);
    }
    return valoare;
}


//Overload pentru operatorii '=', '>>'  si '<<'


Monovolum &Monovolum::operator=(const Monovolum &c) {
    this->lungime = c.lungime;
    this->numeBrand = c.numeBrand;
    this->capacitateMotor = c.capacitateMotor;
    this->tipMasina = c.tipMasina;
    this->nou = c.nou;
    this->ani = c.ani;
    this->pret = c.pret;
    return *this;
}

istream &operator>>(istream &in, Monovolum &c) {
    cout << "Introduce numele masinii\n";
    getline(cin, c.numeBrand);
    cout << "Cati ani are masina:\n";
    unsigned int x;
    cin >> x;                           //Modificam parametrii 'ani' si 'nou' in functie de varsta masinii
    switch (x) {
        case 0:
            c.nou = true;
            c.ani = 0;
            break;
        default:
            c.nou = false;
            c.ani = x;
            break;
    }
    cout << "Introduce capacitatea motorului\n";
    in >> c.capacitateMotor;
    cout << "Introduce lungimea masinii\n";
    in >> c.lungime;
    c.tipMasina = "Monovolum";
    cout << "Introduce pretul masinii noua\n";
    cin >> c.pret;
    cin.get();
    return in;
}

ostream &operator<<(ostream &out, const Monovolum &c) {
    cout << "Numele Masinii:" << c.numeBrand << endl;
    if (c.nou == true)
        cout << "Masina este noua\n";
    else
        cout << "Masina are " << c.ani << " ani\n";
    cout << "Tip masina:" << c.tipMasina << endl;
    cout << "Capacitatea Motorului:" << c.capacitateMotor << endl;
    cout << "Lungimea masinii:" << c.lungime << endl;
    if (c.nou == true) {                                                    //Verificam daca masina este noua si in functie de asta afisam valoarea masinii
        cout << "Pretul masinii:" << c.pret << endl;
        if (c.getPretActual() != c.pret)
            cout << "Pretul masinii cu discount:" << c.getPretActual() << endl;
    } else {
        cout << "Pretul masinii noua:" << c.pret << endl;
        cout << "Pretul masinii actual:" << c.getPretActual() << endl;
    }
    return out;

}

//Destructorul. Nu este nimic alocat dinamic
Monovolum::~Monovolum() {}