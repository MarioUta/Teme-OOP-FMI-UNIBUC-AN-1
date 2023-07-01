//
// Created by Mario on 13/05/2023.
//

#ifndef TEMA_3_MONOVOLUM_H
#define TEMA_3_MONOVOLUM_H

#include "masina.h"

//Specializarea Monovolum


class Monovolum : public Masina {
private:
    string tipMasina; //Tipul masinii
    bool nou;       //Arata daca masina este noua
    unsigned int ani;//Arata varsta masinii
public:
    //Constructori

    Monovolum(int capacitate = 0, const std::string& brand = "Anonim", float lungime = 0.0, int ani=0,int pret=0);

    Monovolum(const Monovolum &c);



    //Getteri

    bool getMasinaNoua()const;

    int getVarstaMasina()const;

    int getPretActual() const ;

    virtual string getTipMasina();

    //Setter

    void setVarstaMasina(int x);

    //Overload pentru operatorii '=', '>>'  si '<<'

    Monovolum &operator=(const Monovolum &c);

    friend istream &operator>>(istream &in, Monovolum &c);

    friend ostream &operator<<(ostream &out, const Monovolum &c);

    //Destructor

    ~Monovolum();

};


#endif //TEMA_3_MONOVOLUM_H
