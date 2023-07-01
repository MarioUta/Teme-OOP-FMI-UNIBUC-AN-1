Dintr-un parc auto se poate cumpăra o gama variată de automobile din următoarele clase: MINI (mașina de oraș de mic litraj, de obicei sub 4m lungime), MICA (mașini de oraș, cu spațiu interior mai mare decât MINI și lungime între 3.85 și 4.1), 
COMPACTA (mașini ușor de folosit atât de oraș cât și la drum lung, de dimensiune 4.2 – 4.5m; modelele vin sub forma de hatchback, combi sau sedan) și MONOVOLUME (automobile sub forma de van ce pot transporta 5-7 persoane). 
Monovolumele pot și achiziționate atât noi cât și second hand. La cele achizitionate sh se percepe un discount proporțional cu numărul de ani vechime și, în lunile de vară, beneficiază de zile promotionale cu reducere fixa de 10% din preț. 

Structura de date: set<pair<tip_automobil, bool nou>> (nou = false pentru cele sh) 


Cerința suplimentară: 

- Să se adauge toate campurile relevante pentru modelarea acestei probleme. 

- Să se adauge campurile și metodele necesare pentru implementarea corecta; 

- Să se  construiască clasa template Vanzare care sa conțină nr total de mașini în stoc (decrementat automat la vanzarea unei mașini), nr de mașini vândute (incrementat automat) și două structuri de obiecte, alocate dinamic, prin care să se gestioneze automobilele din stoc și cele vandute. Sa se supraincarce operatorul -= care sa actualizeze datele din clasa la vanzarea unei mașini. 

- Să se construiască o specializare pentru tipul MONOVOLUM care sa conțină și să afișeze gestioneze doar MONOVOLUMELE. 

 
