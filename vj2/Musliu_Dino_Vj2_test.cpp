// MD5:utMTOF8juGEEx3KFQW62lg==// Verifikator 3.14// Program:Vj2// Opis zadatka:Vj2// Autor:Dino Musliu// Poèetno vrijeme:10.10.2012. 22:38:08// Završno vrijeme:11.10.2012. 0:20:44// IP:fe80::717a:2021:6b7a:177a%11 ( 1540 )// #:#include <iostream>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevoðenja:49/21#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void test(int i){ 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=0;f<60;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: test("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if (br>10)return;} else br=0;zaglavlje = (int)time(0);
  fstream dat("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 13):" << endl; 
  for (f=0;f<60;f++){if (p[f]>0) dat << f << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include "biblioteka_vrijeme.cc"

using namespace std;

struct sknjiga{
    int maticni;
    char prezime[20];
    char ime[20];
    int godina_upisa;
    int vrijeme_unosa;
    sknjiga*sljedeci;
};

sknjiga*glava;

int prva(sknjiga*glava){test(1);
    if(glava==NULL){test(2);
      cout<<"Glava vezane liste nije alocirana, idite na mogucnost 0"<<endl;
      return 0;
      }
      
      bool ponovi_unos;
      sknjiga*novi;
      novi=new sknjiga;
      vrijeme_pocetak();
      do{test(3);
      cout<<"Unesi maticni broj: ";
      cin>>novi->maticni;
      ponovi_unos=false;
      sknjiga*pomocni=glava->sljedeci;
      while(pomocni!=NULL){test(4);
      if(novi->maticni=pomocni->maticni){test(5);}
      }

      cout<<"Unesi prezime: ";
      cin>>novi->prezime;
      cout<<"Unesi ime: ";
      cin>>novi->ime;
      cout<<"Unesi godinu upisa: ";
      cin>>novi->godina_upisa;
      vrijeme_kraj();
      novi->vrijeme_unosa=int(vrijeme_proteklo()/1000);
      cout<<"Vrijeme unosa je"<<novi->vrijeme_unosa<<endl;
      novi->sljedeci=NULL;
      }while(novi->maticni<30000||novi->maticni>49999||ponovi_unos==true);
      sknjiga*pomocni=glava;
      while(pomocni->sljedeci!=NULL){test(6);
              pomocni=pomocni->sljedeci;
              }
              pomocni->sljedeci=novi;
      };
      
int druga(sknjiga*glava){test(7);
    int brojac=0;
    float sredina=0;
    if(glava==NULL) return -1;
    
    sknjiga*pomocni;
    pomocni=glava->sljedeci;
    
    while(pomocni!=NULL){test(8);
    
    cout<<"Maticni broj: "<<pomocni->maticni<<endl;
    cout<<"Ime: "<<pomocni->ime<<endl;
    cout<<"Prezime: "<<pomocni->prezime<<endl;
    cout<<"Godina upisa: "<<pomocni->godina_upisa<<endl;
    sredina=sredina+pomocni->vrijeme_unosa;
    brojac++;
    cout<<"-----------------------------------"<<endl;
    pomocni=pomocni->sljedeci;
    }
    cout<<"Aritmeticka sredina je: "<<sredina/brojac<<endl;
    
    return brojac;
};

int main(){test(9);

    int izbor;
    
    do{test(10);
        system("cls");
        cout<<"0. Alokacija glave vezane liste"<<endl;
        cout<<"1. Unos novog elementa vezane liste studenta"<<endl;
        cout<<"2. Ispis sadraja cijele vezane liste"<<endl;
        cout<<"3. Brisanje elementa liste"<<endl;
        cout<<"9. Izlaz iz programa"<<endl;
        cout<<"Izbor?: ";
        cin>>izbor;
      
    test(11); switch(izbor){
        case 0:
                if(glava==NULL){test(12);
                    cout<<"Glava vezane liste NIJE alocirana, ponovite mogucnost 0 za alociranje"<<endl;
                    glava=new sknjiga;
                    glava->sljedeci=NULL;
                    }
                else cout<<"Glava vezane liste JE vec alocirana"<<endl;
                
                break;
        case 1:
                prva(glava);
                break;
        
        case 2:
                if(druga(glava)==-1){test(13);
                        cout<<"Glava vezane liste nije alocirana. ";
                        break;
                        }
                
                cout<<"Broj elementa vezane liste je:" <<druga(glava)<<endl;
                
                break;
    
    }//######
    system("pause");
    }while(izbor!=9);
  
  
    return 0;
}//####
    
