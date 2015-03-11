#include <iostream>
#include <cmath>
#include "biblioteka_vrijeme.cc"
#include <windows.h>
using namespace std;
int n,brojtrokuta=0,krivibroj=0;
bool alocirana=false;
class ctrokut {
private:
    float s;
    cvrijeme polje2;
public:
    string naziv;
    float a,b,c;
    float povrsina() {
        s=(a+b+c)/2;
        float P= sqrt(s*(s-a)*(s-b)*(s-c));
        return P;
    }
    void unos() {
    	polje2.pocetak();
        cout<<"Unesite naziv trokuta: ",cin>>naziv;
		cout<<"a= ",cin>>a;
        cout<<"b= ",cin>>b;
        cout<<"c= ",cin>>c;
        polje2.kraj();
    }
    void ispis() {
        cout<<"Naziv= "<<naziv<<endl<<"a= "<<a<<endl<<"b= "
		<<b<<endl<<"c= "<<c<<endl<<"Vrijeme= "<<polje2.proteklo()<<endl;
    }
};
ctrokut*polje;
ctrokut*polje3;
bool prvi() {
    if(alocirana) 
        cout<<"Polje je vec alocirano! \nVelicina polja= "<<n<<endl;
    if(alocirana)for(int i=0;i<brojtrokuta;i++)
									polje->ispis();
    if(alocirana)if(brojtrokuta==0)cout<<"Nije unesen niti jedan element!\n\n";
    if(alocirana)return 0;
    cout<<"Broj elemenata = ";
    cin>>n;
    alocirana=true;
    polje=new ctrokut[n];
    polje3=new ctrokut[n];
}
bool drugi() {
    if(!alocirana)cout<<"Polje nije alocirana!\n\n";
	if(!alocirana)return 0;
    cout<<"Broj alociranih elemenata polja trokuta je: "<<n<<endl;
    cout<<"Broj upisanih trokuta je: "<<brojtrokuta<<endl;
    if(brojtrokuta==n)cout<<"Unijeli ste previse trokutova\n";
    if(brojtrokuta==n)return 0;
    bool tocanunos;
    do {
        tocanunos=true;
        ctrokut*trokut=new ctrokut;
        trokut->unos();
        if(!(trokut->a+trokut->b>trokut->c))tocanunos=false;
        else if(!(trokut->b+trokut->c>trokut->a))tocanunos=false;
        else if(!(trokut->a+trokut->c>trokut->b))tocanunos=false;
        if(!tocanunos) 
            cout<<"Niste unijeli trokut!\n",polje3[krivibroj]=*trokut,krivibroj++;
        else 
            polje[brojtrokuta]=*trokut,
            brojtrokuta++,
            delete trokut;
    }
    while(!tocanunos);
}
bool treci() {
	if(brojtrokuta==0)return 0;
    cout<<"PODACI KOJI SU DOBRO UNESENI \n-------------\n";
    for(int i=0; i<brojtrokuta; i++) 
        cout<<"\nELEMENT\n---------\n",
        polje[i].ispis(),
        cout<<"Povrsina= "<<polje[i].povrsina()<<endl;
    cout<<"KRIVO UNESENI PODACI\n-----------\n";
    for(int i=0; i<krivibroj; i++) 
        cout<<"\nELEMENT\n---------\n",
        polje3[i].ispis();
}
bool cetvrti() {
    cout<<"Unesite naziv trokuta: ";
    string naziv2;
    cin>>naziv2;
    for(int i=0; i<brojtrokuta; i++) 
        if(naziv2==polje[i].naziv) {
            polje[i].ispis();
            cout<<"Povrsina= "<<polje[i].povrsina()<<endl;
            cout<<"Odaberite jednu od opcija: \n--------\n";
            cout<<"1. Promjena naziva\n2. Promjena stranice a\n3. Promjena stranice b\n4. Promjena stranice c\n";
            int izbor2;
            cin>>izbor2;
            if(izbor2==1)cout<<"Unesite novi naziv: ",cin>>polje[i].naziv;
            else if(izbor2==2)cout<<"Unesite novu stranicu a: ",cin>>polje[i].a;
            else if(izbor2==3)cout<<"Unesite novu stranicu b: ",cin>>polje[i].b;
            else if(izbor2==4) cout<<"Unesite novu stranicu c: ",cin>>polje[i].c;
            bool tocanunos=true;
            if(!(polje[i].a+polje[i].b>polje[i].c))tocanunos=false;
            else if(!(polje[i].b+polje[i].c>polje[i].a))tocanunos=false;
            else if(!(polje[i].a+polje[i].c>polje[i].b))tocanunos=false;
            if(!tocanunos) 
                cout<<"OVO VISE NIJE TROKUT!!!\n",
                polje[i].ispis();
            if(!tocanunos)return 0;
            cout<<"TROKUT\n----\n";
            polje[i].ispis();
            cout<<"Povrsina= "<<polje[i].povrsina()<<endl;
            return 0;
        }
}
int main()
{
    int izbor;
    do {
    	cout<<"\n\n======================\nIZBORNIK\n";
        cout<<"1. Dinamièka alokacija polja trokuta i polja vremena\n";
        cout<<"2. Unos podataka o trokutima\n";
        cout<<"3. Ispis podataka o svim unesenim trokutima\n";
        cout<<"4. Ispravak podataka o trokutima\n";
        cout<<"9. Izlaz iz programa\n";
        cin>>izbor;
        system("cls");
        if(izbor==1)prvi();
        else if(izbor==2)drugi();
        else if(izbor==3)treci();
        else if(izbor==4)cetvrti();
    }
    while(izbor!=9);
    return 0;
}
