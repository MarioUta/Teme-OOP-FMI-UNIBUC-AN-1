//
// Created by Mario on 19/04/2023.
//

#include "Menu.h"
#include "AgentieImobiliara.h"
#include <iostream>
#include <cstdlib>

AgentieImobiliara Menu::c;

void Menu::startMenu() {

    cout << "Bine ai venit in meniul interactiv ale agentiei FMI Housing! \n\n";
    cout << "Alege una dintre urmatoarele optiuni:\n\n";
    cout << "1.Introduce lista locuintelor noastre\n";
    cout << "2.Afiseaza lista locuintelor noastre\n";
    cout << "3.Afiseaza detalii despre o locuinta anume\n";
    cout << "4.Adauga o locuinta in lista\n";
    cout << "5.Elimina o locuinta din lista\n";
    cout << "6.Inchide meniul\n";
    int x;
    cin >> x;
    switch (x) {
        case 1:
            citireLocuinte();
            break;
        case 2:
            afisLocuinte();
            break;
        case 3:
            afisLocuinta();
            break;
        case 4:
            addLocuinta();
            break;
        case 5:
            removeLocuinta();
            break;
        case 6:
            cout << "Sesiunea s-a incheiat!\n";
            break;
        default:
            cout << "Nu ati introdus o optiune valida"
                 << '\n';
    }
}

void Menu::citireLocuinte() {
    ::system("CLS");
    cin >> c;
    ::system("CLS");
    startMenu();
}

void Menu::afisLocuinte() {
    ::system("CLS");
    cout << c;
    cout << "Apasa orice pentru a te intoarce la meniul principal\n";
    cin.get();
    cin.get();
    ::system("CLS");
    startMenu();
}

void Menu::afisLocuinta() {
    ::system("CLS");

    cout << "Introduce indicele locuintei pe care vrei sa o afisezi\n";
    int x;
    cin >> x;
    if (x >= c.getNumarLocuinte() || x < 0) {
        cout << "Nu este o optiune valida!\n";
        startMenu();
    } else {
        if (c[x].tipLocuinta() == 1) {
            cout << "Tip Locuinta: Apartament\n";
            cout << "Nume client: " << c[x].getNumeClient() << endl;
            cout << "Suprafata utila: " << c[x].getSuprafataUtila() << endl;
            cout << "Etaj: " << c[x].getEtaj() << endl;
            cout << "Discount: " << c[x].getDiscount() << endl;
            cout << "Chirie fara dicount: " << c[x].calculChirie(1000, 0) << endl;
            cout << "Chirie cu dicount: " << c[x].calculChirie(1000, 1) << endl << endl;
        }
        if (c[x].tipLocuinta() == 2) {
            cout << "Tip Locuinta: Casa\n";
            cout << "Nume client: " << c[x].getNumeClient() << endl;
            cout << "Suprafata utila: " << c[x].getSuprafataUtila() << endl;
            cout << "Suprafata curte: " << c[x].getSuprafataCurte() << endl;
            cout << "Discount: " << c[x].getDiscount() << endl << endl;
            cout << "Chirie fara dicount: " << c[x].calculChirie(1000, 0) << endl;
            cout << "Chirie cu dicount: " << c[x].calculChirie(1000, 1) << endl << endl;
        }
        int x;
        cout
                << "Alege una dintre urmatoarele optiuni:\n\n1.Afiseaza detaliile altei locuinte\n2.Intoarce-te la meniul principal\n";
        cin >> x;
        if (x == 1)
            afisLocuinta();
        else if (x == 2) {
            ::system("CLS");
            startMenu();
        } else
            cout << "N-ai ales o optiune valida!\n";
    }
}

void Menu::addLocuinta() {
    ::system("CLS");
    c.adaugaLocuinta();
    ::system("CLS");

    startMenu();
}

void Menu::removeLocuinta() {
    ::system("CLS");
    c.eliminaLocuinta();
    ::system("CLS");
    startMenu();
}

