
#include <iostream>
#include "AgentieImobiliara.h"


using namespace std;

AgentieImobiliara::AgentieImobiliara() : numarLocuinte(0) {     //Constructorul neparametrizat intializeaza numarul de locuinte cu 0;
}

AgentieImobiliara::AgentieImobiliara(const vector<Locuinta*>& agency):numarLocuinte(agency.size()){

    for (int i = 0; i < agency.size(); i++) {

        if (agency[i]->tipLocuinta() == 1) {                //Verifica daca obiectul este de tip Casa sau Apartament

            Apartament *a = new Apartament();
            a->setNumeClient(agency[i]->getNumeClient());
            a->setSuprafataUtila(agency[i]->getSuprafataUtila());
            a->setEtaj(agency[i]->getEtaj());
            a->setDiscount(agency[i]->getDiscount());
            this->Agentie.push_back(a);
        } else {                                                                    //Creeaza un pointer a, de tip apartament/casa, in care stocheaza datele din locuinta la indicele 'i', dupa introduce pointer-ul a in vector
            Casa *a = new Casa();
            a->setNumeClient(agency[i]->getNumeClient());
            a->setSuprafataUtila(agency[i]->getSuprafataUtila());
            a->setSuprafataCurte(agency[i]->getSuprafataCurte());
            a->setDiscount(agency[i]->getDiscount());
            this->Agentie.push_back(a);
        }
    }

}


AgentieImobiliara::AgentieImobiliara(const AgentieImobiliara &agency) : numarLocuinte(agency.numarLocuinte) {   //Constructor de copiere
    for (int i = 0; i < agency.numarLocuinte; i++) {

        if (agency.Agentie[i]->tipLocuinta() == 1) {                //Verifica daca obiectul este de tip Casa sau Apartament

            Apartament *a = new Apartament();
            a->setNumeClient(agency.Agentie[i]->getNumeClient());
            a->setSuprafataUtila(agency.Agentie[i]->getSuprafataUtila());
            a->setEtaj(agency.Agentie[i]->getEtaj());
            a->setDiscount(agency.Agentie[i]->getDiscount());
            this->Agentie.push_back(a);
        } else {                                                                    //Creeaza un pointer a, de tip apartament/casa, in care stocheaza datele din locuinta la indicele 'i', dupa introduce pointer-ul a in vector
            Casa *a = new Casa();
            a->setNumeClient(agency.Agentie[i]->getNumeClient());
            a->setSuprafataUtila(agency.Agentie[i]->getSuprafataUtila());
            a->setSuprafataCurte(agency.Agentie[i]->getSuprafataCurte());
            a->setDiscount(agency.Agentie[i]->getDiscount());
            this->Agentie.push_back(a);
        }
    }
}

int AgentieImobiliara::getNumarLocuinte() const { return numarLocuinte; }           //Getter pentru nuamrul de locuinte

AgentieImobiliara &AgentieImobiliara::operator=(const AgentieImobiliara &agency) {  //Supraincarcarea operatorului =

    if (numarLocuinte != 0) {                                                       //Verifica daca Agentia imobiliara era initial goala, sau daca avea deja locuinte salvate
        for (int i = 0; i < numarLocuinte; i++)
            delete this->Agentie[i];
        this->Agentie.clear();
    }                                                                               //Dezaloca variblele alocte dinamic din vectorul caruia ii se atribuie valoarea

    this->numarLocuinte = agency.numarLocuinte;                                     //Schimba valoarea numarului de locuinte

    for (int i = 0; i < agency.numarLocuinte; i++) {
        if (agency.Agentie[i]->tipLocuinta() == 1) {                                //Verifica daca obiectul este de tip Casa sau Apartament
            Apartament *a = new Apartament();
            a->setNumeClient(agency.Agentie[i]->getNumeClient());
            a->setSuprafataUtila(agency.Agentie[i]->getSuprafataUtila());
            a->setEtaj(agency.Agentie[i]->getEtaj());
            a->setDiscount(agency.Agentie[i]->getDiscount());
            this->Agentie.push_back(a);
        } else {                                                                    //Creeaza un pointer a, de tip apartament/casa, in care stocheaza datele din locuinta la indicele 'i', dupa introduce pointer-ul a in vector
            Casa *a = new Casa();
            a->setNumeClient(agency.Agentie[i]->getNumeClient());
            a->setSuprafataUtila(agency.Agentie[i]->getSuprafataUtila());
            a->setSuprafataCurte(agency.Agentie[i]->getSuprafataCurte());
            a->setDiscount(agency.Agentie[i]->getDiscount());
            this->Agentie.push_back(a);
        }
    }
    return *this;
}


istream &operator>>(istream &in, AgentieImobiliara &agency) {           //Supraincarcarea >>
    cout << "Cate locuinte vrei sa citesti?\n";
    int n;                                                              //Numarul de locuinte pe care urmeaza sa-l citim
    cin >> n;

    if (agency.numarLocuinte != 0) {                                    //Verifica daca Agentia imobiliara era initial goala, sau daca avea deja locuinte salvate
        for (int i = 0; i < agency.numarLocuinte; i++)
            delete agency.Agentie[i];
        agency.Agentie.clear();
    }

    agency.numarLocuinte = n;                                           //Numarul de locuinte devine n
    for (int i = 0; i < n; i++) {
        cout << "Apasa 1 daca locuinta este apartament\nApasa 2 daca locuinta este Casa\n";
        int choice;
        cin >> choice;
        if (choice == 1) {                                              //Alegem tipul de locuinta pe care vrem sa-l introducem
            Apartament *a = new Apartament();
            cin >> *a;
            agency.Agentie.push_back(a);
        }                                                       //Creeaza un pointer a, de tip apartament/casa, citeste valoarea care se regaseste la adresa de memorie indicata de a, dupa introduce pointer-ul a in vector
        if (choice == 2) {
            Casa *b = new Casa();
            cin >> *b;
            agency.Agentie.push_back(b);
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const AgentieImobiliara &agency) {                    //Supraincarcarea <<
    for (int i = 0; i < agency.numarLocuinte; i++) {
        if (agency.Agentie[i]->tipLocuinta() == 1) {                                    //Verifica daca obiectul este de tip Casa sau Apartament
            cout << "Tip Locuinta: Apartament\n";
            cout << "Nume client: " << agency.Agentie[i]->getNumeClient() << endl;
            cout << "Suprafata utila: " << agency.Agentie[i]->getSuprafataUtila() << endl;
            cout << "Etaj: " << agency.Agentie[i]->getEtaj() << endl;
            cout << "Discount: " << agency.Agentie[i]->getDiscount() << endl << endl;
        }                                                                              //Afiseaza obiectul in functie daca este Casa sau Apartament
        if (agency.Agentie[i]->tipLocuinta() == 2) {
            cout << "Tip Locuinta: Casa\n";
            cout << "Nume client: " << agency.Agentie[i]->getNumeClient() << endl;
            cout << "Suprafata utila: " << agency.Agentie[i]->getSuprafataUtila() << endl;
            cout << "Suprafata curte: " << agency.Agentie[i]->getSuprafataCurte() << endl;
            cout << "Discount: " << agency.Agentie[i]->getDiscount() << endl << endl;
        }
    }
    return out;
}

Locuinta &AgentieImobiliara::operator[](int index) {                                //Supraincarea []
    return *this->Agentie[index];
}

void AgentieImobiliara::adaugaLocuinta() {                                          //Metoda care adauga o locuinta agentiei imobiliare
    cout << "Apasa 1 daca locuinta este apartament\nApasa 2 daca locuinta este Casa\n";
    int choice;
    cin >> choice;
    if (choice == 1) {                                                              //Alegem tipul de locuinta pe care vrem sa-l introducem
        Apartament *a = new Apartament();
        cin >> *a;
        Agentie.push_back(a);
    }                                                                              //Creeaza un pointer a, de tip apartament/casa, citeste valoarea care se regaseste la adresa de memorie indicata de a, dupa introduce pointer-ul a in vector
    if (choice == 2) {
        Casa *b = new Casa();
        cin >> *b;
        Agentie.push_back(b);
    }
    numarLocuinte = Agentie.size();                                                //Modifica numarul de locuinte astfel incat sa ia in considerare adaugarea unei noi locuinte
}

void AgentieImobiliara::eliminaLocuinta() {                                        //Metoda care elimina o locuinta din agentie
    cout << "Introduce indicele locuintei pe care vrei sa o elimni\n";
    int x;
    cin >> x;
    if (x >= numarLocuinte || x < 0) {                                          //Verifica daca exista locuinta pe care vrem sa o eliminam
        cout<<"Nu este o locuinta valida";
    } else {
        Agentie.erase(Agentie.begin() + x);
        numarLocuinte--;                                                        //Modifica numarul de locuinte astfel incat sa ia in considerare eliminarea unei noi locuinte
    }
}

AgentieImobiliara::~AgentieImobiliara() {                                       //Destructorul
    for (int i = 0; i < numarLocuinte; i++) {
        delete Agentie[i];                                                      //Elimina pe rand valorile retinute de fiecare pointer de tip Locuinta din vectorul Agentie
    }
    Agentie.clear();                                                            //Elimina continutul vectorului Agentie
}