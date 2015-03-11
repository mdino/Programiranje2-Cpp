#include <iostream>
#include <cstring>

using namespace std;

int izbor,br_stud=0,br_prij=0;

class cstudij{
      public:
             cstudij*sljedeci;
             virtual void unos(){
                     
                     };
             virtual void ispis(){
                     
                     };
             cstudij(){
                       sljedeci=NULL;
                       }
             virtual bool id(){
                     
                     };
             virtual int sifra_ret(){
                     
                     };
             virtual string prezime(){
                     
                     };
      };

//
class cstudent: public cstudij{
      public:
             int maticni;
             string prezimeime;
             void unos(){
                  cout<<"Maticni= ";
                  cin>>maticni;
                  cout<<"Prezime i ime: ";
                  cin>>prezimeime;
             }
             void ispis(){
                  cout<<"-----------------\n";
                  cout<<"STUDENT\n-----------------\n";
                  cout<<"Maticni= "<<maticni<<endl;
                  cout<<"Prezime i ime= "<<prezimeime<<endl;
             }
      bool id(){
           return 0;
           }
      int sifra_ret(){
          return maticni;
          }
       string prezime(){
           return prezimeime;        
           }
           
};

class cprijava: public cstudij{
      public:
             int sifra;
             int maticni;
             string predmet;
             int rok;
             void unos(){
                  cout<<"Sifra= ";
                  cin>>sifra;
                  cout<<"Maticni= ";
                  cin>>maticni;
                  cout<<"Predmet= ";
                  cin>>predmet;
                  cout<<"Rok= ";
                  cin>>rok;
                  }
             void ispis(){
                  cout<<"-----------------\n";
                  cout<<"PRIJAVA\n-----------------\n";
                  cout<<"SIFRA= "<<sifra<<endl;
                  cout<<"Maticni= "<<maticni<<endl;
                  cout<<"Predmet= "<<predmet<<endl;
                  cout<<"Rok= "<<rok<<endl;
                  }
             bool id(){
                  return 1;
                  }
             int sifra_ret(){
                 return maticni;
                 }
             string prezime(){
                    return predmet;
                    }
      };

cstudij*glava=new cstudij;

void prvi(){//3 testiranje - classprijava - unos i ispis, else if(2) bez pronadjen
//4 testiranje int sfira ret + cijeli prvi + dodat u case 5
     cout<<"Broj elemenata vezane liste je: "<<br_stud+br_prij<<endl;
     cout<<"1. Upis novog studenta\n";
     cout<<"2. Upis nove prijave\n";
     cout<<"3. Ispis cijele liste\n";
     cout<<"Vas izbor: ";
     cin>>izbor;
     cstudij*tekuci=glava;
     if(izbor==1){
        while(tekuci->sljedeci)tekuci=tekuci->sljedeci;
        cstudent*novi=new cstudent;
        novi->unos();
        tekuci->sljedeci=novi;
        br_stud++;
                  }//if
     else if(izbor==2){
        //  if(br_stud==0)cout<<"Nema niti jednog studenta\n";
//          if(br_stud==0)return;
          while(tekuci->sljedeci)tekuci=tekuci->sljedeci;
          cprijava*novi=new cprijava;
          novi->unos();
          cstudij*provjera=glava->sljedeci;
          bool pronadjen=false;
          while(provjera){
            if(novi->maticni==provjera->sifra_ret())pronadjen=true;
            provjera=provjera->sljedeci;
                          }
          if(pronadjen)cout<<"Pronadjen je student s tim maticnim brojem\n";
          if(!pronadjen)cout<<"Nema tog studenta u listi\n";
          if(!pronadjen)return;
          tekuci->sljedeci=novi;
          br_prij++;
          }///else if
     else if(izbor==3){
        tekuci=glava->sljedeci;
        while(tekuci){
         tekuci->ispis();
         tekuci=tekuci->sljedeci;
                      }//while
     }//else if
}//prvi
     
void drugi(){
     cout<<"Ukupni broj upisanih studenata= "<<br_stud<<endl;
     cout<<"Ukupni broj prijava= "<<br_prij<<endl;
     cout<<"1. Ispis popisa studenata\n";
     cout<<"2. Ispis popisa prijava\n";
     cout<<"Vas izbor: ";
     cin>>izbor;
     if(izbor==1){
         cstudij*tekuci=glava->sljedeci;
         while(tekuci){
            if(tekuci->id()==0)tekuci->ispis();
            tekuci=tekuci->sljedeci;
                       }
                  }
     else if(izbor==2){
          cstudij*tekuci=glava->sljedeci;
          while(tekuci){
             if(tekuci->id()==1)tekuci->ispis();
             tekuci=tekuci->sljedeci;
                        }
          }
     }
     
void treci(){
     cout<<"Ukupni broj upisanih studenata= "<<br_stud<<endl;
     cout<<"Ukupni broj prijava= "<<br_prij<<endl;
     if(br_stud==0)cout<<"Niti jedan student nije upisan\n";
     if(br_stud==0)return;
     cout<<"Maticni= ";
     int maticni;
     cin>>maticni;
     cout<<"Ime i prezime studenta: ";
     cstudij*tekuci=glava->sljedeci;
     bool pronadjen=false;
     while(tekuci){
      if(tekuci->id()==0&&tekuci->sifra_ret()==maticni){
                          cout<<tekuci->prezime()<<endl;
                          pronadjen=true;
                          }
      tekuci=tekuci->sljedeci;
                   }
      if(!pronadjen)cout<<"Student nije pronadjen\n";
      if(!pronadjen)return;
     tekuci=glava->sljedeci;
     while(tekuci){
       if(tekuci->id()==1&&tekuci->sifra_ret()==maticni)tekuci->ispis();
       tekuci=tekuci->sljedeci;
                   }
     }
     
void cetvrti(){
cout<<"Ukupni broj upisanih studenata= "<<br_stud<<endl;
     cout<<"Ukupni broj prijava= "<<br_prij<<endl;
     if(br_stud==0)cout<<"Niti jedan student nije upisan\n";
     if(br_stud==0)return;
     cout<<"Prezime i ime studenta: ";
     string pi;
     cin>>pi;
     cout<<"Maticni broj studenta: ";
     cstudij*tekuci=glava->sljedeci;
     bool pronadjen=false;
     int maticni;
     while(tekuci){
      if(tekuci->id()==0&&(tekuci->prezime()==pi)){
                          cout<<tekuci->sifra_ret()<<endl;
                          maticni=tekuci->sifra_ret();
                          pronadjen=true;
                          }
      tekuci=tekuci->sljedeci;
                   }
      if(!pronadjen)cout<<"Student nije pronadjen\n";
      if(!pronadjen)return;
     tekuci=glava->sljedeci;
     while(tekuci){
       if(tekuci->id()==1&&tekuci->sifra_ret()==maticni)tekuci->ispis();
       tekuci=tekuci->sljedeci;
                   }
     }
     
int main(){
 do{
     system("cls");
     cout<<"1. Unos studenata/unos prijava/ispis studenata i prijava"<<endl;
     cout<<"2. Ispis studenata/ispis prijava (odvojeno)"<<endl;
     cout<<"3. Ispis liste prijava zadanog studenta (prema matiènom broju)"<<endl;
     cout<<"4. Ispis liste prijava zadanog studenta (prema prezimenu i imenu)"<<endl;
     cout<<"9. Izlaz iz programa"<<endl;


     cout<<"Izbor? ";
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
                   case 5://1 testiranje nakon izbornika, 2 testiranje nakon class studij do void ispis();
                   		cstudent*pomoc=new cstudent;
                   		cprijava*pomoc2=new cprijava;
                   		pomoc->unos();
                   		pomoc->ispis();
                   		glava->ispis();
                   		glava->sifra_ret();
                   		glava->unos();
                   		pomoc->sifra_ret();
                   		pomoc2->sifra_ret();
                   }
     system("pause");
     
     }while(izbor!=9);   
    
 return 0;   
}
