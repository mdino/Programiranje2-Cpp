#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
#include <stdio.h>
using namespace std;

int globalni_br=0;

struct troba{
       int sifra,kolicina;
       char naziv[30];
       float cijena,vrijeme_unosa;       
};

troba roba;

struct tvezana{
      int sifra,kolicina;
      char naziv[30];
      float cijena,vrijeme_unosa;
      tvezana*sljedeci;
};

int postoji(){//1
             char ime[20];
             fstream dat;
             dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary); //citanje datoteke
             if(!dat){//ako ne postoji
                      cout<<"Otvarnje nije uspjelo, datoteka ne postoji na disku!"<<endl;
                      dat.open("roba_Musliu_Dino.dat",ios::out|ios::binary);//kreiranje dat
                      cout<<"Datoteke je uspjesno kreirana!"<<endl;
                      }
             else if(dat){//ako postoji
                  cout<<"Datoteka postoji!"<<endl;
                  cout<<"Zelite li obrisati datoteku i kreirati novu?: (1-DA | 2-NE) ";
                  int izbor;
                  cin>>izbor;
                  if(izbor==1){
                               dat.close();
                               dat.clear();
                               remove("roba_Musliu_Dino.dat");  
                               fstream dat2;    
                               cout<<"Ime nove datoteke: ";
                               cin>>ime;
                               dat2.open(ime,ios::out|ios::binary);
                               cout<<"Datoteka kreirana, ime nove datoteke je \""<<ime<<"\""<<endl;
                               }
                  else if(izbor==2){
                       return 0;
                       }
                  else
                      cout<<"Krivi unos!"<<endl;
                  
                  }
             dat.close();
             dat.clear();
};

int provjera(int sifra){//4
                        int ista=false;
                        fstream dat;
                        int brojac=0;
                        dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary);
                        
                        while(1){
                              dat.read((char*)&roba,sizeof(roba));
                              if(dat.eof())break;
                              if(sifra==roba.sifra){
                                                    brojac++;
                                                    ista=true;
                                                    }
                              }//while
                        if(ista){
                                 while(1){
                                          dat.read((char*)&roba,sizeof(roba));
                                          if(dat.eof())break;
                                 }//while
                        cout<<"Broj istih sifri = "<<brojac<<endl;                 
                        return 0;
                        }//if
                        dat.close();
                        dat.clear();
                        return 1;
}//provjera

void unesi(){//2
     
    fstream dat;
    dat.open("roba_Musliu_Dino.dat",ios::out|ios::binary|ios::app);//otvara dat za upis     

    vrijeme_pocetak(); 
    bool pogreska;
    int s;
    do{
    pogreska=true;
    do{
    cout<<"Sifra: ";
    cin>>roba.sifra;
    s=roba.sifra;
    }while(provjera(roba.sifra)==0);
    cout<<"Naziv: ";
    unos(roba.naziv);
    cout<<"Cijena: ";
    cin>>roba.cijena;
    cout<<"Kolicina: ";
    cin>>roba.kolicina;
    float umnozak=(roba.kolicina)*(roba.cijena);
    if(roba.sifra<100 || roba.sifra>999){
       cout<<"Pogresan unos, ponovi unos!"<<endl;
       pogreska=false;
       }//if
    else if(strlen(roba.naziv)>20){
           cout<<"Pogresan unos, ponovi unos!"<<endl;
           pogreska=false;
         }//else if(1)
    else if(umnozak<0){
           cout<<"Pogresan unos, ponovi unos!"<<endl;
           pogreska=false;
         }//else if(2)
    }while(pogreska==false);
    vrijeme_kraj();
    roba.vrijeme_unosa=vrijeme_proteklo();
    cout<<"Vrijeme proteklo: "<<vrijeme_proteklo()/1000<<" s."<<endl;
    cout<<"Zapisujem sifru: "<<roba.sifra<<endl;
    roba.sifra=s;
    dat.write((char *)&roba,sizeof(troba));//upisuje podatke
    dat.close();
    dat.clear();
    fstream dat3;
    dat3.open("roba_Musliu_Dino.dat",ios::in|ios::out|ios::binary);
    
     while(1){
                  dat3.read((char*)&roba,sizeof(troba));
                  if(dat3.eof()) break;
                  cout<<"Sifra: "<<roba.sifra<<endl;
                  cout<<"Naziv: "<<roba.naziv<<endl;
                  cout<<"Cijena: "<<roba.cijena<<endl;
                  cout<<"Kolicina: "<<roba.kolicina<<endl;
                  cout<<"--------------------------"<<endl;
}
dat3.close();
dat3.close();
}

int drugi(){//3

    int brojac=0;  
    float umnozak=0;
    float suma=0;
  
    char ime[20];
    cout<<"Ime datoteke: ";
    cin>>ime;
    cout<<endl;    
    
    
    fstream dat;
    dat.open(ime,ios::in|ios::binary);
    
    if(!dat){//ako ne postoji
       cout<<"Otavanje nije uspjelo, datoteka ne postoji na disku!"<<endl;
       return 0;
       }
    else{
         while(1){
                  dat.read((char*)&roba,sizeof(troba));
                  if(dat.eof()) break;
                  cout<<"Sifra: "<<roba.sifra<<endl;
                  cout<<"Naziv: "<<roba.naziv<<endl;
                  cout<<"Cijena: "<<roba.cijena<<endl;
                  cout<<"Kolicina: "<<roba.kolicina<<endl;
                  cout<<"--------------------------"<<endl;
                  brojac++;
                  umnozak=roba.kolicina*roba.cijena;
                  suma+=umnozak;
                  }
         cout<<"Ukupna vrijednost robe: "<<suma<<endl;
         cout<<"Broj zapisa u datoteci je: "<<brojac<<"."<<endl;
         globalni_br=brojac;
         }
    dat.close();
    dat.clear();
}//drugi

       

void vezana(){
     fstream dat;
     dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary);
     tvezana*glava=new tvezana; //alokacija glave vezane liste
     glava->sljedeci=NULL;
     while(1){
     tvezana*novi=new tvezana;
              dat.read((char*)&roba,sizeof(roba));
              if(dat.eof()) break;
              novi->sifra=roba.sifra;
              strcpy(novi->naziv,roba.naziv);
              novi->kolicina=roba.kolicina;
              novi->cijena=roba.cijena;
              novi->vrijeme_unosa=roba.vrijeme_unosa;
              novi->sljedeci=NULL;
              tvezana*pomocni=glava;
              while(pomocni->sljedeci!=NULL){
                                             pomocni=pomocni->sljedeci;
                                             }
              pomocni->sljedeci=novi;
     }//while
     
     //sortiranje uzlazno
     tvezana *prethodni,*tekuci,*sljedeci;
     int indikator,brojac=0;
     do{
        indikator = 0;
        tekuci=glava->sljedeci;
        prethodni=glava;
     while (tekuci->sljedeci){
      sljedeci=tekuci->sljedeci;
      if (tekuci->sifra > sljedeci->sifra){
         prethodni->sljedeci=sljedeci;
         tekuci->sljedeci=sljedeci->sljedeci;
         sljedeci->sljedeci=tekuci;
         indikator=1;
      }//if
      prethodni=prethodni->sljedeci;
      tekuci=prethodni->sljedeci;
    }//while
  } while (indikator==1);
  
   dat.close();
   dat.clear();
   ofstream dat6;
   dat6.open("roba_sort_Musliu_Dino.txt");
   if(dat6.is_open())cout<<"Uspjesno otvorena\n";
   else cout<<"Nije otvorena!!!!!!!\n";
   tekuci=glava->sljedeci;
   while(tekuci){
       dat6<<tekuci->sifra<<"\t"<<tekuci->naziv<<"\t"<<tekuci->kolicina<<"\t"<<tekuci->cijena<<"\t"<<tekuci->vrijeme_unosa<<endl;
       tekuci=tekuci->sljedeci;
       }
   dat6.close();
   dat6.clear();
   cout<<"DEALOCIRAM\n";
   tvezana*pomocni=glava->sljedeci;
   prethodni=glava->sljedeci;
   while(pomocni->sljedeci){
        pomocni=pomocni->sljedeci;
        delete prethodni;
        prethodni=pomocni;
                            }
   delete pomocni;
   delete glava;
   delete prethodni;
}
     


int main(){
    int izbor;

    
    do{
        system("cls");
        cout<<"0. Provjera i kreiranje datoteke"<<endl;
        cout<<"1. Unos podataka o robi u datoteku"<<endl;
        cout<<"2. Ispis sadrzaja datoteke roba"<<endl;
        cout<<"3. Sortiranje datoteke uz pomoc vezane liste"<<endl;
        cout<<"9. Izlaz iz programa"<<endl;
        cout<<"Izbor: ";
        cin>>izbor;
        
        switch(izbor){
                      case 0:
                           postoji();
                           break;
                      
                      case 1:
                           unesi();
                           break;
                      
                      case 2:
                           drugi();
                           break;
                      
                      case 3:
                           vezana();
                           break;
                      
                      
                      }//switch
        system("pause");
        }while(izbor!=9);
    
    
    return 0;
}//main
