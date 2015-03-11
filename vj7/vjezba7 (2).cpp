#include <iostream>
#include <fstream>
#include "biblioteka_tel_imenik.cc"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string.h>
#include <stdio.h>
using namespace std;
struct tstudent {
    int maticni;
    char prezimeime[30], datum[10];
    tstudent*sljedeci;
};
tstudent*lista=new tstudent;
int brojac2;
int brojac3;
int provjera(char naziv[]="studenti_Vrevic_Armin.dat") {
    ifstream dat(naziv);
    if(dat.is_open()) {
        cout<<"Datoteka je uspjesno otvorena! \n";
        dat.close();
        dat.clear();
        return 1;
    }
    dat.close();
    dat.clear();
    return 0;
}
int prvi() {
    tstudent student;
    if(!provjera()) {
        ofstream dat("studenti_Vrevic_Armin.dat");
        cout<<"Kreirana je nova datoteka!\n";
        dat.close();
        dat.clear();
    }
    fstream dat("studenti_Vrevic_Armin.dat",ios::in|ios::out|ios::ate);
    cout<<"Odaberite opciju: \n";
    cout<<"1. Upisivanje pojedinog zapisa\n";
    cout<<"2. Generiranje zapisa\n";
    int izbor;
    cin>>izbor;
    if(izbor==1) {
        cout<<"Maticni= ";
        cin>>student.maticni;
        cout<<"Prezime i ime: ";
        unos(student.prezimeime);
        cout<<"Datum= ";
        unos(student.datum);
        dat.write((char*)&student,sizeof(tstudent));
        dat.close();
        dat.clear();
        return 0;
    }
    cout<<"Koliko zapisa zelite generirati? ";
    int izbor2;
    cin>>izbor2;
    int maticni;
    char maticni2[5];
    char dd2[2],mm2[2],ggg2[4];
    for(int i=0; i<izbor2; i++) {
        char *datum=new char[10];
        student.maticni=rand()%30000+20000;
        student.datum[0]='\0';
        maticni=rand()%30000+20000;
        strcpy(student.prezimeime,"student_");
        itoa (maticni,maticni2,10);
        strcat(student.prezimeime,maticni2);
        int dd=rand()%28+1, mm=rand()%12+1, ggg=rand()%30+1979;
        itoa(dd,dd2,10);
        datum[0]='\0';
        student.datum[0]='\0';
        strcat(datum,dd2);
        itoa(mm,mm2,10);
        int vel=strlen(datum);
        datum[vel]='.';
        datum[vel+1]='\0';
        strcat(datum,mm2);
        itoa(ggg,ggg2,10);
        int vel2=strlen(datum);
        datum[vel2]='.';
        datum[vel2+1]='\0';
        strcat(datum,ggg2);
        vel=strlen(datum);
        strcpy(student.datum,datum);
        delete[] datum;
        dat.write((char*)&student,sizeof(tstudent));
    }
    dat.close();
    dat.clear();
}
int drugi() {
    tstudent student;
    int izbor;
    cout<<"Unesite naziv datoteke: ";
    char naziv[40];
    unos(naziv);
    if(!provjera(naziv)) {
        cout<<"Datoteka s tim nazivom ne postoji!\n";
        return 0;
    }
    fstream dat("studenti_Vrevic_Armin.dat",ios::in|ios::out);
    dat.seekg(0,ios::end);
    int velicina=dat.tellg()/sizeof(tstudent);
    cout<<"Velicina datoteke u broju zapisa je: "<<velicina<<endl;
    brojac3=velicina;
    cout<<"Odaberite opciju: \n";
    cout<<"1. Ucitavanje sadrzaja datoteke u odgovarajucu vezanu listu\n";
    cout<<"2. Ispis sadrzaja liste \n";
    cin>>izbor;
    tstudent*zadnji=lista;
    if(izbor==1) {
        lista->sljedeci=NULL;
        zadnji->sljedeci=NULL;
        cout<<"DEALOCIRANA JE VEZANA LISTA!\n";
        fstream dat("studenti_Vrevic_Armin.dat",ios::in|ios::out);
        dat.seekg(0);
        brojac2=0;
        while(1) {
            dat.read((char*)&student,sizeof(tstudent));
            //if(dat.eof())break;
            if(brojac2==brojac3)break;
            tstudent*novi=new tstudent;
            novi->maticni=student.maticni;
            strcpy(novi->prezimeime,student.prezimeime);
            strcpy(novi->datum,student.datum);
            zadnji->sljedeci=novi;
            zadnji=novi;
            brojac2++;
        }
        zadnji->sljedeci=NULL;
        cout<<"BROJAC= "<<brojac2<<endl;
        dat.close();
        dat.clear();
        return 0;
    }
    if(lista->sljedeci==NULL) {
        cout<<"LISTA JE PRAZNA!\n";
        dat.close();
        dat.clear();
        return 0;
    }
    zadnji=zadnji->sljedeci;
    while(zadnji) {
        cout<<"\nELEMENT\n-------------\n";
        cout<<"Maticni= "<<zadnji->maticni<<endl;
        cout<<"Prezime i ime= "<<zadnji->prezimeime<<endl;
        cout<<"Datum = ";
        for(int i=0; i<10; i++)cout<<zadnji->datum[i];
        cout<<endl;
        zadnji=zadnji->sljedeci;
    }
    dat.close();
    dat.clear();
    return 0;
}
void treci() {
    cout<<"Izaberite opciju: \n";
    cout<<"1. Uzlazno sortiranje vezane liste\n";
    cout<<"2. Silazno sortiranje vezane liste\n";
    int izbor;
    cin>>izbor;
    if(izbor==1) {
        vrijeme_pocetak();
        tstudent *prethodni,*tekuci,*sljedeci;
        int indikator,brojac=0;
        do {
            indikator = 0;
            tekuci=lista->sljedeci;
            prethodni=lista;
            while (tekuci->sljedeci) {
                sljedeci=tekuci->sljedeci;
                if (tekuci->maticni > sljedeci->maticni) {
                    prethodni->sljedeci=sljedeci;
                    tekuci->sljedeci=sljedeci->sljedeci;
                    sljedeci->sljedeci=tekuci;
                    indikator=1;
                }//if
                prethodni=prethodni->sljedeci;
                tekuci=prethodni->sljedeci;
            }//while
        } while (indikator==1);
        vrijeme_kraj();
    }
    else {
        vrijeme_pocetak();
        tstudent *prethodni,*tekuci,*sljedeci;
        int indikator,brojac=0;
        do {
            indikator = 0;
            tekuci=lista->sljedeci;
            prethodni=lista;
            while (tekuci->sljedeci) {
                sljedeci=tekuci->sljedeci;
                if (tekuci->maticni < sljedeci->maticni) {
                    prethodni->sljedeci=sljedeci;
                    tekuci->sljedeci=sljedeci->sljedeci;
                    sljedeci->sljedeci=tekuci;
                    indikator=1;
                }//if
                prethodni=prethodni->sljedeci;
                tekuci=prethodni->sljedeci;
            }//while
        } while (indikator==1);
        vrijeme_kraj();
    }
    cout<<"Broj elemenata u listi je: "<<brojac2<<endl;
    cout<<"Vrijeme koje je bilo potrebno da se sortira lista: "<<vrijeme_proteklo()<<endl;
}
void cetvrti() {
    cout<<"Odaberite jednu od opcija: ";
    cout<<"1. Sortiranje datoteke u uzlaznom redoslijedu \n";
    cout<<"2. Sortiranje datoteke u silaznom redoslijedu\n";
    int izbor;
    cin>>izbor;
    if(izbor==1) {
        vrijeme_pocetak();
        tstudent slog1,slog2,pom;
        int broj_zapisa,i,j;
        //1.utvrditi koliko je zapisa veæ u datoteci
        fstream dat ("studenti_Vrevic_Armin.dat",ios::in|ios::out|ios::binary);// U/I datoteka
        dat.seekg (0, ios::end);
        broj_zapisa=dat.tellg()/sizeof(tstudent);
        for (j=0; j<broj_zapisa-1; j++)	// više prolaza (broj_zapisa-1)
            for (i=0; i<broj_zapisa-1; i++) {
                dat.seekg(i*sizeof(tstudent)); //pozicija za èitanje datoteke.
                dat.read ((char *)&slog1,sizeof(tstudent)); // uzastopni zapisi
                dat.read ((char *)&slog2,sizeof(tstudent));
                if (slog1.maticni>slog2.maticni) {
                    dat.seekp(i*sizeof(tstudent)); //pozicija za upis u datoteku
                    dat.write ((char *)&slog2,sizeof(tstudent)); // zapis u
                    dat.write ((char *)&slog1,sizeof(tstudent)); // obrnutom redoslijedu
                }//if
            }//for
        dat.close();
        dat.clear();
        vrijeme_kraj();
        cout <<"\nUkupan broj zapisa:"<<broj_zapisa<<endl;
        cout <<"Vrijeme sortiranja:"<<vrijeme_proteklo()<<endl;
    }
    else {
        vrijeme_pocetak();
        tstudent slog1,slog2,pom;
        int broj_zapisa,i,j;
        //1.utvrditi koliko je zapisa veæ u datoteci
        fstream dat ("studenti_Vrevic_Armin.dat",ios::in|ios::out|ios::binary);// U/I datoteka
        dat.seekg (0, ios::end);
        broj_zapisa=dat.tellg()/sizeof(tstudent);
        for (j=0; j<broj_zapisa-1; j++)	// više prolaza (broj_zapisa-1)
            for (i=0; i<broj_zapisa-1; i++) {
                dat.seekg(i*sizeof(tstudent)); //pozicija za èitanje datoteke.
                dat.read ((char *)&slog1,sizeof(tstudent)); // uzastopni zapisi
                dat.read ((char *)&slog2,sizeof(tstudent));
                if (slog1.maticni<slog2.maticni) {
                    dat.seekp(i*sizeof(tstudent)); //pozicija za upis u datoteku
                    dat.write ((char *)&slog2,sizeof(tstudent)); // zapis u
                    dat.write ((char *)&slog1,sizeof(tstudent)); // obrnutom redoslijedu
                }//if
            }//for
        dat.close();
        dat.clear();
        vrijeme_kraj();
        cout <<"\nUkupan broj zapisa:"<<broj_zapisa<<endl;
        cout <<"Vrijeme sortiranja:"<<vrijeme_proteklo()<<endl;
    }

}
int main() {
    int izbor;
    lista->sljedeci=NULL;
    do {
        cout<<"1. Rucni unos zapisa/generiranje zapisa datoteke\n";
        cout<<"2. Kopiranje sadrzaja datoteke u odgovarajucu vezanu listu/ispis sadrzaja vezane liste\n";
        cout<<"3. Sortiranje vezane liste uzlazno/silazno\n";
        cout<<"4. Sortiranje datoteke uzlazno/silazno\n";
        cout<<"9. Izlaz iz programa\n";
        cin>>izbor;
        system("cls");
        switch(izbor) {
        case 1:
            prvi();
            break;
        case 2:
            drugi();
            break;
        case 3:
            if(!lista->sljedeci) cout<<"Dodajte prvo elemente u listu\n";
            else treci();
            break;
        case 4:
            cetvrti();
            break;
        }
    }
    while(izbor!=9);
    return 0;
}
