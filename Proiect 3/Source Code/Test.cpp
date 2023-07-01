//
// Created by Mario on 17/05/2023.
//

#include "Test.h"
#include "masina.h"
#include "Mini.h"
#include "Mica.h"
#include "Monovolum.h"
#include "Compacta.h"
#include "Vanzare.h"
#include "Vanzare.cpp"
#include <iostream>


void Test::testOperatoriInputOutputToateClasele() { //Clasa Masina are constructorii protected

    Mini a;
    Mica b;
    Compacta c;
    Monovolum d;
    Vanzare<Masina> e;
    Vanzare<Monovolum> f;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    cin>>f;
    cout<<a<<b<<c<<d<<e<<f;
}

void Test::testOperatorEgalConstructoriToateClasele() {

    Mini a(3,"Alfa Romeo",4,10000);
    Mica b(1,"Mazda",4,5000);
    Compacta c(2,"Mitubishi",6,15000);
    Monovolum d(5,"Volkswagen",7,10,20000);

    Mini a1(a);
    Mica b1(b);
    Compacta c1(c);
    Monovolum d1(d);
    cout<<a1<<b1<<c1<<d1;

    a1=a;
    b1=b;
    c1=c;
    d1=d;
    cout<<a1<<b1<<c1<<d1;

    ////////////////////////////////

    Mini *p = new Mini(14124, "Alfa Romeo", 2,25);
    Monovolum *q = new Monovolum(533, "Lamborghini", 3, 4,2000);
    Mica *s = new Mica(9233, "Audi R8", 6);
    set<pair<Masina *, bool> > sir1;
    sir1.insert(make_pair(p, true));
    sir1.insert(make_pair(q, q->getMasinaNoua()));
    sir1.insert(make_pair(s, true));

    Monovolum *x = new Monovolum(14124, "Alfa Romeo", 2,25,4121);
    Monovolum *y = new Monovolum(533, "Lamborghini", 3, 0,1234);
    Monovolum *z = new Monovolum(9233, "Audi R8", 6,12,41412);
    set<pair<Monovolum *, bool> > sir2;
    sir2.insert(make_pair(x, x->getMasinaNoua()));
    sir2.insert(make_pair(y, y->getVarstaMasina()));
    sir2.insert(make_pair(z, z->getMasinaNoua()));


    Vanzare<Masina> e(sir1);
    Vanzare<Monovolum> f(sir2);

    Vanzare<Masina>e1(e);
    Vanzare<Monovolum>f1(f);

    cout<<e1<<f1;

    e1=e;
    f1=f;

    cout<<e1<<f1;

    delete p;
    delete q;
    delete s;
    delete x;
    delete y;
    delete z;

}

void Test::calculPretMonovolumeVarstaSiDiscount() {
    Monovolum d(5,"Volkswagen",7,10,20000);
    cout<<"Pretul noua: "<<d.getPret()<<endl;
    cout<<"Pretul actual: "<<d.getPretActual()<<endl;


    Monovolum e(5,"Volkswagen",7,0,20000);
    cout<<"Pretul noua: "<<e.getPret()<<endl;
    cout<<"Pretul actual: "<<e.getPretActual()<<endl;
}

void Test::testCitireAfisareANObiecte() {
    Masina::citesteNObiecte();
    Masina::afiseazaNObiecte();
}

void Test::testSpecializareClasaVanzare() {
    Vanzare<Monovolum> d;
    cin>>d;
    d.afiseazaMasinilieInStoc();
    d.afiseazaMasinileVandute();
    d-=d[0];
    Vanzare<Monovolum> e;
    e=d;
    cout<<e;
}