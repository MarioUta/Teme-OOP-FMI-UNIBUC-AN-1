//
// Created by Mario on 13/05/2023.
//

#ifndef TEMA_3_MINI_H
#define TEMA_3_MINI_H

#include "masina.h"
//Specializarea Mini

class Mini : public Masina {
private:
    string tipMasina;//Tipul masinii
public:
    //Constructori

    Mini(int capacitate = 0, const std::string &brand = "Anonim", float lungime = 0.0, int pret = 0);

    Mini(const Mini &c);
    //Overload pentru operatorii '=', '>>'  si '<<'

    Mini &operator=(const Mini &c);

    friend istream &operator>>(istream &in, Mini &c);

    friend ostream &operator<<(ostream &out, const Mini &c);
    //Getter

    virtual string getTipMasina();
    //Destructor

    ~Mini();
};


#endif //TEMA_3_MINI_H
