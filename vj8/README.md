Napišite program u C++ koji će korisniku staviti na raspolaganje izbornik sa sljedećim mogućnostima:

1. Dinamička alokacija polja trokuta
2. Unos podataka o trokutima
3. Ispis podataka o svim unesenim trokutima
4. Ispravak podataka o trokutima
9. Izlaz iz programa

•	Potrebno je definirati klasu ctrokut, koja definira sljedeće članove:
naziv – naziv trokuta (javni atribut, znakovni niz)
a,b,c – duljine stranica trokuta (javni atributi tipa float)
s – privatni atribut tipa float
vrijeme - privatni objekt iz klase cvrijeme (koristi se za mjerenje vremena unosa podataka)
povrsina() – javna metoda tipa float, koja računa površinu trokuta po Heronovoj formuli: 

	s = (a+b+c) / 2 		 

unos() – javna metoda za unos naziva trokuta i duljina stranica trokuta
ispis() – javna metoda za ispis naziva trokuta, duljina stranica trokuta i površine trokuta
•	Za mjerenje vremena  koristiti metode iz klase cvrijeme (biblioteka 'biblioteka_vrijeme.cc').
•	Nije dopušteno za vremena unosa koristiti pomoćno polje!


Za 1 bod:

Mogućnost 1. Ako je polje već alocirano, ispisati veličinu polja (broj alociranih elemenata), te nazive svih unesenih trokuta (ili poruku da nije još niti jedan unesen) i vratiti se u glavni izbornik. U suprotnom upitati korisnika za broj elemenata polja, te dinamički alocirati polje trokuta.
 
Za 2 boda:

Mogućnost 2.  Ispisati podatak o broju alociranih elemenata polja trokuta, te o broju upisanih trokuta. Ako polje nije alocirano, ispisati odgovarajuću poruku i vratiti se u glavni izbornik. Unijeti podatke o trokutu pomoću metode unos() (upita korisnika za naziv trokuta i dužine stranica a, b i c). Ako tri stranice ne čine trokut, ispisati odgovarajuću poruku i zatražiti ponovni unos. Izmjeriti vrijeme unosa podataka pomoću odgovarajućeg objekta vrijeme (iz klase cvrijeme).

Za 3 boda: 

Mogućnost 3. Koristiti metodu ispis() klase ctrokut za ispis podataka o trokutima. Uz svaki trokut treba ispisati i vrijeme potrebno za unos podataka (metoda proteklo() iz klase cvrijeme). Ispis treba biti podijeljen u dva dijela:
a.) trokuti (tri stranice čine trokut): ispisuju se naziv, dužine stranica a, b i c i površina trokuta, te vrijeme unosa podataka
b.) unosi u slučajevima kad tri stranice ne čine trokut: ispisuju se naziv i dužine stranica a, b i c, te vrijeme unosa podataka

Za 4 boda:

Mogućnost 4. Upitati korisnika za naziv trokuta. Ispisati podatke o odgovarajućem trokutu, zajedno s vremenom potrebnim za unos podataka. Upitati korisnika želi li promijeniti naziv trokuta ili dužine stranica (a, b i c). Ispisati podatke o trokutu nakon ispravka, zajedno s površinom ili porukom da tri stranice ne čine trokut.
