
#ifndef PROIECT3_CASA_H
#define PROIECT3_CASA_H

#include "Locuinta.h"

class Casa : public Locuinta {
private:
    int suprafataCurte;
public:

    //Constructori

    Casa(string numeClient = "Anonim", int suprafataUtila = 0, float discount = 0, int suprafataCurte = 0);

    Casa(const Casa &loc);

    //Getteri si Setteri
    void setSuprafataCurte(int suprafta);

    int getSuprafataCurte()const;

    int getEtaj()const;

    //Supraincarcarea operatorilor
    Casa &operator=(const Casa &loc);

    friend  ostream& operator<<(ostream&out, const Casa& loc);

    friend istream &operator>>(istream &in, Casa &loc);

    //Diverse metode
    int tipLocuinta()const;

    int calculChirie(int X, int Y) const;

    //Destructorul

    ~Casa();

};


#endif //PROIECT3_CASA_H