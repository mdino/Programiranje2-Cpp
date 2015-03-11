#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
//#include "biblioteka_tel_imenik.cc"
#include <cmath>

using namespace std;

int br_zapisa;

struct troba{
	int br_roba;
	char naziv[30];
	float cijena;
	float vrijeme_unosa;
};

int postoji(){
	fstream dat;
	dat.open("roba_Musliu_Dino.dat",ios::in|ios::binary);
	if (!dat){
		br_zapisa=0;
		dat.open("roba_Musliu_Dino.dat",ios::out|ios::binary);
	else if(dat.is_open()){	
	 cout<<"Datoteka uspjesno otvorena!"<<endl;
	}
	}	
}//int postoji

int main(){
	int izbor;
	do{
		cout<<"1. Kreiranje datoteke praznih zapisa"<<endl;
		cout<<"2. Unos podataka o robi u relativnu datoteku (bez obzira na duplikate)"<<endl;
		cout<<"3. Pretraživanje relativne datoteke"<<endl;
		cout<<"4. Unos podataka o robi u relativnu datoteku (vodi raèuna o duplikatima)"<<endl;
		cout<<"9. Izlaz iz programa"<<endl;
		cout<<"Izbor: ";
		cin>>izbor;
		
		switch(izbor){
			case 1:
				postoji();
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;	
		}
			
	}while(izbor!=9);
	
	return 0;
}
