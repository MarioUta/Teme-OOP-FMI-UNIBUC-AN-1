//
// Created by Mario on 13/05/2023.
//

#ifndef TEMA_3_MICA_H
#define TEMA_3_MICA_H

#include "masina.h"
//Specializarea Mica

class Mica : public Masina {
private:
    string tipMasina;//Tipul masinii
public:
    //Constructori
    explicit Mica(int capacitate = 0, const std::string& brand = "Anonim", float lungime = 0.0,int pret=0);

    Mica(const Mica &c);

    //Overload pentru operatorii '=', '>>'  si '<<'

    Mica &operator=(const Mica &c);

    friend istream &operator>>(istream &in, Mica &c);

    friend ostream &operator<<(ostream &out, const Mica &c);


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
        this->tipMasina="Mini";
    }
    //Getter

    virtual string getTipMasina();

    ~Mica();
};


#endif //TEMA_3_MICA_H
