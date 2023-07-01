//
// Created by Mario on 13/05/2023.
//

#ifndef TEMA_3_MASINA_H
#define TEMA_3_MASINA_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Masina {
protected:
    int capacitateMotor;
    string numeBrand;
    float lungime;
    int pret;
    static vector<Masina*> obiecte; //Vector pentru memorarea a N obiecte

    //Constructorii sunt protected deoarece nu vreau sa declar obiecte doar de tipul masina

    explicit Masina(int capacitate = 0, const string& brand = "Anonim", float lungime = 0, int pret=0);//Constructorul cu parametrii default
    Masina(const Masina& c);//Constructorul de copiere

public:

    static void citesteNObiecte();//Metoda pentru citirea a N obiecte

    static void afiseazaNObiecte();//Metoda pentru afisarea a N obiecte

    static void dezaloca(); //Metoda pentru dezalocarea celor N obiecte

    //Setteri

    static const vector<Masina *> &getObiecte();

    virtual void setCapacitateMotor(int x);

    virtual void setNumeMasina(const string &x);

    virtual void setLungime(float x);

    virtual void setPret(int x);
    //Getteri

    virtual int getPret() const;

    virtual string getTipMasina() const;

    virtual int getCapacitateMotor() const;

    virtual string getNumeMasina() const;

    virtual float getLungime() const;

    friend istream &operator>>(istream &in, Masina &c) {
    c.citireMasina();
    cin.get();
    return in;
}


    virtual void afisareMasina(){

        cout<<capacitateMotor<<'\n';
        cout<<numeBrand<<'\n';
        cout<<pret<<'\n';
        cout<<lungime<<'\n';
    }

    virtual void citireMasina(){

        cin>>capacitateMotor;
        cin>>numeBrand;
        cin>>pret;
        cin>>lungime;
    }

    //Destrutorul;

    virtual ~Masina();
};


#endif //TEMA_3_MASINA_H
