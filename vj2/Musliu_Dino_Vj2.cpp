// MD5:zSKYRODOCH1vfVffIjnjEA==
// Verifikator 3.14
// Program:Vj2
// Opis zadatka:Vj2
// Autor:Dino Musliu
// Poèetno vrijeme:10.10.2012. 22:38:08
// Završno vrijeme:11.10.2012. 0:22:21
// IP:fe80::717a:2021:6b7a:177a%11 ( 1540 )
// #:#include <iostream>,#include "biblioteka_vrijeme.cc",
// Uspješnih/neuspješnih prevoðenja:50/22
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

int prva(sknjiga*glava){
           bool postoji;
		if(glava==NULL){
			cout<<"Glava vezane liste nije alocirana, idite na mogucnost 0"<<endl;
			return 0;
			}
			
			
			sknjiga*novi;
			novi=new sknjiga;
			vrijeme_pocetak();
			
			
            ponovi_unos:       
			do{
                do{
                    postoji=false;
        			cout<<"Unesi maticni broj: ";
        			cin>>novi->maticni;
        			sknjiga*P=glava->sljedeci;
        		    while(P){
                                   if(P->maticni==novi->maticni)postoji=true;
                                   P=P->sljedeci;
                                   }
                   if(postoji)cout<<"Taj maticni broj vec postoji, unesite novi!"<<endl;
                   }while(postoji);
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
			}while(novi->maticni<30000||novi->maticni>49999);
		  sknjiga*pomocni=glava;
  		while(pomocni->sljedeci!=NULL){
		  				pomocni=pomocni->sljedeci;
				  		}
		  				pomocni->sljedeci=novi;
  		};
		  
int druga(sknjiga*glava){
		int brojac=0;
		float sredina=0;
		if(glava==NULL) return -1;
		sknjiga*pomocni;
		pomocni=glava->sljedeci;
		
		while(pomocni!=NULL){
	
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

int treca(sknjiga*glava, int mt_broj){
    bool lista;
    if(glava==NULL){
                    cout<<"Glava vezane liste nije alocirana, idite na mogucnust 0. "<<endl;
                    return 0;
                    }
  do{
     cout<<"Unesi maticni broj: ";
     cin>>mt_broj;
    
    sknjiga* pretrazi;
    pretrazi=glava->sljedeci;
    while(pretrazi){
                    if(pretrazi->maticni==mt_broj){
                       cout<<"Ime: "<<pretrazi->ime<<endl;
                       cout<<"Prezime: "<<pretrazi->prezime<<endl;
                       cout<<"Zelite li obrisati listu (1-DA)(0-NE)";
                       cin>>lista;
                       if(lista==1){
                                     sknjiga *brisi = glava -> sljedeci;
                                     sknjiga *prethodni = glava;
                                     while (brisi){
                                                     if (brisi -> maticni == mt_broj){
                                                     prethodni -> sljedeci = brisi -> sljedeci;
                                                      delete brisi;
                                                      cout << "Element je izbrisan iz vezane liste!" << endl;
                                                      return 0;
                                                      }
                                                      }
                                    } 
                       return 0;
                                                   }
                       pretrazi=pretrazi->sljedeci;
                    }
    sknjiga*pomocni;
    pomocni=glava->sljedeci;
    cout<<"Nije pronadeni odgovarajuci maticni broj,postojeci maticni brojevi:  "<<endl;
    while(pomocni!=NULL){
                         cout<<"Maticni broj: "<<pomocni->maticni<<endl;
                         pomocni=pomocni->sljedeci;
                         }
    cout<<"Ponovite unos. "<<endl;
    }while(1);
    return 0;
};

int main(){
        int mt_broj;
		int izbor;
		int bla;
		
		do{
				system("cls");
				cout<<"0. Alokacija glave vezane liste"<<endl;
				cout<<"1. Unos novog elementa vezane liste studenta"<<endl;
				cout<<"2. Ispis sadraja cijele vezane liste"<<endl;
				cout<<"3. Brisanje elementa liste"<<endl;
				cout<<"9. Izlaz iz programa"<<endl;
				cout<<"Izbor?: ";
				cin>>izbor;
			
		switch(izbor){
				case 0:
								if(glava==NULL){
										cout<<"Glava vezane liste NIJE alocirana, ponovite mogucnost 0 za alociranje"<<endl<<endl;
										glava=new sknjiga;
										glava->sljedeci=NULL;
										}
								else cout<<"Glava vezane liste JE vec alocirana"<<endl;
								
								break;
				case 1:
								prva(glava);
								break;
				
				case 2:
                                bla=druga(glava);
                                if(bla==-1){
                                            cout<<"Glava vezane liste nije alocirana. ";
                                            break;
                                            }
								cout<<"Broj elementa vezane liste je:" <<bla<<endl;
								
								break;
                            
				case 3:
                             
                              treca(glava,mt_broj);
                              break;
                case 4:          druga(glava);
                              
                              
		
		}//switch
		system("pause");
		}while(izbor!=9);
	
	
		return 0;
}//main
  
