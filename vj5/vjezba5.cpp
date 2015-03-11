#include <iostream>
#include <fstream>
#include "biblioteka_tel_imenik.cc"
#include <cmath>
using namespace std;
struct troba{
       int sifra,vrijeme,vrijednost;
       char naziv[20];       
       };//struct
int prvi_manji_prost(int x){
  int i,j,prost;
  for (i=x-1;i>1;i--){ 
    		prost = 1; 
    		for (j=2;j<=sqrt(i);j++){
  	      	      if (i%j==0){
                              prost=0;
                              break;
                              }//if
    		} //for j
    if (prost) return i;
  }//for i
  return 0;
};//funkcija
bool provjera(){
     bool provjera=false;;
     ifstream dat("roba_Vrevic_Armin.dat");
     if(dat.is_open())return 1;
     if(!provjera)return 0;
     dat.close();
     dat.clear();
     }//funkcija
void prvi(){
     troba roba;
     ofstream dat("roba_Vrevic_Armin.dat");
     cout<<"Koliki je broj zapisa: ";
     roba.sifra=0;
     roba.vrijeme=0;
     roba.vrijednost=0;
     roba.naziv[0]='\0';
     int broj;
     cin>>broj;
     for(int i=0;i<broj;i++)dat.write((char*)&roba,sizeof(troba));
     dat.close();
     dat.clear();
     cout<<"Velicina datoteke u broju zapisa je: "<<broj<<endl;
     cout<<"Prvi manji prosti broj od velicine datoteke je: "<<prvi_manji_prost(broj)<<endl; 
     }//funkcija
bool drugi(){
     if(!provjera()){
                   cout<<"Datoteka ne postoji na disku!\n";
                   return 0;
                   }
     int rbz=0;
     troba roba;
     fstream dat("roba_Vrevic_Armin.dat",ios::in|ios::out);
     vrijeme_pocetak();
     do{
        cout<<"Sifra= ";
        cin>>roba.sifra;
        if(roba.sifra<100||roba.sifra>999)cout<<"Krivo ste unijeli sifru, unesite ponovno!\n";
        }//do
     while(roba.sifra<100||roba.sifra>999);
     cout<<"Naziv= ";
     unos(roba.naziv);
     cout<<"Vrijednost= ";
     cin>>roba.vrijednost;
     vrijeme_kraj();
     roba.vrijeme=(int)vrijeme_proteklo()/10;
     dat.seekg(0,ios::end);
     rbz=dat.tellg()/sizeof(troba);
     cout<<rbz<<endl;
     int prost=prvi_manji_prost(rbz);
     rbz=roba.sifra%prost;
     cout<<"Redni broj zapisa u datoteci je: "<<rbz<<endl;
     dat.seekp(rbz*sizeof(troba));
     dat.write((char*)&roba,sizeof(troba));
     dat.close();
     dat.clear();
     ifstream dat2("roba_Vrevic_Armin.dat");
     while(1){
        dat2.read((char*)&roba,sizeof(troba));
        if(dat2.eof())break;
        if(roba.sifra>0){
                 cout<<"\nELEMENT\n--------\n";        
                 cout<<"Sifra= "<<roba.sifra<<endl;
                 cout<<"Naziv= "<<roba.naziv<<endl;
                 cout<<"Vrijednost= "<<roba.vrijednost<<endl;
                 cout<<"Vrijeme= "<<roba.vrijeme<<endl;
                 }//if
                 }//while
     }//funkcija
bool treci(){
     if(!provjera()){
                     cout<<"Datoteka ne postoji na disku\n";
                     return 0;
                     }//if
     fstream dat("roba_Vrevic_Armin.dat",ios::in|ios::out);
     stanje_dat_objekta(dat);
     troba roba;
     int sifra;
     cout<<"Unesite sifru robe: ";
     cin>>sifra;
     if(sifra<100|sifra>999)return 0;
     int rbz;
     dat.seekg(0,ios::end);
     rbz=dat.tellg()/sizeof(troba);
     int prost=prvi_manji_prost(rbz);
     rbz=sifra%prost;
     cout<<"Redni broj zapisa: "<<rbz<<endl;
     dat.seekp(rbz*sizeof(troba));
     dat.read((char*)&roba,sizeof(troba));
     if(sifra==roba.sifra){
                           cout<<"Naziv= "<<roba.naziv<<endl;
                           cout<<"Vrijednost= "<<roba.vrijednost<<endl;
                           cout<<"Vrijeme= "<<roba.vrijeme<<endl<<endl;
                           return 0;
                           }//if
     if(roba.sifra==0){
                       cout<<"PRAZAN ZAPIS!!\n\n";
                       return 0;
                       }//if
     if(roba.sifra!=sifra){
                       cout<<"DUPLIKAT!!!\n\n";
                       return 0;
                       }//if
     }//funkcija
bool cetvrti(){
      if(!provjera()){
                     cout<<"Datoteka ne postoji na disku\n";
                     return 0;
                     }//if
      troba roba;
      troba roba2;
      troba roba3;
      roba3.sifra=0;
      fstream dat("roba_Vrevic_Armin.dat",ios::in|ios::out);
      vrijeme_pocetak();
      cout<<"Sifra= ";
      cin>>roba.sifra;
      cout<<"Naziv= ";
      cin>>roba.naziv;
      cout<<"Vrijednost= ";
      cin>>roba.vrijednost;
      vrijeme_kraj();
      roba.vrijeme=(int)vrijeme_proteklo()/10;
      int rbz;
      dat.seekg(0,ios::end);
      rbz=dat.tellg()/sizeof(troba);
      int prost=prvi_manji_prost(rbz);
      rbz=roba.sifra%prost;
      dat.seekp(rbz*sizeof(troba));
      dat.read((char*)&roba2,sizeof(troba));
      if(roba2.sifra>0)cout<<"DUPLIKAT! \n Redni broj zapisa duplikata je: "<<rbz<<endl;
      dat.seekp(0);
      do dat.read((char*)&roba2,sizeof(troba));
      while(roba2.sifra>0);
      rbz=(dat.tellg()/sizeof(troba))-1;
      cout<<"Redni broj novog zapisa korigiranog je: "<<rbz<<endl;
      dat.seekp(rbz*sizeof(troba));
      dat.write((char*)&roba,sizeof(troba));
      dat.seekp(0);
      while(1){
        dat.read((char*)&roba,sizeof(troba));
        if(dat.eof())break;
        if(roba.sifra>0){
                 cout<<"\nELEMENT\n--------\n";        
                 cout<<"Sifra= "<<roba.sifra<<endl;
                 cout<<"Naziv= "<<roba.naziv<<endl;
                 cout<<"Vrijednost= "<<roba.vrijednost<<endl;
                 cout<<"Vrijeme= "<<roba.vrijeme<<endl;
                 }//if
                 }//while
     }
int main(){
    int izbor;
    do{
       cout<<"Izbornik\n-----------\n1. Kreiranje datoteke s praznim zapisima 1\n2. Upis(i duplikati) \n3. Provjera \n4. Upis\n9. Izlaz\n";
       cin>>izbor;
       switch(izbor){
                     case 1: 
                          prvi();
                          break;
                     case 2: 
                          drugi();
                          break;
                     case 3: 
                          treci();
                          break;
                     case 4:
                          cetvrti();
                          break;
       }//switch
    cout<<endl<<endl;
}//do
    while(izbor!=9);
    
    return 0;
}//main
