Napišite program u C++ koji će korisniku staviti na raspolaganje izbornik sa sljedećim mogućnostima:

1. Unos podataka o robi u datoteku
2. Ispis sadržaja datoteke roba
3. Sortiranje datoteke uz pomoć vezane liste
9. Izlaz iz programa

•	Pojedine mogućnosti (osim mogućnosti 1) realizirati pomoću odgovarajućih funkcija.
•	Za mjerenje vremena  koristiti funkcije iz biblioteke 'Biblioteka_vrijeme.cc'.
•	Za unos znakovnih nizova (naziv robe) koristiti funkciju unos iz biblioteke 'Biblioteka_vrijeme.cc'.
•	Svaki zapis datoteke roba (fiksna veličina zapisa) sadrži šifru robe, naziv robe, cijenu, količinu i vrijeme unosa (u sekundama; realni podatak).
•	Oznaku #maticni_broj# zamijenite svojim brojem indeksa, 5 znamenki, a oznaku #prez_ime# svojim prezimenom i imenom (samo slova engleske abecede, crtica između prezimena i imena, npr. Anic_Ana). Nije dopušteno u tu svrhu koristiti varijable ili imenovane konstante (npr. definirane pomoću const ili #define ) !

Za 1 bod:
Mogućnost 0. Treba provjeriti da li datoteka roba_#prez_ime#.dat postoji na disku i po potrebi je kreirati. Ako postoji, upitati korisnika želi li izbrisati postojeću datoteku i kreirati novu.

Mogućnost 1. Zatražiti unos šifre robe, naziva robe, cijene i količine. Ako je šifra robe izvan raspona 100-999 ili naziv robe duži od 20 znakova ili umnožak cijene i količine manji od nule, ispisati poruku o pogreški i zatražiti da se unos ponovi. Izmjerite vrijeme unosa podataka (upisuje se u odgovarajući atribut zapisa) i upišite zapis u datoteku. Ispišite sadržaj cijele datoteke (sve atribute iz svih zapisa).

Za 2 boda: 

Mogućnost 2. Upitati korisnika za naziv datoteke. Ako datoteka ne postoji na disku, ispisati odgovarajuću poruku i vratiti se u glavni izbornik. U suprotnom ispisati broj zapisa u datoteci. Ispisati sadržaj cijele datoteke (sve atribute iz svih zapisa), s tim da za svaki zapis treba još izračunati i ispisati vrijednost robe (=umnožak cijene i količine). Na kraju ispisa treba ispisati ukupnu vrijednost robe (=zbroj svih umnožaka cijene i količine).

Za 3 boda: 

Proširiti mogućnost 1 tako da se provjeri postojanje unesene šifre robe u datoteci roba_#prez_ime#.dat.Ako je odgovor potvrdan, tada ispisati broj pojava zadane šifre robe i zatražiti ponovni unos (samo unos šifre robe se ponavlja, ne unos cijelog zapisa).

Za 4 boda: 

Mogućnost 3. Prepisati sadržaj datoteke roba_#prez_ime#.dat u odgovarajuću vezanu listu (struktura elementa liste je u odnosu na zapis datoteke proširena pokazivačem na sljedeći element u listi). Sortirati listu uzlazno prema šifri robe. Sadržaj liste zapisati u TEKSTUALNU datoteku roba_sort_#prez_ime#.txt. Dealocirati listu. 
