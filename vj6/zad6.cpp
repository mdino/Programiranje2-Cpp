#include <iostream>
#include <fstream>
#include <iomanip>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc"

using namespace std;

struct troba{//2
       int sifra, kolicina;
       float cijena, vrijeme;
       char naziv[10];
};
tindeks indeks;
troba roba;

fstream dat;
fstream ind;


void provjera()//1
{
     int izbor;
     dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary);
     
     if(!dat){
              cout << "Datoteka ne postoji i bit ce kreirana zajedno sa indeksnom datotekom!" << endl;
              dat.open("roba_Musliu_Dino.dat",ios::out|ios::binary);
              ind.open("roba_Musliu_Dino.ind",ios::out|ios::binary);  
     }
     else {
         cout << "Datoteka vec postoji na disku!" << endl;
         cout << "Zelite li raditi sa postojecom (0) datotekom ili kreirati novu (1)? ";
         cin >> izbor;
         
         if(izbor==0){
                     cout<<"Nastavljam rad sa postojecom datotekom. "<<endl;
                     return;
                     }
                     
         else if(izbor==1){
                     dat.close();
                     dat.clear();
                     remove("roba_Musliu_Dino.dat");
                     remove("roba_Musliu_Dino.ind");
                     dat.open("roba_Musliu_Dino.dat",ios::out|ios::binary);
                     ind.open("roba_Musliu_Dino.ind",ios::out|ios::binary);
                     cout<<"Nova datoteka je kreirana!"<<endl;                  
         }//else(2)
     }//else(1)
     
}//provjera

void unos()//3
{

     dat.open("roba_Musliu_Dino.dat",ios::in|ios::out|ios::binary|ios::ate);
     ind.open("roba_Musliu_Dino.ind",ios::in|ios::out|ios::binary|ios::ate);
     
     vrijeme_pocetak();
     do{
        cout << "Sifra: ";
        cin >> roba.sifra;
        }while(roba.sifra<100 || roba.sifra >999);
     cout << "Naziv: ";
     unos(roba.naziv);
     cout << "Cijena: ";
     cin >> roba.cijena;
     cout << "Kolicina: ";
     cin >> roba.kolicina;
     vrijeme_kraj();
     
     roba.vrijeme=vrijeme_proteklo()/1000;
     dat.write((char*) &roba,sizeof(troba));
     indeks.kljuc = roba.sifra;
     indeks.adresa = (int)dat.tellp() - sizeof(troba);
     ind.write((char*) &indeks, sizeof(tindeks));
     dat.close();
     dat.clear();
     ind.close();
     ind.clear();
     preslozi_indeks("roba_Musliu_Dino.ind",indeks);
     cout << "\nIspis sortirane indeksne datoteke!\n" << endl;
     ind.open("roba_Musliu_Dino.ind", ios::in | ios::binary);
     while(1){
              ind.read((char*)&indeks,sizeof(tindeks));
              if(ind.eof()) break;
              cout << "Sifra: " << indeks.kljuc << endl;
              cout << "Adresa: " << indeks.adresa << endl;
              cout << "-----------" << endl;
              }
     ind.close();
     ind.clear();
}

void pretraga()//4
{
     int sifra;
     troba roba;
     bool nadjen=false;
     int broj=0;
     
     dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary);
     ind.open("roba_Musliu_Dino.ind",ios::in|ios::binary);
     cout << "Unesite sifru datoteke: ";
     cin >> sifra;
     while (1){
               ind.read ((char *)&indeks, sizeof(tindeks));
               broj++;
               if (ind.eof())break;
               if(indeks.kljuc == sifra){
                                  dat.seekg(indeks.adresa);
                                  dat.read ((char *)&roba, sizeof(troba));
                                  nadjen=true;
                                 cout << "Ukupan broj procitanih zapisa: " << broj << endl;
                                 cout << "--------------------------------" << endl;
                                 cout << "Sifra: " << indeks.kljuc << endl;
                                 cout << "Adresa: " << indeks.adresa << endl;
                                 cout << "------------" << endl;
                                 cout << "Naziv: " << roba.naziv << endl;
                                 cout << "Cijena: " << roba.cijena << endl;
                                 cout << "Kolicina: " << roba.kolicina << endl;
                                 cout << "Vrijeme: " << setprecision(3) << roba.vrijeme << endl;
                                 break;
                                 }//if
        }//while                        
     if (!nadjen){ cout << "Zapis nije pronadjen!" << endl;
     cout <<"Ukupan broj procitanih zapisa: " << broj << endl;
     }//if
     
}//pretraga

void ispis(){//5
     troba roba;
     float vrijednost, suma;
     vrijednost=0;
     suma=0;
     float vrijeme;
     dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary);
     ind.open("roba_Musliu_Dino.ind",ios::in|ios::binary);
     while (1){
               ind.read ((char *)&indeks, sizeof(tindeks));
               if (ind.eof())break;
               dat.seekg(indeks.adresa);
               dat.read ((char *)&roba, sizeof(troba));
               cout << "Sifra: " << roba.sifra << endl;
               cout << "Naziv: " << roba.naziv << endl;
               cout << "Cijena: " << roba.cijena << endl;
               cout << "Kolicina: " << roba.kolicina << endl;
               cout << "Vrijeme: " << setprecision(3) << roba.vrijeme << endl;
               cout << "-------------" << endl;
               vrijednost =(roba.kolicina*roba.cijena);
               suma+=vrijednost;
               vrijeme+= roba.vrijeme;
               }
     cout << "Ukupna vrijednost: " << suma << endl;
     cout << "Ukupno vrijeme: " << setprecision(3) << vrijeme << endl;
}//ispis

void generator(int zapis){//6
     troba roba;
     int i,j;
     dat.open("roba_Musliu_Dino.dat",ios::in|ios::out|ios::binary|ios::ate);
     ind.open("roba_Musliu_Dino.ind",ios::in|ios::out|ios::binary|ios::ate);
     vrijeme_pocetak();
     srand(time(NULL));
     for(i=1;i<=zapis;i++){
                           roba.sifra=rand()%999+100;
                           for(j=0;j<10;j++){
                           roba.naziv[j]=char (rand()%26+97);
                                              }
                           roba.naziv[10]='\0';
                           roba.cijena=float(rand()%1000+10);
                           roba.kolicina=rand()%1000+0;
                           roba.vrijeme=0;
                           dat.write ((char *)&roba,sizeof(troba));
                           indeks.kljuc=roba.sifra;
                           indeks.adresa=(int)dat.tellp()-sizeof(troba);
                           ind.write ((char *)&indeks,sizeof(tindeks));
                           }
     dat.close();
     dat.clear();
     ind.close();
     ind.clear();
     preslozi_indeks("roba_Musliu_Dino.ind",indeks);
     vrijeme_kraj();
     cout << "Vrijeme generiranja je: " << vrijeme_proteklo()/1000 << endl;
}

int main(){
     int izbor,brojac;
     char naziv[30];
          
     do{
          system("cls");
          cout << "1. Rucni unos podataka o robi u indeksiranu datoteku" << endl;
          cout << "2. Pretrazivanje indeksirane datoteke prema sifri robe" << endl;
          cout << "3. Ispis sadrzaja maticne datoteke u redoslijedu sifre robe" << endl;
          cout << "4. Generiranje zapisa o robi (sa sortiranjem indeksa)" << endl;
          cout << "9. Izlaz iz programa" << endl;
          cout<<"Izbor?: ";
          cin >> izbor;
          
          switch(izbor){
                        case 1:
                             provjera();
                             dat.close();
                             dat.clear();
                             ind.close();
                             ind.clear();
                             unos();
                             break;
                             
                        case 2:
                             cout << "Upisite naziv maticne datoteke: ";
                             unos(naziv);
                             dat.open(naziv,ios::in|ios::binary);
                             if(!dat){
                                      cout << "Datoteka ne prostoji!" << endl;
                                         }
                             else{
                                     dat.seekg(0, ios::end);
                                     brojac=dat.tellg()/sizeof(troba);
                                     cout << "Broj zapisa je: " << brojac << endl;
                                     dat.close();
                                     dat.clear();
                                     pretraga();
                                     }
                             dat.close();
                             dat.clear();
                             ind.close();
                             ind.clear();
                                
                             break;
                        case 3:
                             cout << "Upisite naziv maticne datoteke: ";
                             unos(naziv);
                             dat.open(naziv,ios::in|ios::binary);
                             if(!dat){
                                      cout << "Datoteka ne postoji!" << endl;
                                      }
                             else{
                                     dat.close();
                                     dat.clear();
                                     ispis();
                                     }
                             dat.close();
                             dat.clear();
                             ind.close();
                             ind.clear();

                             break;
                        case 4:
                             int zapis;
                             dat.open("roba_skurdija_ivan.dat",ios::in|ios::binary);
                             ind.open("roba_skurdija_ivan.ind",ios::in|ios::binary);
                             if(!dat || !ind){
                                         cout << "Datoteke ne postoje i bit ce kreirane!" << endl;
                                         dat.open("roba_skurdija_ivan.dat",ios::out|ios::binary);
                                         ind.open("roba_skurdija_ivan.ind",ios::out|ios::binary);  
                                         }
                             else {
                                         cout << "Datoteke vec postoje na disku!" << endl;
                                         }
                             cout << "Koliko zapisa zelite generirati: ";
                             cin >> zapis;
                             dat.close();
                             dat.clear();
                             ind.close();
                             ind.clear();
                             generator(zapis);
                             break;
                        }
                        
          system("pause");
          }while(izbor!=9);
    return 0;
}//main
