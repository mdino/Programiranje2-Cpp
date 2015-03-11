//Jednostavna vezana lista u C++
#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct tstudent{
  int mat_br;
  char prez_ime[35];
  int god_stu;
  tstudent *sljedeci;
};//struct 
void dodaj_element(tstudent *lista){ // dodaje element na kraj liste
  tstudent *novi,*zadnji;
  zadnji = lista;
  while (zadnji->sljedeci)
    zadnji = zadnji->sljedeci;       // pronala�enje zadnjeg elementa u listi
  novi = new tstudent;                // alokacija novog elementa liste
  zadnji -> sljedeci = novi;         // povezivanje zadnje elementa u listi s novim elementom
  novi -> sljedeci = NULL;           // novi je sada zadnji element u listi
  cout << "Maticni broj: "; cin >> novi -> mat_br;
  cout << "Prezime i ime: "; unos(novi->prez_ime);    // funkcija iz biblioteke
  cout << "Godina studija: "; cin >> novi -> god_stu;
};//dodaj_element
void ispisi_sve_elemente(tstudent *lista){ // ispis svih elemenata liste
  tstudent *tekuci = lista -> sljedeci;  // tekuci se usmjerava na po�etni element za ispis
  while (tekuci){
    cout << "adresa elementa = " << int(tekuci) << endl; 
    cout << "Maticni broj: " << tekuci -> mat_br << endl;
    cout << "Prezime i ime: " << tekuci -> prez_ime << endl;
    cout << "Godina studija: " << tekuci -> god_stu << endl;
    cout << "Adresa sljedeceg elementa: " << int (tekuci -> sljedeci) << endl;
    cout << "---------------------" << endl;
    tekuci = tekuci -> sljedeci;   // kretanje kroz listu
  }; // while
};//ispisi_sve_elemente
void pretrazi_listu(tstudent *lista,int mat_br){ //pretra�ivanje liste prema mati�nom broju
  tstudent *tekuci = lista -> sljedeci;  // tekuci se usmjerava na po�etni element za ispis
  while (tekuci){
    if (tekuci -> mat_br == mat_br){
      cout << "Maticni broj: " << tekuci -> mat_br << endl;
      cout << "Prezime i ime: " << tekuci -> prez_ime << endl;
      cout << "Godina studija: " << tekuci -> god_stu << endl;
      cout << "---------------------" << endl;
      return;  // izlaz iz petlje i potprograma
    };//if
    tekuci = tekuci -> sljedeci;   // kretanje kroz listu
  }; // while
  cout << "Element nije pronadjen!" << endl;
};//pretrazi_listu
void brisi_element(tstudent *lista,int mat_br){ //brisanje elementa liste prema mati�nom broju
  tstudent *brisi = lista -> sljedeci, *prethodni = lista;
  while (brisi){
    if (brisi -> mat_br == mat_br){
      prethodni -> sljedeci = brisi -> sljedeci;
      delete brisi;
      cout << "Element je izbrisan iz vezane liste!" << endl;
      return;  // izlaz iz petlje i potprograma
    }; // if
    prethodni = brisi;
    brisi = brisi->sljedeci;
  }; // while
  cout << "Element za brisanje nije pronadjen!" << endl;
};//brisi element
tstudent *dealokacija_liste(tstudent *lista){ //dealokacija liste
  tstudent *tekuci,*prethodni;
  prethodni=lista;
  tekuci=lista->sljedeci;
  while (tekuci){
    delete prethodni;
    prethodni=tekuci;
    tekuci=tekuci->sljedeci;
  }//while
  delete prethodni;
  return NULL;
};//dealokacija_liste
int main(){
  int izbor,mat_br;
  tstudent *lista = new tstudent; // alokacija glave liste
  lista -> sljedeci = NULL;      // kraj liste
  do{
    cout << "1. dodavanje novog elementa na kraj liste" << endl;
    cout << "2. ispis svih elemenata liste" << endl;
    cout << "3. pretrazivanje liste prema maticnom broju" << endl;
    cout << "4. brisanje elementa liste prema maticnom broju" << endl;
    cout << "5. dealokacija liste i kreiranje nove glave liste" << endl;
    cout << "9. dealokacija liste i izlaz" << endl;
    cin >> izbor;
    switch (izbor){
      case 1:dodaj_element(lista);break;
      case 2:ispisi_sve_elemente(lista);break;
      case 3:
        cout << "Maticni broj: "; cin >> mat_br;
        pretrazi_listu(lista,mat_br);break;
      case 4:
        cout << "Maticni broj: "; cin >> mat_br;
        brisi_element(lista,mat_br);break;
      case 5:
        lista=dealokacija_liste(lista);
        lista = new tstudent;         // alokacija nove glave liste
        lista -> sljedeci = NULL;     // kraj liste
        break;
      case 9:lista=dealokacija_liste(lista);break;
    };
    cout << endl;
  } while (izbor!=9);
  cout << (int)lista; // NULL
}//main
