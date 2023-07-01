//
// Created by Mario on 13/05/2023.
//

#ifndef TEMA_3_COMPACTA_H
#define TEMA_3_COMPACTA_H

#include <string>
#include "masina.h"

using namespace std;

//Specializarea Compacta

class Compacta : public Masina {
private:
    string tipMasina;//Tipul masinii
public:
    //Constructori
    Compacta(int capacitate = 0, const std::string &brand = "Anonim", float lungime = 0.0, int pret = 0);

    Compacta(const Compacta &c);

    //Overload pentru operatorii '=', '>>'  si '<<'

    Compacta &operator=(const Compacta &c);

    friend istream &operator>>(istream &in, Compacta &c);

    friend ostream &operator<<(ostream &out, const Compacta &c);

    //Getter

    virtual string getTipMasina();

    //Destructor

    ~Compacta();
};


#endif //TEMA_3_COMPACTA_H
