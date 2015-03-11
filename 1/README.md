# Vjezba1


Napišite program u C++ koji će korisniku staviti na raspolaganje izbor sa sljedećim mogućnostima, vezanim uz računanje površine različitih geometrijskih likova:

1. Površina pravokutnika
2. Površina kruga
3. Površina trokuta (po Heronovoj formuli)
4. Ispis polja trokuta
9. Izlaz iz programa

•	Pojedine mogućnosti realizirati pomoću preopterećene funkcije povrsina (tipa float - vraća vrijednost površine). U funkciji main unose se vrijednosti argumenata potrebnih za računanje površine, a funkcija vraća rezultat koji se ispisuje u funkciji main. Treba izmjeriti i ispisati vrijeme potrebno za unos argumenata i računanje površine.
•	Za mjerenje vremena koristiti odgovarajuću biblioteku ('Biblioteka_vrijeme.cpp')
•	Potrebno je korisniku ispisati mogućnosti, te omogućiti unos izbora. Izbor mogućnosti treba implementirati pomoću selekcije tipa switch (svaki pojedini case odnosi se na pojedinu mogućnost). Korisnik može više puta birati mogućnost, tako dugo dok ne izabere izlaz iz programa tj. selekcija tipa switch treba se nalaziti unutar iteracije tipa do-while.
 
Za 1 bod:

Mogućnost 1. Računanje površine pravokutnika. Korisnik unosi argumente (širinu i visinu; realni brojevi) unutar funkcije main. Unos se prekida, uz ispisivanje odgovarajuće poruke o pogreški i povratak u glavni izbornik, u sljedećem slučaju:
- ako je širina <= 0 ili je visina <= 0
Nakon toga poziva se funkcija koja izračunava površinu pravokutnika, a rezultat se ispisuje unutar funkcije main. Izmjerite i ispišite vrijeme potrebno za unos argumenata i izračunavanje rezultata.

Za 2 boda:

Mogućnost 2. Računanje površine kruga. Korisnik unosi argument (radijus kruga; realni broj) unutar funkcije main. Unos se prekida, uz ispisivanje odgovarajuće poruke o pogrešci i povratak u glavni izbornik, u sljedećem slučaju:
- da je radijus <= 0
Nakon toga poziva se funkcija koja izračunava površinu kruga, a rezultat se ispisuje unutar funkcije main. Izmjerite i ispišite vrijeme potrebno za unos argumenta i izračunavanje rezultata.



Za 3 boda:

Mogućnost 3. Računanje površine trokuta prema Heronovoj formuli. Korisnik unosi argumente (dužine stranica a, b i c; realni brojevi) unutar funkcije main. Unos se prekida, uz ispisivanje odgovarajuće poruke o pogrešci i povratak u glavni izbornik, u sljedećim slučajevima:
- da je dužina neke od stranica <= 0
- da dužina najduže stranice bude veća ili jednaka zbroju dvije preostale stranice (=stranice ne čine trokut)
Nakon toga poziva se funkcija koja izračunava površinu trokuta, a rezultat se ispisuje unutar funkcije main. Izmjerite i ispišite vrijeme potrebno za unos argumenata i izračunavanje rezultata.

Za 4 boda:

Proširite prethodnu mogućnost tako da formirate statičko polje od 100 elemenata tipa strukture s dužinama stranica trokuta (koristiti deklaraciju struct). Kad korisnik unese ispravne dužine stranica trokuta, te se upisuju u odgovarajući element polja.
Mogućnost 4. Ispisuju se svi elementi polja trokuta (=dužine stranica a, b i c za svaki pojedini trokut) s tim da se za svaki trokut poziva funkcija za računanje površine, te se površina ispisuje. Nije dopušteno površinu trokuta zapisati kao dodatni element strukture!

