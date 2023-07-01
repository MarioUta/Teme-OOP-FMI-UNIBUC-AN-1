//
// Created by Mario on 19/04/2023.
//

#ifndef PROIECT3_MENU_H
#define PROIECT3_MENU_H

#include "Apartament.h"
#include "Casa.h"
#include "AgentieImobiliara.h"
class Menu {
private:
    static AgentieImobiliara c;
public:
    static void startMenu();     //Functia de start a meniului
    static void citireLocuinte();//Functia care citeste locuintele agentiei
    static void afisLocuinte();  //Functia care afiseaza toate locuintele agentiei
    static void afisLocuinta();  //Functie care afiseaza detaliile unei singure locuinte
    static void addLocuinta();   //Functie care adauga o locuinta in portofoliul agentiei
    static void removeLocuinta();//Functie care elimina o locuinta din portofoliul agentiei

};


#endif //PROIECT3_MENU_H
