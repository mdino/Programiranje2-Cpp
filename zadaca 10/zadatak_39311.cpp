//Zadatak 10
//Prezime i ime:Musliu Dino
//Matieni broj:39311
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
class LISTA3_s{
public:
  int kljuc;
  int cetvrta;
  char peta[40];
  int sedma;
  char treca[40];
  float prva;
  void unos(){
    cout << "kljuc: "; cin >> kljuc;
    cout << "cetvrta: "; cin >> cetvrta;
    cout << "peta: "; cin >> peta;
    cout << "sedma: "; cin >> sedma;
    cout << "treca: "; cin >> treca;
    cout << "prva: "; cin >> prva;
  };
  void ispis(){
    cout << "kljuc: " << kljuc << endl;
    cout << "cetvrta: " << cetvrta << endl;
    cout << "peta: " << peta << endl;
    cout << "sedma: " << sedma << endl;
    cout << "treca: " << treca << endl;
    cout << "prva: " << prva << endl;
  };
};
class LISTA3{
  LISTA3 *sljedeci;
public:
  LISTA3_s sadrzaj;
  LISTA3(){
    sljedeci=NULL;
  };
  void f39311(){
    LISTA3 *zadnji,*novi;
    zadnji=this;
    while (zadnji->sljedeci)
      zadnji=zadnji->sljedeci;
    novi = new LISTA3;
    zadnji->sljedeci=novi;
    novi->sadrzaj.unos();
  };
  void f40(){
    LISTA3 *tekuci=this->sljedeci;
    while (tekuci){
      cout << "-----------------" << endl;
      tekuci->sadrzaj.ispis();
      tekuci=tekuci->sljedeci;
    }
  };
};//LISTA3
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 40 % 2 + 3;
  dat << "kljuc\t";
  dat << "cetvrta\t";
  dat << "peta\t";
  dat << "sedma\t";
  dat << "treca\t";
  dat << "prva\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (40 + i + b) * 67 + 879;
    dat << broj++ % 100 << "\t";
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 10 << "." << (broj++ +43) % 10 << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
int main(){
  zadatak();
  LISTA3 *oLISTA3;
  oLISTA3=new LISTA3;
  char dalje;
  int b=0,i;
  do{
    oLISTA3->f39311();
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "-------------------------------------" << endl;
  oLISTA3->f40();
  //*
  cout << "++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "int = " << sizeof(int) << " b" << endl;
  cout << "Musliu Dino 39311 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoau ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeaa pitanja:
//1. Koliko memorijskog prostora zauzimaju objekti iz klase LISTA3_s, a koliko glava vezane liste iz primjera?
//2. Definirajte statieko polje od 40 elemenata iz klase LISTA3_s.
//3. Napišite programski kod koji bi, umetnut na poziciju oznaeenu s //* izazvao 40 pokretanja
//   konstruktora LISTA3().
//Spremite Word-ov dokument u datoteku 'zadatak_39311.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Modificirajte klasu LISTA3 tako da objekt iz klase LISTA3_s bude sadržan po referenci (umjesto po vrijednosti).
//Funkcionalnost primjera mora ostati ista.
//Ažurirani program spremite u datoteku 'ispravak_39311.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_39311.zip' koja ukljuauje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_39311.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_39311.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaae zadaae'
