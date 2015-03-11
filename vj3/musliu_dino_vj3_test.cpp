// MD5:9oIK/CdbnZBTeXHTw4lzFg==// Verifikator 3.14// Program:vj3// Opis zadatka:vj3// Autor:dino musliu// Poèetno vrijeme:20.10.2012. 10:11:21// Završno vrijeme:20.10.2012. 13:28:42// IP:fe80::717a:2021:6b7a:177a%11 ( 1540 )// #:#include <iostream>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevoðenja:106/30#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void test(int i){ 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=0;f<60;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: test("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if (br>10)return;} else br=0;zaglavlje = (int)time(0);
  fstream dat("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 29):" << endl; 
  for (f=0;f<60;f++){if (p[f]>0) dat << f << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct slista{
    int sifra;
    char naziv[20];
    float cijena_komada;
    int kolicina;
    int vrijeme_unosa;
    slista*sljedeci;
    slista*prethodni;
};

struct Stablo{
  int s;
  char n[20];
  int c;
  int k;
  int v;
  Stablo*lijevi;
  Stablo*desni;
};

Stablo*stablo=new Stablo;

int Broj_elemenata(slista*lista){test(1);
 int broj=0;
 slista*pomocni=lista->sljedeci;
 while(pomocni)
        {test(2);
        broj++;
        pomocni=pomocni->sljedeci;
        }
 return broj;
}

int prvi(slista*lista){test(3);
       cout<<"Lista ima: "<<Broj_elemenata(lista)<<" elemenata\n";
       slista*pomocni=lista;
       while(pomocni->sljedeci)
           pomocni=pomocni->sljedeci;
       slista*novi=new slista;
       novi->sljedeci=NULL;
       novi->prethodni=NULL;
       vrijeme_pocetak();
       cout<<"Sifra= ";
       cin>>novi->sifra;
       cout<<"Naziv robe= ";
       cin>>novi->naziv;
       cout<<"Cijena komada= ";
       cin>>novi->cijena_komada;
       cout<<"Kolicina= ";
       cin>>novi->kolicina;
       vrijeme_kraj();
       novi->vrijeme_unosa=vrijeme_proteklo();
       cout<<"Vrijeme potrebno za unos podataka je: "<<vrijeme_proteklo()<<endl;
       cout<<"Vrijednost robe= "<<novi->cijena_komada*novi->kolicina<<endl;
       cout<<"1. Potvrdi unos\n";
       cout<<"2. Nemoj potvrditi unos\n";
       int izbor;
       cout<<"Vas izbor: ";
       cin>>izbor;
       if(izbor==1){test(4);
             pomocni->sljedeci=novi;
             novi->prethodni=pomocni;
             pomocni=lista->sljedeci;
             while(pomocni){test(5);
                 cout<<"------------------------------"<<endl;
                 cout<<"Sifra= "<<pomocni->sifra<<endl;
                 cout<<"Naziv= "<<pomocni->naziv<<endl;
                 cout<<"Vrijednost robe= "<<pomocni->cijena_komada*pomocni->kolicina<<endl;
                 cout<<"Vrijeme unosa= "<<pomocni->vrijeme_unosa<<endl;
                 pomocni=pomocni->sljedeci;
             }
             return 0;
             }
      else if(izbor==2){test(6);
         cout<<"Vrijeme unosa = "<<novi->vrijeme_unosa<<endl;
         cout<<"Broj elemenata liste= "<<Broj_elemenata(lista)<<endl;
      }
      else cout<<"Krivi unos\n";
};

int drugi(slista*lista,int broj){test(7);
  slista*novi=new slista;
  novi->sljedeci=NULL;
  novi->prethodni=NULL;
  if(broj==0)
      {test(8);
      lista->sljedeci=novi;
      novi->prethodni=lista;
      }
   else{test(9);
      novi->sljedeci=lista->sljedeci;
      novi->prethodni=lista;
      lista->sljedeci=novi;
      novi->sljedeci->prethodni=novi;
   }
   vrijeme_pocetak();
   cout<<"Sifra= ";
   cin>>novi->sifra;
   cout<<"Naziv robe= ";
   cin>>novi->naziv;
   do{test(10);
    cout<<"Cijena komada= ";
    cin>>novi->cijena_komada;
   }while(novi->cijena_komada<=0);
   do{test(11);
     cout<<"Kolicina= ";
     cin>>novi->kolicina;
     }while(novi->kolicina<=0);
   vrijeme_kraj();
   novi->vrijeme_unosa=vrijeme_proteklo();
   cout<<"Vrijeme trajanja korisnikovog unosa podataka: "<<vrijeme_proteklo()<<endl;
   slista*pomocni=lista->sljedeci;
   while(pomocni->sljedeci)
       pomocni=pomocni->sljedeci;
   while(pomocni!=lista){test(12);
         cout<<"------------------------------"<<endl;
         cout<<"Sifra= "<<pomocni->sifra<<endl;
         cout<<"Naziv robe= "<<pomocni->naziv<<endl;
         cout<<"Vrijednost= "<<pomocni->cijena_komada*pomocni->kolicina<<endl;
         cout<<"Vrijeme unosa= "<<pomocni->vrijeme_unosa<<endl;
         pomocni=pomocni->prethodni;
   }
}

void uzlazno(Stablo*stablo){test(13);
    static Stablo*korijen=stablo;
    if(stablo==NULL)return;
    uzlazno(stablo->lijevi);
    if(stablo!=korijen)cout<<"\n---------------------\n"<<stablo->s<<" naziv= "<<stablo->n<<endl;
    uzlazno(stablo->desni);
}

void silazno(Stablo*stablo){test(14);
    static Stablo*korijen=stablo;
    if(stablo==NULL)return;
    silazno(stablo->desni);
    if(stablo!=korijen)cout<<"\n------------------------\n"<<stablo->s<<" naziv= "<<stablo->n<<endl;
    silazno(stablo->lijevi);
}
int treci(slista*lista,Stablo*stablo){test(15);
      slista*p_lista=lista->sljedeci;
      while(p_lista!=NULL){test(16);
         Stablo*p_stablo=stablo;
         bool izlaz=false;       
         do{test(17);
           if(p_lista->sifra>p_stablo->s){test(18);
                      if(p_stablo->desni!=NULL)
                                    p_stablo=p_stablo->desni;
                      else{test(19);
                          Stablo*novi=new Stablo;
                          p_stablo->desni=novi;
                          novi->desni=NULL;
                          novi->lijevi=NULL;
                          novi->s=p_lista->sifra;
                          strcpy(novi->n,p_lista->naziv);
                          novi->c=p_lista->cijena_komada;
                          novi->k=p_lista->kolicina;
                          izlaz=true;
                      }          //###############
                     
           }//##
           else{test(20);
              if(p_stablo->lijevi!=NULL)
                        p_stablo=p_stablo->lijevi;
             else{test(21);
                   Stablo*novi=new Stablo;
                   p_stablo->lijevi=novi;
                   novi->lijevi=NULL;
                   novi->desni=NULL;
                   novi->s=p_lista->sifra;
                   strcpy(novi->n,p_lista->naziv);
                   novi->c=p_lista->cijena_komada;
                   novi->k=p_lista->kolicina;
                   izlaz=true;
             }//#####
           } //#####
           }while(izlaz==false);
           p_lista=p_lista->sljedeci;
      }
      cout<<"1. Uzlazno\n2. Silazno\n";
      cout<<"Vas izbor: ";
      int izbor;
      cin>>izbor;
      if(izbor==1)
          uzlazno(stablo);
      else 
          silazno(stablo);
      //####################
      //###################
}//#####

Stablo*trazi(Stablo*stablo,int sifra){test(22);
     Stablo*tekuci=stablo;
     while(tekuci){test(23);
         if((tekuci->s==sifra)&&(tekuci!=stablo))break;
         if(sifra>tekuci->s)
            tekuci=tekuci->desni;
         else
           tekuci=tekuci->lijevi;
     }
     return tekuci;
}

void cetvrti(Stablo*stablo){test(24);
    cout<<"1. Pretrazivanje\n2. Dealokacija\n";
    cout<<"Vas izbor: ";
    int izbor;
    cin>>izbor;
    if(izbor==1){test(25);
        cout<<"Sifra robe= ";
        int sifra;
        cin>>sifra;
        bool izbor=false;
        Stablo*pronadjen=trazi(stablo,sifra);
        if(pronadjen==NULL)cout<<"NIJE PRONADJENO!\n";
        else{test(26);
           cout<<"Pronadjen\n";
           cout<<"Sifra= "<<pronadjen->s<<endl;
           cout<<"Naziv= "<<pronadjen->n<<endl<<endl;
        }
        }
        
}

int main(){test(27);
   slista*lista=new slista;
   lista->sljedeci=NULL;
   lista->prethodni=NULL;
   
   stablo->lijevi=NULL;
   stablo->desni=NULL;
   int izbor;
   do{test(28);
       int broj=Broj_elemenata(lista);
       system("cls");
       cout<<"Izbornik\n";
       cout<<"1. Dodavanje elmenta na kraj dvostruko vezane liste\n";
       cout<<"2. Dodavanje elementa na pocetak dvostruko vezane liste\n";
       cout<<"3. Binarno stablo (kreiranje i ispis)\n";
       cout<<"4. Binarno stablo (pretrazivanje / dealokacija)\n";
       cout<<"9. Izlaz iz programa\n";
       cout<<"Vas izbor: ";
       cin>>izbor;

       test(29); switch(izbor){
           case 1:
                 prvi(lista);
                 break;
            case 2:
                 drugi(lista,broj);
                 break;     
            case 3:
                 treci(lista,stablo);
                 break;
           case 4:
                 cetvrti(stablo);
                 
       }
       cout<<"--------------------------------------\n";
       system("pause");
   }while(izbor!=9);
   return 0;
}
  
    
