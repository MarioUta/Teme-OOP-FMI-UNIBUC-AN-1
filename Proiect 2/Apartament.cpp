
#include "Apartament.h"
#include <iostream>

Apartament::Apartament(string numeClient, int suprafataUtila, float discount, int etaj) : Locuinta(numeClient,
                                                                                                   suprafataUtila,
                                                                                                   discount),
                                                                                          etaj(etaj) {}                     //Apeleaza constructorul clasei Locuinta,  initializeaza etaj


Apartament::Apartament(const Apartament &loc) : Locuinta(loc.numeClient, loc.suprafataUtila, loc.discount),                 //Apeleaza constructorul clasei Locuinta, initializeaza etaj
                                                etaj(loc.etaj) {

}

void Apartament::setEtaj(int etaj) { this->etaj = etaj; }                                                                   //Setter pentru etaj

int Apartament::getEtaj() const { return etaj; }                                                                            //Getter pentru etaj

int Apartament::getSuprafataCurte() const {return -1;}                                                                      //getSuprafataCurte este o functie virtuala pura in clasa Locuinta, intoarce -1 deoarece apartamentul nu are curte

int Apartament::calculChirie(int X, int Y) const {                                                                          //functia calculChirie din cerinta
    if(Y==0||Y==1)
        return X * this->suprafataUtila * (1 - Y * discount / 100.0);
    else
    {
        cout<<"Y poate lua doar valorile 0 si 1\n";
        return 0;
    }
}

int Apartament::tipLocuinta() const {return 1;}                                                                             //Indica tipul de locuinta, ajuta la Upcasting

Apartament& Apartament::operator=(const Apartament &loc) {                                                                  //Supraincarea =
    this->numeClient=loc.numeClient;
    this->suprafataUtila=loc.suprafataUtila;
    this->discount=loc.discount;
    this->etaj=loc.etaj;
    return *this;
}

ostream& operator<<(ostream&out, const Apartament& loc){                                                                   //Supraincarcarea <<
    cout<<"Tip Locuinta: Apartament\n";
    cout<<"Nume client: "<<loc.numeClient<<endl;
    cout<<"Suprafata utila: "<<loc.suprafataUtila<<endl;
    cout<<"Etaj: "<<loc.etaj<<endl;
    cout<<"Discount: "<<loc.discount<<endl;
    return out;
}
istream& operator>>(istream&in,Apartament& loc)                                                                           //Supraincarcarea >>
{
    cout<<"Introduce numele clientului:\n";
    in>>loc.numeClient;
    cout<<"Introduce suprafta utila:\n";
    in>>loc.suprafataUtila;
    cout<<"Introduce etajul la care se afla locuinta:\n";
    in>>loc.etaj;
    cout<<"Introduce discount-ul:\n";
    in>>loc.discount;
    return in;
}

Apartament::~Apartament() {}                                                                                             //Nu are ce sa dezaloce, destructorul clasei Locuinta este virtual, va fi apelat si acesta in cazul upcasting-ului