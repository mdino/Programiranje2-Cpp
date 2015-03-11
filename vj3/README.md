Napišite program u C++ koji će korisniku staviti na raspolaganje izbornik sa sljedećim mogućnostima:

1. Dodavanje elementa na kraj dvostruko vezane liste
2. Dodavanje elementa na početak dvostruko vezane liste
3. Binarno stablo (kreiranje i ispis)
4. Binarno stablo (pretraživanje / dealokacija)
9. Izlaz iz programa

•	Pojedine mogućnosti realizirati pomoću odgovarajućih funkcija s argumentima.
•	Za mjerenje vremena  koristiti funkcije iz biblioteke 'Biblioteka_vrijeme.cc'.
•	Za unos znakovnih nizova koristiti funkciju unos iz biblioteke 'Biblioteka_vrijeme.cc'.
•	Svaki element vezane liste/binarnog stabla sadrži sljedeće podatke: šifra robe, naziv robe, cijena komada, količina, vrijeme unosa (vrijeme je u tisućinkama sekunde, cjelobrojni podatak) , sljedeci i prethodni (pokazivači na sljedeći, odnosno prethodni element u listi) odnosno lijevo i desno (pokazivači na podređene čvorove).
 
Za 1 bod:

Mogućnost 1. Argument funkcije je adresa glave vezane liste robe. Korisniku treba ispisati trenutni broj elemenata vezane liste robe (riješiti pozivom odgovarajuće funkcije Broj_elemenata()). Alocirati novi element na kraju vezane liste i zatražiti od korisnika da unese šifru robe, naziv robe, cijenu komada i količinu. Izmjeriti i ispisati vrijeme trajanja korisnikovog unosa podataka, te vrijednost robe (= cijena * količina). Zatražiti od korisnika da potvrdi unos podataka. Ako ne potvrdi, ispisati vrijeme unosa i broj elemenata liste i vratiti se u glavni izbornik. Na kraju, u slučaju potvrde unosa, ispisati sadržaj vezane liste robe od početka (za svaki element ispisuju se šifra robe, naziv robe, vrijednost i vrijeme unosa).

Za 2 boda: 

Mogućnost 2. Argumenti funkcije su adresa glave vezane liste robe i broj elemenata vezane liste robe (dobije se pozivom funkcije Broj_elemenata()). Alocirati novi element na početku vezane liste i zatražiti od korisnika da unese šifru robe, naziv robe, cijenu komada i količinu. Izmjeriti i ispisati vrijeme trajanja korisnikovog unosa podataka. Ukoliko je cijena komada <= 0 ili količina <= 0, zatražiti ponovni unos (samo neispravno unesenog podatka). Na kraju ispisati sadržaj vezane liste robe od kraja (za svaki element ispisuju se šifra robe, naziv robe, vrijednost i vrijeme unosa).

Za 3 boda: 

Mogućnost 3. Argumenti funkcije su adresa glave vezane liste robe i korijen binarnog stabla. Prepisati sve elemente vezane liste u odgovarajuće čvorove binarnog stabla, s tim da je ključ razvrstavanja šifra robe. Upitati korisnika želi li ispis sadržaja binarnog stabla u uzlaznom ili silaznom redoslijedu. Ispisati sadržaj binarnog stabla (za svaki čvor ispisuju se šifra robe, naziv robe, cijena komada, količina i vrijeme unosa) u odgovarajućem redoslijedu.
 
Za 4 boda:

Mogućnost 4. Upitati korisnika želi li pretraživati binarno stablo ili dealokaciju stabla. Za dealokaciju ispisati broj dealociranih čvorova stabla (korijen ostaje). Kod pretraživanja korisnik unosi šifru robe, nakon čega se ispisuju šifra robe, naziv robe, cijena komada, količina i vrijeme unosa odgovarajućeg čvora (ako je nađen) ili poruka da čvor nije pronađen.
