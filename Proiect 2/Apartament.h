

#ifndef PROIECT3_APARTAMENT_H
#define PROIECT3_APARTAMENT_H

#include "Locuinta.h"
#include <string>

using namespace std;

class Apartament : public Locuinta {            //Mosteneste public Locuinta
private:
    int etaj;
public:
    //Constructori

    Apartament(string numeClient = "Anonim", int suprafataUtila = 0, float discount = 0, int etaj = 0);

    Apartament(const Apartament &loc);

    //Setteri si Getteri
    void setEtaj(int etaj);

    int getEtaj ()const;

    int getSuprafataCurte() const ;

    //Operator overload
    Apartament &operator=(const Apartament &loc);

    friend ostream &operator<<(ostream &out, const Apartament &loc);

    friend istream &operator>>(istream &in, Apartament &loc);

    //Diverse metode
    int tipLocuinta() const;

    int calculChirie(int X, int Y) const;

    //Destructorul
    ~Apartament();


};

#endif //PROIECT3_APARTAMENT_H