Napišite program u C++ koji će korisniku staviti na raspolaganje izbornik sa sljedećim mogućnostima:

0. Alokacija glave vezane liste
1. Unos novog elementa vezane liste studenata
2. Ispis sadržaja cijele vezane liste
3. Brisanje elementa liste
9. Izlaz iz programa

•	Pojedine mogućnosti (osim nulte) realizirati pomoću odgovarajućih funkcija s argumentima.
•	Za mjerenje vremena  koristiti funkcije iz biblioteke 'Biblioteka_vrijeme.cc'.
•	Za unos znakovnih nizova koristiti funkciju unos iz biblioteke 'Biblioteka_vrijeme.cc'.
•	Svaki element vezane liste sadrži sljedeće podatke: matični broj, prezime i ime, godina upisa, vrijeme unosa (vrijeme je u sekundama; realni podatak) i sljedeci (pokazivač na sljedeći element u listi).
 
Za 1 bod:

Mogućnost 0. Ako je glava vezane liste već alocirana, ispisati odgovarajuću poruku. U suprotnom alocirati glavu vezane liste i ispisati odgovarajuću poruku.
Mogućnost 1. Funkcija kao ulazni argument ima adresu glave vezane liste. Provjeriti da li je glava vezane liste alocirana. Ako nije, tada ispisati odgovarajuću poruku, kojom se korisnika upućuje na mogućnost 0 i vratiti se u glavni izbornik.
Zatražiti od korisnika unos sljedećih podataka koji ulaze u element vezane liste: matični broj, prezime i ime, godina upisa. Unos se ponavlja tako dugo dok je matični broj izvan raspona 30000-49999. Vrijeme korisnikovog unosa podataka treba izmjeriti, pretvoriti u sekunde (realni broj), ispisati i upisati u polje vrijeme unosa.

Za 2 boda: 

Mogućnost 2. Funkcija kao ulazni argumente ima adresu glave vezane liste a vraća ukupan broj elemenata u vezanoj listi (ne računajući glavu). Ako glava vezane liste nije alocirana, tada funkcija treba vratiti vrijednost -1. Broj elemenata vezane liste (ili poruka da nije alocirana glava liste) ispisuje se u funkciji main. 
Unutar funkcije ispisati sadržaj cijele vezane liste (za svaki element ispisuju se matični broj, prezime i ime, godina upisa i vrijeme unosa). Na kraju (unutar funkcije), treba ispisati aritmetičku sredinu svih vremena unosa (u sekundama, realni broj).

Za 3 boda:
 
Mogućnost 1 proširiti kontrolom kod unosa novih elemenata liste (da ista matični broj već nije upisana u vezanu listu - tada treba ispisati odgovarajuću poruku i zatražiti da se unos matični broj ponovi).

Za 4 boda:

Mogućnost 3. Funkcija kao ulazne argumente ima adresu glave vezane liste i matični broj. Provjeriti da je glava vezane liste alocirana i da lista nije prazna -> u tim slučajevima ispisati odgovarajuću poruku i vratiti se u glavni izbornik. Pretražiti vezanu listu prema matičnom broju. Ako zadani matični broj nije pronađen, ispisati sve postojeće matične brojeve, zajedno s naslovima i zatražiti ponovni unos matičnog broja. U suprotnom, ispisati matični broj  i prezime i ime te zatražiti od korisnika da potvrdi brisanje. U slučaju pozitivnog odgovora izbrisati odgovarajući element vezane liste. Vratiti se u glavni izbornik (u oba slučaja).
