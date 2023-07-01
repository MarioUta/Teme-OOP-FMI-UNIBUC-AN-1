

#ifndef PROIECT3_AGENTIEIMOBILIARA_H
#define PROIECT3_AGENTIEIMOBILIARA_H

#include "Locuinta.h"
#include "Apartament.h"
#include "Casa.h"
#include <vector>
using namespace std;

class AgentieImobiliara {
private:
    vector<Locuinta*> Agentie;
    int numarLocuinte;

public:
    AgentieImobiliara();//Construcor neparametrizat
    explicit AgentieImobiliara(const vector<Locuinta*>& agency);
    AgentieImobiliara(const AgentieImobiliara& agency);//Constructor de copiere

    int getNumarLocuinte() const;///Functie care intoarce numarul de locuinte al agentiei  imobiliare

    AgentieImobiliara& operator=(const AgentieImobiliara&agency);//Supraincarcarea operatorului =

    Locuinta& operator[](int index);//Supraincarea []

    friend istream& operator>>(istream &in,AgentieImobiliara& agency); //Supraincarcarea >>
    friend ostream& operator<<(ostream &in,const AgentieImobiliara& agency); //Supraincarcarea <<

    void adaugaLocuinta();


    void eliminaLocuinta();//Functie care sterge elimina o locuinta a agentiei imobiliare

    ~AgentieImobiliara();   //Destructorul
};


#endif //PROIECT3_AGENTIEIMOBILIARA_H
