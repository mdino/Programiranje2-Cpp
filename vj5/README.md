-----------------------------------------------------------------------------------------------------------------
Napišite program u C++ koji će korisniku staviti na raspolaganje izbornik sa sljedećim mogućnostima:

1. Kreiranje datoteke praznih zapisa
2. Unos podataka o robi u relativnu datoteku (bez obzira na duplikate)
3. Pretraživanje relativne datoteke
4. Unos podataka o robi u relativnu datoteku (vodi računa o duplikatima)
9. Izlaz iz programa

•	Pojedine mogućnosti (osim mogućnosti 1) realizirati pomoću odgovarajućih funkcija.
•	Za mjerenje vremena  koristiti funkcije iz biblioteke 'Biblioteka_tel_imenik.cc'.
•	Zapis datoteke roba sadrži broj robe, naziv robe, količinu, cijenu i vrijeme unosa (u sekundama).
•	Oznaku #prez_ime# zamijenite svojim prezimenom i imenom (samo slova engleske abecede, crtica između prezimena i imena, npr. Anic_Ana). Nije dopušteno u tu svrhu koristiti varijable ili imenovane konstante (npr. definirane pomoću const ili #define ) !

Za 1 bod:

Mogućnost 1. Treba provjeriti da li datoteka roba_#prez_ime#.dat postoji na disku i po potrebi je kreirati, upitati korisnika za broj zapisa, kreirati datoteku praznih zapisa i izračunati i ispisati veličinu datoteke (u broju zapisa) i prvi manji prost broj od veličine datoteke.

Za 2 boda:

Mogućnost 2. Treba provjeriti da li datoteka roba_#prez_ime#.dat postoji na disku. Ako ne postoji,  ispisati odgovarajuću poruku i pozvati mogućnost 1 (radi kreiranja datoteke). Nakon toga zatražiti unos broja robe, naziva robe, cijene i količine. Ako je količina<0 ili cijena<=0 zatražiti ponovni unos (samo neispravno unesenog podatka), tako dugo dok unos ne bude ispravan. Izmjerite vrijeme unosa podataka (upisuje se u odgovarajući atribut zapisa) i upišite zapis u datoteku (redni broj izračunava se metodom prostog broja). Ispišite redni broj zapisa u datoteci. Ispišite sadržaj cijele datoteke (sve atribute iz svih nepraznih zapisa).
Napomena: mogućnost 2 ne vodi računa o duplikatima = upisuje preko postojećeg nepraznog zapisa.

Za 3 boda: 

Mogućnost 3. Treba provjeriti da li datoteka roba_#prez_ime#.dat postoji na disku. Ako ne postoji, ispisati odgovarajuću poruku i vratiti se u glavni izbornik. U suprotnom ispisati podatak o veličini datoteke (u bajtima) uz pomoć funkcije stanje_dat_objekta. Nakon toga zatražiti unos broja robe, koja mora biti u rasponu 100-999, u suprotnom vratiti se u glavni izbornik. Izračunati redni broj zapisa metodom prostog broja i ispisati ga. Pročitati odgovarajući zapis te ispisati odgovarajuću poruku i vratiti se u glavni izbornik:
- ako je nađen zapis s traženim brojem robe, ispisati naziv robe, količinu, cijenu i vrijeme unosa
- ako je nađen prazan zapis, ispisati da zapis nije pronađen, 
- ako je nađen duplikat, ispisati odgovarajuću poruku.

Za 4 boda: 

Mogućnost 4. Treba provjeriti da li datoteka roba_#prez_ime#.dat postoji na disku. Ako ne postoji, ispisati odgovarajuću poruku i vratiti se u glavni izbornik. Nakon toga zatražiti unos broja robe, naziva robe, cijene i količine. Izmjerite vrijeme unosa podataka (upisuje se u odgovarajući atribut zapisa) i izračunajte redni broj zapisa metodom prostog broja. Ako je zapis duplikat, ispisati odgovarajuću poruku, zajedno s rednim brojem zapisa. Upišite zapis u datoteku, ne preko nepraznog zapisa (treba pronaći najbliži prazan zapis). Ispišite sadržaj cijele datoteke (sve atribute iz svih nepraznih zapisa).

