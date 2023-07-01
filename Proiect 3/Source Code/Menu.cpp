//
//

#include "Menu.h"
#include "Vanzare.h"
#include "Vanzare.cpp"
#include <iostream>
#include <cstdlib>

Vanzare<Masina> Menu::c;

void Menu::startMenu() {

    cout << "Bine ai venit in meniul interactiv ale agentiei FMI Car Retail! \n\n";
    cout << "Alege una dintre urmatoarele optiuni:\n\n";
    cout << "1.Introduce lista masinilor noastre\n";
    cout << "2.Afiseaza lista masinilor noastre\n";
    cout << "3.Vinde o masina a agentiei\n";
    cout << "4.Inchide meniul\n";
    int x;
    cin >> x;
    switch (x) {
        case 1:
            citireMasini();
            break;
        case 2:
            afisMasini();
            break;
        case 3:
            vindeMasina();
            break;
        case 4:
            cout << "Sesiunea s-a incheiat!\n";
            break;
        default:
            cout << "Nu ati introdus o optiune valida"
                 << '\n';
            exit(1);
            break;
    }
}

void Menu::citireMasini() {
    ::system("CLS");
    cin >> c;
    ::system("CLS");
    startMenu();
}

void Menu::afisMasini() {
    ::system("CLS");
    cout << c;
    cout << "Apasa orice pentru a te intoarce la meniul principal\n";
    cin.get();
    cin.get();
    ::system("CLS");
    startMenu();
}

void Menu::vindeMasina() {
    ::system("CLS");
    cout<<"Introduce numarul masinii pe care vrei sa o vinzi:\n";
    int n;
    cin>>n;
    c-=c[n];
    ::system("CLS");
    startMenu();
}

