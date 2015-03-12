Definirajte osnovnu klasu cstudij koja definira pokazivač na sljedeći element u vezanoj listi te virtualne metode za unos i ispis podataka.

Definirajte klase cstudent i cprijava koje nasljeđuju cstudij i implementiraju metode za unos i ispis podataka u vezanu listu (atributi: matični broj i prezime i ime, odnosno šifra prijave, matični broj, predmet i rok). 

Glava vezane liste je iz klase cstudij, a elementi su iz klasa cstudent i cprijava. Za utvrđivanje klase kojoj pripada pojedini objekt koristiti operator typeid.

Glavni izbornik programa:

1. Unos studenata/unos prijava/ispis studenata i prijava
2. Ispis studenata/ispis prijava (odvojeno)
3. Ispis liste prijava zadanog studenta (prema matičnom broju)
4. Ispis liste prijava zadanog studenta (prema prezimenu i imenu)
9. Izlaz iz programa

Za 1 bod:

Mogućnost 1.  Ispisati trenutni broj elemenata vezane liste. Upitati korisnika želi li upisati novog studenta, novu prijavu ili ispis cijele liste studenata i prijava.

Za 2 boda:

Mogućnost 2. Ispisati trenutni broj upisanih studenata i trenutni broj upisanih prijava. Upitati korisnika želi li ispis popisa studenata ili popisa prijava.

Za 3 boda:

Proširiti mogućnost 1 tako da se ne može unijeti prijava za studenta čiji matični broj nije već upisan (u objektu iz klase cstudent). Ako je student upisan, ispisati odgovarajuću poruku!

Mogućnost 3. Ispisati trenutni broj upisanih studenata i trenutni broj upisanih prijava. Ako ni jedan student nije upisan, ispisati odgovarajuću poruku i vratiti se u glavni izbornik. Zatražiti od korisnika matični broj studenta. Ako je student upisan, ispisati prezime i ime, u suprotnom ispisati odgovarajuću poruku i vratiti se u glavni izbornik. Ispisati sve prijave zadanog studenta (za svaku prijavu ispisuju se šifra prijave, matični broj, predmet i rok).

Za 4 boda:

Mogućnost 4. Ispisati trenutni broj upisanih studenata i trenutni broj upisanih prijava. Ako ni jedan student nije upisan, ispisati odgovarajuću poruku i vratiti se u glavni izbornik. Zatražiti od korisnika prezime i ime studenta. Ako je student upisan, ispisati matični broj, u suprotnom ispisati odgovarajuću poruku i vratiti se u glavni izbornik. Ispisati sve prijave zadanog studenta (za svaku prijavu ispisuju se šifra prijave, matični broj, predmet i rok).

