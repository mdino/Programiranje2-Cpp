#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct troba{
             int sifra,kolicina;
             char naziv[80];
             float cijena,vrijednost,vrijeme;
             };//struct
struct troba2{
             int sifra,kolicina;
             char naziv[80];
             float cijena,vrijednost,vrijeme;
             troba2*sljedeci;
             };//struct
troba roba;
troba roba3;
troba2 roba2;
int bzapisa(){
               int brojac=-1;
               ifstream dat("roba_Vrevic_Armin.dat");
               if(dat.is_open()){
                           brojac++;
                           while(1){
                                    dat.read((char*)&roba3,sizeof(roba3));
                                    if(dat.eof())break;
                                    brojac++;
                                    }//while
                           dat.close();
                           dat.clear();
                           }//if
               return brojac;
                    }//funkcija
int provjera(int sifra){
                        int ista=false;
                        ifstream dat("roba_Vrevic_Armin.dat");
                        while(1){
                              dat.read((char*)&roba3,sizeof(roba3));
                              if(dat.eof())break;
                              if(sifra==roba3.sifra)ista=true;
                              }//while
                        dat.close();
                        dat.clear();
                        if(ista){
                                 ifstream dat2("roba_Vrevic_Armin.dat");
                                 cout<<"---------\n---------\n---------\n";
                                 while(1){
                                          dat2.read((char*)&roba3,sizeof(roba3));
                                          if(dat2.eof())break;
                                          cout<<"Sifra= "<<roba3.sifra<<endl;
                                 }//while
                        cout<<"---------\n---------\n---------\n";
                        cout<<"Ponovno unesite sifru\n\n\n";
                        return 0;
                        }//if
                        return 1;
                        }//funkcija
void ispis(){
             ifstream dat("roba_Vrevic_Armin.dat");
             cout<<"------------------------\n\n";
             while(1){
                      dat.read((char*)&roba,sizeof(roba));
                      if(dat.eof())break;
                      cout<<"Sifra= "<<roba.sifra<<endl<<"Naziv= "<<roba.naziv<<endl<<"Vrijednost= "<<roba.vrijednost<<endl;
                      cout<<"Cijena= "<<roba.cijena<<endl<<"Kolicina= "<<roba.kolicina<<endl<<"Vrijeme= "<<roba.vrijeme<<endl;
                      cout<<"-----------------------\n";  
                      }//while
             dat.close();
             dat.clear();
             }//funkcija
void vezana(){
              ifstream dat("roba_Vrevic_Armin.dat");
              troba2 *glava=new troba2;
              glava->sljedeci=NULL;
              troba2*zadnji=new troba2;
              while(1){
                       dat.read((char*)&roba,sizeof(roba));
                       if(dat.eof())break;
                       troba2*novi;
                       zadnji=glava;
                       while(zadnji->sljedeci)zadnji=zadnji->sljedeci;
                       novi=new troba2;
                       novi->sifra=roba.sifra;
                       strcpy(novi->naziv,roba.naziv);
                       novi->vrijednost=roba.vrijednost;
                       novi->cijena=roba.cijena;
                       novi->kolicina=roba.kolicina;
                       novi->vrijeme=roba.vrijeme;
                       zadnji->sljedeci=novi;
                       novi->sljedeci=NULL;
                       }//while
              troba2*trenutno;
              trenutno=glava->sljedeci;              
              cout<<"Vezana lista : \n----------\n\n";
              while(trenutno){
                              cout<<"Sifra= "<<trenutno->sifra<<endl<<"Naziv= "<<trenutno->naziv<<endl;
                              cout<<"\n---------\n----------\n";
                              trenutno=trenutno->sljedeci;
                              }//while
              cout<<endl<<endl;
              troba2*prethodni,*tekuci,*sljedeci;
              int indikator,brojac=0;
              do{
                  indikator=0;
                  tekuci=glava->sljedeci;
                  prethodni=glava;
                  while(tekuci->sljedeci){
                                          sljedeci=tekuci->sljedeci;
                                          if(tekuci->sifra>sljedeci->sifra){
                                                                            prethodni->sljedeci=sljedeci;
                                                                            tekuci->sljedeci=sljedeci->sljedeci;
                                                                            sljedeci->sljedeci=tekuci;
                                                                            indikator=1;
                                                                            }//if
                                          prethodni=prethodni->sljedeci;
                                          tekuci=prethodni->sljedeci;
                                          }//while
                                          }//while
              while(indikator==1);
              ofstream dat2("roba_sort_Vrevic_Armin.dat");
              trenutno=glava->sljedeci;
              while(trenutno){
                              dat2.write((char*)&*trenutno,sizeof(*trenutno));
                              trenutno=trenutno->sljedeci;
                              }
              dat2.close();
              dat2.clear();
              zadnji=glava;
              trenutno=glava->sljedeci;
              while(trenutno){
                              delete zadnji;
                              zadnji=trenutno;
                              trenutno=trenutno->sljedeci;
                              }//while
              }//funkcija
void f(){
         bool pogresno;
         if(bzapisa()>=0)cout<<"Datoteka postoji i unutra se nalazi: "<<bzapisa()<<" elemenata!\n";
         else{
              cout<<"Datoteka ne postoji, kreiram novu! \n";
              ofstream dat2("roba_Vrevic_Armin.dat",ios::binary);
              dat2.close();
              dat2.clear();
                            }//else
         vrijeme_pocetak();
         pogresno=true;
         do{
             cout<<"Sifra= ";
             cin>>roba.sifra; 
             }//do
         while(provjera(roba.sifra)==0);
         cout<<"Naziv= ";  
         cin>>roba.naziv;
         cout<<"Cijena= ";
         cin>>roba.cijena;
         cout<<"Kolicina= "; 
         cin>>roba.kolicina;
         roba.vrijednost=roba.cijena*roba.kolicina;
         vrijeme_kraj();
         if(roba.sifra<10||roba.sifra>999)cout<<"POGRESNO UNESENI PODACI!\n";
         else if(strlen(roba.naziv)>40)cout<<"POGRESNO UNESENI PODACI!\n";
         else if((roba.cijena*roba.kolicina)<0||(roba.cijena*roba.kolicina)>39235)cout<<"POGRESNO UNESENI PODACI\n";     
         else pogresno=false;       
         if(!pogresno){ 
                        cout<<"\n-----------------------------\n\n\n";
                        roba.vrijeme=vrijeme_proteklo()/100;
                        ofstream dat3("roba_Vrevic_Armin.dat",ios::app);
                        dat3.write((char*)&roba,sizeof(roba));
                        dat3.close();
                        dat3.clear();
                        ispis();
                       }//if     
        }//funkcija
int main(){
        int izbor;
    do{
        cout<<"------------------\n";
        cout<<"|    Izbornik    |";
        cout<<"\n------------------\n";
        cout<<"1. Unos podataka o robi  u datoteku\n";
        cout<<"2. Ispis sadrzaja datoteke roba\n";
        cout<<"3. Sortiranje datoteke uz pomoc vezane liste\n";
        cout<<"9. Izlaz\n";
        cin>>izbor;
        switch(izbor){
                      case 1:{
                              f();
                              break;
                              }//case 1
                      case 2:{
                              int brojac=0;
                              cout<<"Unesite naziv datoteke: ";
                              char naziv[60];
                              cin.ignore();
                              cin.getline(naziv,60);
                              ifstream dat(naziv);
                              if(dat.is_open()){
                                                if(strcmp(naziv,"roba_sort_Vrevic_Armin.dat")){//ovaj if dodati tek nakon svih funkcija i svega
                                                                             cout<<"U datoteci se nalazi : "<<bzapisa()<<" elemenata\n";                         
                                                                             if(bzapisa()<2)cout<<endl;
                                                                             else ispis();
                                                                                 }//if
                                                else{//cijeli else dodati nakon svih funkcija i svega
                                                       int brojac=0;
                                                       while(1){
                                                                dat.read((char*)&roba2,sizeof(roba2));
                                                                if(dat.eof())break;
                                                                brojac++;
                                                                }//while
                                                       if(brojac<2){
                                                                    cout<<"U datoteci se nalazi: "<<brojac<< " elemenata\n";
                                                                    }                                                                   
                                                       else{
                                                            dat.close();
                                                            dat.clear();
                                                            ifstream dat2(naziv);
                                                            while(1){
                                                                     cout<<endl<<endl;
                                                                     dat2.read((char*)&roba2,sizeof(roba2));
                                                                     if(dat2.eof())break;
                                                                     cout<<"Sifra= "<<roba2.sifra<<endl<<"Naziv= "<<roba2.naziv<<endl;
                                                                     cout<<"Vrijednost= "<<roba2.vrijednost<<endl<<"Vrijeme= "<<roba2.vrijeme<<endl;
                                                                     cout<<"--------------------\n------------------\n";
                                                                     }//while
                                                            dat2.close();
                                                            dat2.clear();
                                                            }//else 
                                                            }//else                    
                                                }//if
                              else cout<<"Datoteka ne postoji! \n";
                              dat.close();
                              dat.clear();
                              break;
                              }//case 2
                      case 3:{
                              if(bzapisa()<=0)cout<<"Niste unijeli niti jedan element dosad!\n";
                              else vezana();
                              break;
                              }//case 3
                      }//switch
                      }//do
        while(izbor!=9);
    return 0;
}//main
