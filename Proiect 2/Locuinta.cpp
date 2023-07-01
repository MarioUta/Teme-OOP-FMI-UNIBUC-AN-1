
#include "Locuinta.h"
#include "Apartament.h"
#include "Casa.h"
#include <iostream>

using namespace std;
vector<Locuinta *> Locuinta::Locuinte;                                                                                          //Initalizare vectorului static de pointeri de locuinte, folosit in fucntia care citeste n obiecte de tip Casa/Apartament

Locuinta::Locuinta(std::string numeClient, int suprafataUtila, float discount) : numeClient(numeClient),
                                                                                 suprafataUtila(suprafataUtila),                //Cosntructor
                                                                                 discount(discount) {};

Locuinta::Locuinta(const Locuinta &loc) {                                                                                       //Cosntructor de copiere
    this->numeClient = loc.numeClient;
    this->suprafataUtila = loc.suprafataUtila;
    this->discount = loc.discount;
}


void Locuinta::setNumeClient(std::string nume) { this->numeClient = nume; }                                                     //Setter pentru numeClient

void Locuinta::setSuprafataUtila(int suprafata) { this->suprafataUtila = suprafata; }                                           //Setter pentru suprafataUtila

void Locuinta::setDiscount(float discount) { this->discount = discount; }                                                       //Setter pentru discount

string Locuinta::getNumeClient() const { return this->numeClient; }                                                             //Getter pentru numeClient

int Locuinta::getSuprafataUtila() const { return this->suprafataUtila; }                                                        //Getter pentru suprafataUtila

float Locuinta::getDiscount() const { return this->discount; }                                                                  //Getter pentru discount

void Locuinta::citireLocuinte() {                                                                                               //Functie care citeste si memoreaza n obiecte de tip Casa/Apartament
    cout << "Cate locuinte vrei sa citesti?\n";
    int n;
    cin >> n;                                                                                                                   //Numarul de locuinte pe care urmeaza sa-l citim

    if (Locuinte.size() != 0) {                                                                                                 //Verifica daca vectorul era initial gol, sau daca avea deja locuinte salvate
        for (int i = 0; i < Locuinte.size(); i++)
            delete Locuinte[i];
        Locuinte.clear();
    }                                                                                                                           //Dezaloca variblele alocte dinamic din vector
    for (int i = 0; i < n; i++) {
        cout << "Apasa 1 daca locuinta este apartament\nApasa 2 daca locuinta este Casa\n";
        int choice;
        cin >> choice;
        if (choice == 1) {                                                                                                      //Alegem tipul de locuinta pe care vrem sa-l introducem
            Apartament *a = new Apartament();
            cin >> *a;
            Locuinte.push_back(a);
        }                                                                                                                       //Creeaza un pointer a, de tip apartament/casa, citeste valoarea care se regaseste la adresa de memorie indicata de a, dupa introduce pointer-ul a in vector
        if (choice == 2) {
            Casa *b = new Casa();
            cin >> *b;
            Locuinte.push_back(b);
        }
    }
}

void Locuinta::aisareLocuinte() {                                                                                              //Afiseaza cele n obiecte citie
    for (int i = 0; i < Locuinte.size(); i++) {
        if (Locuinte[i]->tipLocuinta() == 1) {
            cout << "Tip Locuinta: Apartament\n";
            cout << "Nume client: " << Locuinte[i]->getNumeClient() << endl;
            cout << "Suprafata utila: " << Locuinte[i]->getSuprafataUtila() << endl;
            cout << "Etaj: " << Locuinte[i]->getEtaj() << endl;
            cout << "Discount: " << Locuinte[i]->getDiscount() << endl << endl;
        }
        if (Locuinte[i]->tipLocuinta() == 2) {
            cout << "Tip Locuinta: Casa\n";
            cout << "Nume client: " << Locuinte[i]->getNumeClient() << endl;
            cout << "Suprafata utila: " << Locuinte[i]->getSuprafataUtila() << endl;
            cout << "Suprafata curte: " << Locuinte[i]->getSuprafataCurte() << endl;
            cout << "Discount: " << Locuinte[i]->getDiscount() << endl << endl;
        }
    }
}
void Locuinta::dezaloca(){                                                                                                   //Functie care dezaloca valorile din vectorul Locuinte si elimina valorile din acesta
    for (int i = 0; i < Locuinte.size(); i++) {
        delete Locuinte[i];                                                                                                  //Elimina pe rand valorile retinute de fiecare pointer de tip Locuinta din vectorul 'Locuinte'
    }
    Locuinte.clear();                                                                                                       //Elimina continutul vectorului Locuinte
}

Locuinta::~Locuinta() {}                                                                                                    //Destructorul, cum nu putem dezaloca vectorul Locuinte, deoarece acesta este static, nu dezalocam nimic prin destructor, daca am fi dezaloc aici vectorul.
                                                                                                                            //ar fi aparut probleme in cazul declararii mai multor obiecte care mostenesc clasa locuinta, acestea stergand cele n obiecte citite, inainte sa vrem renuntam la ele