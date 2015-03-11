#include<iostream>
#include<fstream>           
using namespace std;
class cstudent{
private:
	cstudent *sljedeci;
public:
	int mat_br;
	char prez_ime[40];
	cstudent(){
		sljedeci=NULL;
	}; // konstruktor
	void unos(){
		cstudent *zadnji, *novi;
		zadnji=this;
		while (zadnji->sljedeci)
			zadnji=zadnji->sljedeci;
		novi = new cstudent;
		zadnji->sljedeci=novi;
		cout << "Maticni broj:";
		cin >> novi -> mat_br;
		cout << "Prezime i ime:";
		cin >> novi->prez_ime;
	}; // unos
	void ispis(){
		cstudent *tekuci=this->sljedeci;
		while (tekuci){
				cout << tekuci->mat_br << endl;
				cout << tekuci->prez_ime<<endl;
				tekuci=tekuci->sljedeci;
		};
	}; // ispis
	int provjeri(int mb){
		cstudent *tekuci=this->sljedeci;
		while (tekuci){
        if (tekuci->mat_br==mb) return 1;
				tekuci=tekuci->sljedeci;
		};
		return 0;
	}; // provjeri
	void broj_prijava();
};//cstudent
fstream dat;
cstudent *student;
class cprijava{
public:
	int sif_prij;
	int mat_br;
	char predmet[30];
	char rok[20];
	cprijava(){
    dat.open("prijave.dat",ios::in);
    if (!dat){
  		dat.open("prijave.dat", ios::out);
	  	dat.close();
	   	dat.clear();
		}
	} // cprijava
	void unos(){
		dat.open("prijave.dat", ios::out|ios::app|ios::binary);
  	cout << "Sifra prijave:";
  	cin >> sif_prij;
    do{
  	  cout << "Maticni_broj:";
  	  cin >> mat_br;
  	}while(student->provjeri(mat_br)==0);
  	cout << "Predmet:";
  	cin >> predmet;
  	cout << "Rok:";
  	cin >> rok;
    dat.write((char *)this,sizeof(*this));
		dat.close(); dat.clear();
	}; // unos
	void ispis(){
		dat.open("prijave.dat", ios::in|ios::binary);
		while(1){
      dat.read ((char *)this,sizeof(*this));
      if (dat.eof())break;
      cout << sif_prij << endl;
      cout << mat_br << endl;
      cout << predmet << endl;
      cout << rok << endl;
    }
		dat.close(); dat.clear();
	}; // ispis
	void trazi(int mb){
		dat.open("prijave.dat", ios::in|ios::binary);
		while(1){
      dat.read ((char *)this,sizeof(*this));
      if (dat.eof())break;
      if (mat_br==mb){
        cout << sif_prij << endl;
        cout << mat_br << endl;
        cout << predmet << endl;
        cout << rok << endl;
      }
    }
		dat.close(); dat.clear();
	}; // ispis
};//cprijava
cprijava prijava;
void cstudent::broj_prijava(){
		cstudent *tekuci=this->sljedeci;
		int brojac;
		while (tekuci){
				cout << tekuci->mat_br << endl;
				cout << tekuci->prez_ime<<endl;
				brojac=0;
    		dat.open("prijave.dat", ios::in|ios::binary);
    		while(1){
          dat.read ((char *)&prijava,sizeof(prijava));
          if (dat.eof())break;
          if (prijava.mat_br==tekuci->mat_br)brojac++;
        }
		    dat.close(); dat.clear();
		    cout << "Broj_prijava:" << brojac<< endl;
		    tekuci=tekuci->sljedeci;
		};
	}; // broj_prijava


int main(){
	int izbor,mat_br;
  student = new cstudent;
	do{
		cout << "1. Unos studenata" << endl;
		cout << "2. Ispis studenata" << endl;
		cout << "3. Unos prijava" << endl;
		cout << "4. Ispis prijava" << endl;
		cout << "5. Prijave zadanog studenta" << endl;
		cout << "6. Studenti s brojem prijava" << endl;
		cout << "9. Izlaz" << endl;
		cin >> izbor;
		switch (izbor){
			 case 1: student->unos();break;
			 case 2: student->ispis();break;
			 case 3: prijava.unos();break;
			 case 4: prijava.ispis();break;
			 case 5:  cout << "Maticni broj:";cin >> mat_br;
                prijava.trazi(mat_br);break;
			 case 6: student->broj_prijava();break;

		} // switch

	}while (izbor!=9);
	return 0;
}



