#include <iostream>

#include "Testing.h"
#include "Locuinta.h"
#include "Apartament.h"
#include "Casa.h"
#include "AgentieImobiliara.h"

using namespace std;

void Testing::testCitireAfisareCasaApartament() {
    Apartament a;
    Casa c;
    cin >> a;
    cin >> c;
    cout << a;
    cout << c;
}

void Testing::testOperatorEgalConstructorCopiere() {
    Apartament a("Popescu", 50, 20, 3);
    Apartament b(a);
    Apartament c;
    c = a;
    cout << b << c;

    Casa d("Ionescu", 100, 15, 100);
    Casa e(d);
    Casa f;
    f = d;
    cout << e << f;
}

void Testing::testCitireAfisareANObiecte() {
    Locuinta::citireLocuinte();
    Locuinta::aisareLocuinte();
}

void Testing::testCalculChirie() {
    Apartament a("Popescu", 50, 20, 3);
    Casa b("Ionescu", 100, 15, 100);
    cout << a.calculChirie(200, 0);
    cout << a.calculChirie(200, 1);
    cout << b.calculChirie(200, 0);
    cout << b.calculChirie(200, 1);
}


void Testing::testConstructorParametrizatAgentieImobiliara() {
    vector<Locuinta *> a;
    Apartament *b = new Apartament();
    cin >> *b;
    a.push_back(b);
    Casa *c = new Casa();
    cin >> *c;
    a.push_back(c);
    AgentieImobiliara d(a);
    cout << d;
    AgentieImobiliara e;
    cout << e;

}

void Testing::testCitireAfisareAgentieImobiliara() {
    AgentieImobiliara a;
    cin >> a;
    cout << a;
}

void Testing::testOperatorEgalConstructorCopiereAgentieImobiliara() {
    AgentieImobiliara a;
    cin >> a;
    AgentieImobiliara b(a);
    AgentieImobiliara c;
    c = a;
    cout << b << c;
}

void Testing::testUpcasting() {
    Locuinta *a;
    Apartament p("Popescu", 200, 20, 3);
    a = &p;
    cout << a->getNumeClient() << endl;
    cout << a->getSuprafataUtila() << endl;
    cout << a->calculChirie(12, 1) << endl;

}

void Testing::testDownCasting() {
    Locuinta *l = new Apartament("mihai");
    Apartament *a = dynamic_cast<Apartament *>(l);
    cout << a->calculChirie(211, 1) << endl;
    cout << a->getNumeClient();
}