#include <iostream>
#include <fstream>
#include "biblioteka_tel_imenik.cc"
#include <cmath>


using namespace std;

struct troba{
	int br_roba;
	char naziv[30];
	float cijena;
	float kolicina;
	float vrijeme;
};


int Prost(int x){ //3
    int i,j,prost;
    for(i=x-1;i>1;i--){
                       prost=1;
                       for(j=2;j<=sqrt(i);j++){
                           if(i%j==0){
                                      prost=0;
                                      break;
                                      }//if
                           }//for(j)
    if(prost) return i;
    }//for(i)
    return 0;
}//funkcija za prosti broj

bool postoji;
void provjera(){
     
	fstream dat("roba_Musliu_Dino.dat",ios::in|ios::binary); //citanje datoteke
	if (!dat) cout<<"Datoteka ne postoji!"<<endl;postoji=false;
    if(dat.is_open())cout<<"Datoteka postoji na disku!"<<endl<<endl;postoji=true;
 
}//provjera

void prvi(){ //1

     provjera();
     troba roba;
     fstream dat("roba_Musliu_Dino.dat",ios::out|ios::binary);
     cout<<"Koliki je broj zapisa: ";
     roba.br_roba=0;
     roba.naziv[0]='\0';
     roba.cijena=0;
     roba.vrijeme=0;
     int broj;
     cin>>broj;
     for(int i=0;i<broj;i++) dat.write((char*)&roba,sizeof(troba));
     dat.close();
     dat.clear();
     cout<<"Velicina datoteke u broju zapisa je: "<<broj<<endl;
     cout<<"Prvi manji prosti broj od velicine datoeke je: "<<Prost(broj)<<endl;

}//funkcija za prvi zadatak

void ispis(){
    troba roba;
    fstream dat2("roba_Musliu_Dino.dat",ios::in|ios::binary);
    while(1){
              dat2.read((char*)&roba,sizeof(troba));
              if(dat2.eof())break;
              //if(roba.br_roba>0){
              cout<<"----ELEMENT----"<<endl;
              cout<<"Sifra= "<<roba.br_roba<<endl;
              cout<<"Naziv= "<<roba.naziv<<endl;
              cout<<"Cijena= "<<roba.cijena<<endl;
              cout<<"Vrijeme= "<<roba.vrijeme<<endl<<endl;
              }
              //}
    dat2.close();
    dat2.clear();
}//ispis

int drugi(){//4
     int rbz=0;
     
     troba roba;
     troba roba2;
     provjera();
     if(postoji==false) return 0;
     fstream dat("roba_Musliu_Dino.dat",ios::in|ios::out|ios::binary);

     vrijeme_pocetak();
     cout<<"Broj robe: ";
     cin>>roba.br_roba;
     cout<<"Naziv: ";
     unos(roba.naziv);
     do{
     cout<<"Cijena: ";
     cin>>roba.cijena;
     }while(roba.cijena<1);
     do{
     cout<<"Kolicina: ";
     cin>>roba.kolicina;
     }while(roba.kolicina<1);
     vrijeme_kraj();
     roba.vrijeme=(int)vrijeme_proteklo()/1000;
     cout<<"Potrebno vrijeme je: "<<roba.vrijeme<<" s."<<endl;
     
     dat.seekg(0,ios::end);
     rbz=dat.tellg()/sizeof(troba);
     cout<<rbz<<endl;
     int prosti=Prost(rbz);
     cout<<prosti<<endl;
     rbz=roba.br_roba%prosti;
     cout<<"Redni broj zapisa u datoteci je: "<<rbz<<endl;
     dat.seekp(rbz*sizeof(troba));
     dat.write((char*)&roba,sizeof(troba));
     dat.close();
     dat.clear();
     ispis();
}//drugi

int treci(){
    
    troba roba;
    provjera();
    if(postoji==false) return 0;
    fstream dat("roba_Musliu_Dino.dat",ios::in|ios::out|ios::binary);
    int br;

    //dat.seekg (0, ios::end);
    //cout << "Velicina datoteke (b): " << dat.tellg() << endl;   
    stanje_dat_objekta(dat);
    cout<<"\nUnesite sifru robe: ";
    cin>>br;
    if(br<100|br>999)return 0;
    
    int rbz=0;
    dat.seekg(0,ios::end);
    rbz=dat.tellg()/sizeof(troba);
    int prost=Prost(rbz);
    rbz=br%prost;
    cout<<"Redni broj zapisa: "<<rbz<<endl;
    dat.seekp(rbz*sizeof(troba));
    
    dat.read((char*)&roba,sizeof(troba));
    
    if(roba.br_roba>0){
                       cout<<"DUPLIKAT!!!\n\n";
                       return 0;
                       }
    
    if(br==roba.br_roba){
                       cout<<"Naziv= "<<roba.naziv<<endl;
                       cout<<"Cijena= "<<roba.cijena<<endl;
                       cout<<"Vrijeme= "<<roba.vrijeme<<endl<<endl;
                       return 0;
                           }//if
    if(roba.br_roba==0){
                       cout<<"Zapis je prazan!"<<endl<<endl;
                       return 0;
                       }//if

    dat.close();
    dat.clear();
}//funkcija za 3

int cetvrti(){
    troba roba;
    troba roba2;
    provjera();
    if(postoji==false) return 0;
    fstream dat("roba_Musliu_Dino.dat",ios::in|ios::out|ios::binary);
    
     vrijeme_pocetak();
     cout<<"Broj robe: ";
     cin>>roba.br_roba;
     cout<<"Naziv: ";
     unos(roba.naziv);
     cout<<"Cijena: ";
     cin>>roba.cijena;
     cout<<"Kolicina: ";
     cin>>roba.kolicina;
     vrijeme_kraj();
     roba.vrijeme=(int)vrijeme_proteklo()/1000;
     cout<<"Potrebno vrijeme je: "<<roba.vrijeme<<" s."<<endl;
     int rbz=0;
     dat.seekg(0,ios::end);
     rbz=dat.tellg()/sizeof(troba);
     int prosti=Prost(rbz);
     rbz=roba.br_roba%prosti;
     dat.seekp(rbz*sizeof(troba));
     dat.read((char*)&roba2,sizeof(troba));
     
     if(roba2.br_roba>0)cout<<"DUPLIKAT! \n Redni broj zapisa duplikata je: "<<rbz<<endl;
     dat.seekp(0);
     do{
        dat.read((char*)&roba2,sizeof(troba));
        }while(roba2.br_roba>0);
     rbz=(dat.tellg()/sizeof(troba))-1;
     cout<<"Novi redni broj zapisa je: "<<rbz<<endl;
     dat.seekp(rbz*sizeof(troba));
     dat.write((char*)&roba,sizeof(troba));
     dat.seekp(0);
     ispis();
     
     dat.close();
     dat.clear();
}//funkcija za 4

int main(){
	int izbor;
	do{
        system("cls");
		cout<<"1. Kreiranje datoteke praznih zapisa"<<endl;
		cout<<"2. Unos podataka o robi u relativnu datoteku (bez obzira na duplikate)"<<endl;
		cout<<"3. Pretraživanje relativne datoteke"<<endl;
		cout<<"4. Unos podataka o robi u relativnu datoteku (vodi raèuna o duplikatima)"<<endl;
		cout<<"9. Izlaz iz programa"<<endl;
		cout<<"Izbor: ";
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
		}
	system("pause");
			
	}while(izbor!=9);
	
	return 0;
}
