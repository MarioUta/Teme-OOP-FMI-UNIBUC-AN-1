
#include "Casa.h"
#include "Locuinta.h"
#include <iostream>

Casa::Casa(string numeClient, int suprafataUtila, float discount, int suprafataCurte) : Locuinta(numeClient,
                                                                                                 suprafataUtila,
                                                                                                 discount),
                                                                                        suprafataCurte(
                                                                                                suprafataCurte) {}//Apeleaza constructorul clasei Locuinta,  initializeaza suprafataCurte


Casa::Casa(const Casa &loc) : Locuinta(loc.numeClient, loc.suprafataUtila, loc.discount),                        //Apeleaza constructorul clasei Locuinta,  initializeaza suprafataCurte
                              suprafataCurte(loc.suprafataCurte) {}


void Casa::setSuprafataCurte(int suprafata) { this->suprafataCurte = suprafata; }                               //Setter pentru suprafataCurte


int Casa::getSuprafataCurte() const{ return suprafataCurte; }                                                   //Getter pentru supraftaCurte

int Casa::getEtaj()const {return -1;}                                                                           //getEtaj este o functie virtuala pura in clasa Locuinta, intoarce -1 deoarece Casa nu este la etaj


Casa& Casa::operator=(const Casa &loc) {                                                                        //Supraincarea =
    this->numeClient=loc.numeClient;
    this->suprafataUtila=loc.suprafataUtila;
    this->discount=loc.discount;
    this->suprafataCurte=loc.suprafataCurte;
    return *this;
}

int Casa::tipLocuinta() const {return 2;}                                                                       //Indica tipul de locuinta, ajuta la Upcasting

int Casa::calculChirie(int X, int Y) const {
    return X * (this->suprafataUtila +0.2 * this->suprafataCurte)* (1 - Y * this->discount / 100.0);
}

ostream& operator<<(ostream&out, const Casa& loc){                                                              //Supraincarcarea <<
    cout<<"Tip Locuinta: Casa\n";
    cout<<"Nume client: "<<loc.numeClient<<endl;
    cout<<"Suprafata utila: "<<loc.suprafataUtila<<endl;
    cout<<"Suprafata curte: "<<loc.suprafataCurte<<endl;
    cout<<"Discount: "<<loc.discount<<endl;
    return out;
}
istream &operator>>(istream &in, Casa &loc){                                                                     //Supraincarcarea >>
    cout<<"Introduce numele clientului:\n";
    in>>loc.numeClient;
    cout<<"Introduce suprafta utila:\n";
    in>>loc.suprafataUtila;
    cout<<"Introduce suprafata curte:\n";
    in>>loc.suprafataCurte;
    cout<<"Introduce discount-ul:\n";
    in>>loc.discount;
    return in;
}


Casa::~Casa() {}                                                                                                //Nu are ce sa dezaloce, destructorul clasei Locuinta este virtual, va fi apelat si acesta in cazul upcasting-ului