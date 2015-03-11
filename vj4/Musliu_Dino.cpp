#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"

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
                      cout<<"Otavanje nije uspjelo, datoteka ne postoji na disku!"<<endl;
                      dat.open("roba_Musliu_Dino.dat",ios::out|ios::binary);//kreiranje dat
                      cout<<"Datoteke je uspjesno kreirana!"<<endl;
                      }
             else if(dat){//ako postoji
                  cout<<"Datoteka postoji!"<<endl;
                  cout<<"Zelite li obrisati datoteku i kreirati novu?: (1-DA | 2-NE) ";
                  int izbor;
                  cin>>izbor;
                  if(izbor==1){
                               fstream dat2;
                               //obrisati datoteku....                           
                               cout<<"Datoteka obrisana!"<<endl;
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
                        dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary);
                        
                        while(1){
                              dat.read((char*)&roba,sizeof(roba));
                              if(dat.eof())break;
                              if(sifra==roba.sifra)ista=true;
                              }//while
                        dat.close();
                        dat.clear();
                        if(ista){
                                 while(1){
                                          dat.read((char*)&roba,sizeof(roba));
                                          if(dat.eof())break;
                                          cout<<"Sifra= "<<roba.sifra<<endl;
                                 }//while
                        cout<<"Ponovno unesite sifru\n";
                        return 0;
                        }//if
}//provjera

void unesi(){//2
     
    fstream dat;
    dat.open("roba_Musliu_Dino.dat",ios::out|ios::binary|ios::app);//otvara dat za upis     

    vrijeme_pocetak(); 
    bool pogreska;
    do{
    pogreska=false;
    do{
    cout<<"Sifra: ";
    cin>>roba.sifra;
    }while(provjera(roba.sifra)==0);
    cout<<"Naziv: ";
    cin>>roba.naziv;
    cout<<"Cijena: ";
    cin>>roba.cijena;
    cout<<"Kolicina: ";
    cin>>roba.kolicina;
    float umnozak=(roba.kolicina)*(roba.cijena);
    if(roba.sifra<100 || roba.sifra>999){
       cout<<"Pogresan unos, ponovi unos!"<<endl;
       pogreska=true;
       }//if
    else if(strlen(roba.naziv)>20){
           cout<<"Pogresan unos, ponovi unos!"<<endl;
           pogreska=true;
         }//else if(1)
    else if(umnozak<0){
           cout<<"Pogresan unos, ponovi unos!"<<endl;
           pogreska=true;
         }//else if(2)
    }while(pogreska==true);
    vrijeme_kraj();
    roba.vrijeme_unosa=vrijeme_proteklo();
    cout<<"Vrijeme proteklo: "<<vrijeme_proteklo()/1000<<" s."<<endl;
    dat.write((char *)&roba,sizeof(troba));//upisuje podatke
    
    dat.close();
    dat.clear();   
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
     tvezana*novi=new tvezana;//novi elem. vezane liste
     while(1){
              dat.read((char*)&vezana,sizeof(tvezana));
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
}//vezana


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
                           break;
                      
                      
                      }//switch
        system("pause");
        }while(izbor!=9);
    
    
    return 0;
}//main
