

#ifndef PROIECT3_LOCUINTA_H
#define PROIECT3_LOCUINTA_H

#include <string>
#include <vector>
using namespace std;

class Locuinta {
private:
    static vector<Locuinta*> Locuinte;
protected:
    string numeClient;
    int suprafataUtila;
    float discount;

public:
    //Constructori
    Locuinta(string numeClient = "Anonim", int suprafataUtila = 0, float discount = 0);

    Locuinta(const Locuinta &loc);

    //Setteri si Getteri
    void setNumeClient(string nume);

    void setSuprafataUtila(int suprafata);

    void setDiscount(float discount);

    string getNumeClient() const;

    int getSuprafataUtila()const;

    float getDiscount()const;

    virtual int getEtaj() const=0;

    virtual int getSuprafataCurte()const =0;

    virtual int calculChirie(int X, int Y) const = 0;

    //Metode pentru citirea/afisara a n obiecte

    static void citireLocuinte();

    static void aisareLocuinte();

    //Diverse metode
    virtual int tipLocuinta()const=0;

    static void dezaloca();

    //Destructorul
    virtual ~Locuinta();


};


#endif //PROIECT3_LOCUINTA_H
