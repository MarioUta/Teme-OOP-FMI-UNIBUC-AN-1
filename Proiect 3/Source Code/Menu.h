//
// Created by Mario on 17/05/2023.
//

#ifndef TEMA_3_MENU_H
#define TEMA_3_MENU_H


#include "Vanzare.h"
class Menu {
private:
    static Vanzare<Masina> c;
    static void citireMasini();//Functia care citeste masinilie agentiei
    static void afisMasini();  //Functia care afiseaza toate masinilie
    static void vindeMasina();//Functie care vinde o masina din portofoliul
public:
    static void startMenu();     //Functia de start a meniului

};

#endif //TEMA_3_MENU_H
