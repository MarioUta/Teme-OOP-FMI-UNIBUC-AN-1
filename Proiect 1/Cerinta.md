Subiectul 0. (se va implementa in timpul orelor de laborator, nu se poate alege ca tema)
Clasa Complex
Sa se creeze o clasa ce sa ilustreze un numar complex.
- membri privati pentru partea reala si partea imaginara (double).
- setteri si getteri pentru partea reala si imaginara.
- metoda publica de afisare (sub forma “a”, “i*b”, “-i*b”, “a+i*b”,”a-i*b”)
- metoda publica pentru determinarea unui numar complex
- suma a doua numere complexe, implementata prin supraincarcarea operatorului +
- produsul a doua numere complexe, implementat prin supraincarcarea operatorului *
- impartirea a doua numere complexe, implementata prin supraincarcarea operatorului /
- supraincarcare << si >>

  
Subiectul 1. Clasa ComplexVector
- optional: clasa ComplexVector poate fi prietena clasei Complex (Tema 0)
- Membri privati:
- vector: Complex* – vectorul propriu zis (alocat dinamic)
- size: int – dimensiunea vectorului
Functionalitati:
- supraincarcarea operatorilor << si >> sa foloseasca supraincarcarea acestora pentru clasa Complex
- metoda publica pentru determinarea vectorului modulelor, folosind metoda de determinare a
modulelor din clasa Complex. Metoda va intoarce un nou ComplexVector si nu va modifica vectorul ce
apeleaza metoda.
- metoda publica pentru sortarea crescatoare dupa module a vectorului. Metoda nu va intoarce nimic si
va sorta vectorul ce o apeleaza.
- metoda publica pentru calculul sumei tuturor elementelor vectorului, folosind operatorul + al clasei
Complex. Metoda va intoarce totalul si nu va modifica vectorul ce o apeleaza.
- supraincarcarea operatorului + : se intoarce suma a doi vectori
