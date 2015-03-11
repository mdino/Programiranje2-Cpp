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

int Broj_elemenata(slista*lista){
 int broj=0;
 slista*pomocni=lista->sljedeci;
 while(pomocni)
        {
        broj++;
        pomocni=pomocni->sljedeci;
        }
 return broj;
}

int prvi(slista*lista){
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
       if(izbor==1){
             pomocni->sljedeci=novi;
             novi->prethodni=pomocni;
             pomocni=lista->sljedeci;
             while(pomocni){
                 cout<<"------------------------------"<<endl;
                 cout<<"Sifra= "<<pomocni->sifra<<endl;
                 cout<<"Naziv= "<<pomocni->naziv<<endl;
                 cout<<"Vrijednost robe= "<<pomocni->cijena_komada*pomocni->kolicina<<endl;
                 cout<<"Vrijeme unosa= "<<pomocni->vrijeme_unosa<<endl;
                 pomocni=pomocni->sljedeci;
             }
             return 0;
             }
      else if(izbor==2){
         cout<<"Vrijeme unosa = "<<novi->vrijeme_unosa<<endl;
         cout<<"Broj elemenata liste= "<<Broj_elemenata(lista)<<endl;
      }
      else cout<<"Krivi unos\n";
};

int drugi(slista*lista,int broj){
  slista*novi=new slista;
  novi->sljedeci=NULL;
  novi->prethodni=NULL;
  if(broj==0)
      {
      lista->sljedeci=novi;
      novi->prethodni=lista;
      }
   else{
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
   do{
    cout<<"Cijena komada= ";
    cin>>novi->cijena_komada;
   }while(novi->cijena_komada<=0);
   do{
     cout<<"Kolicina= ";
     cin>>novi->kolicina;
     }while(novi->kolicina<=0);
   vrijeme_kraj();
   novi->vrijeme_unosa=vrijeme_proteklo();
   cout<<"Vrijeme trajanja korisnikovog unosa podataka: "<<vrijeme_proteklo()<<endl;
   slista*pomocni=lista->sljedeci;
   while(pomocni->sljedeci)
       pomocni=pomocni->sljedeci;
   while(pomocni!=lista){
         cout<<"------------------------------"<<endl;
         cout<<"Sifra= "<<pomocni->sifra<<endl;
         cout<<"Naziv robe= "<<pomocni->naziv<<endl;
         cout<<"Vrijednost= "<<pomocni->cijena_komada*pomocni->kolicina<<endl;
         cout<<"Vrijeme unosa= "<<pomocni->vrijeme_unosa<<endl;
         pomocni=pomocni->prethodni;
   }
}

void uzlazno(Stablo*stablo){
    static Stablo*korijen=stablo;
    if(stablo==NULL)return;
    uzlazno(stablo->lijevi);
    if(stablo!=korijen)cout<<"\n---------------------\n"<<stablo->s<<" naziv= "<<stablo->n<<endl;
    uzlazno(stablo->desni);
}

void silazno(Stablo*stablo){
    static Stablo*korijen=stablo;
    if(stablo==NULL)return;
    silazno(stablo->desni);
    if(stablo!=korijen)cout<<"\n------------------------\n"<<stablo->s<<" naziv= "<<stablo->n<<endl;
    silazno(stablo->lijevi);
}
int treci(slista*lista,Stablo*stablo){
      slista*p_lista=lista->sljedeci;
      while(p_lista!=NULL){
         Stablo*p_stablo=stablo;
         bool izlaz=false;       
         do{
           if(p_lista->sifra>p_stablo->s){
                      if(p_stablo->desni!=NULL)
                                    p_stablo=p_stablo->desni;
                      else{
                          Stablo*novi=new Stablo;
                          p_stablo->desni=novi;
                          novi->desni=NULL;
                          novi->lijevi=NULL;
                          novi->s=p_lista->sifra;
                          strcpy(novi->n,p_lista->naziv);
                          novi->c=p_lista->cijena_komada;
                          novi->k=p_lista->kolicina;
                          izlaz=true;
                      }          //else           
                     
           }//if
           else{
              if(p_stablo->lijevi!=NULL)
                        p_stablo=p_stablo->lijevi;
             else{
                   Stablo*novi=new Stablo;
                   p_stablo->lijevi=novi;
                   novi->lijevi=NULL;
                   novi->desni=NULL;
                   novi->s=p_lista->sifra;
                   strcpy(novi->n,p_lista->naziv);
                   novi->c=p_lista->cijena_komada;
                   novi->k=p_lista->kolicina;
                   izlaz=true;
             }//else2
           } //else1
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
      //stablo->lijevi=NULL;
      //stablo->desni=NULL;
}//treci

Stablo*trazi(Stablo*stablo,int sifra){
     Stablo*tekuci=stablo;
     while(tekuci){
         if((tekuci->s==sifra)&&(tekuci!=stablo))break;
         if(sifra>tekuci->s)
            tekuci=tekuci->desni;
         else
           tekuci=tekuci->lijevi;
     }
     return tekuci;
}

int dealokacija(Stablo*stablo){
      static int broj=0;
      static Stablo*korijen=stablo;
      if(stablo->lijevi)dealokacija(stablo->lijevi);
      if(stablo->desni)dealokacija(stablo->desni);
      
      if(stablo!=korijen){
      broj++;
      delete stablo;}
      return broj;
}
void cetvrti(Stablo*stablo){
    cout<<"1. Pretrazivanje\n2. Dealokacija\n";
    cout<<"Vas izbor: ";
    int izbor;
    cin>>izbor;
    if(izbor==1){
        cout<<"Sifra robe= ";
        int sifra;
        cin>>sifra;
        bool izbor=false;
        Stablo*pronadjen=trazi(stablo,sifra);
        if(pronadjen==NULL)cout<<"NIJE PRONADJENO!\n";
        else{
           cout<<"Pronadjen\n";
           cout<<"Sifra= "<<pronadjen->s<<endl;
           cout<<"Naziv= "<<pronadjen->n<<endl<<endl;
        }
        }
    else{
       int broj=dealokacija(stablo);
       cout<<"Broj dealociranih cvorova stabla= "<<broj<<endl;
    }
}

int main(){
   slista*lista=new slista;
   lista->sljedeci=NULL;
   lista->prethodni=NULL;
   
   stablo->lijevi=NULL;
   stablo->desni=NULL;
   int izbor;
   do{
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

       switch(izbor){
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
  
  
