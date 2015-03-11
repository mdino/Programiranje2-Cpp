// MD5:LgGU70iExg7P7t+mSXZzPg==// Verifikator 3.14// Program:vjezba1// Opis zadatka:vj1// Autor:Dino Musliu// Poèetno vrijeme:8.10.2012. 17:21:25// Završno vrijeme:8.10.2012. 18:15:56// IP:fe80::717a:2021:6b7a:177a%11 ( 1540 )// #:#include <iostream>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevoðenja:48/7#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;

float povrsina(float sirina, float visina){
      
      float p;
      p=sirina*visina;
      return p;
}
float povrsina(float radijus){
   float p;
   p=radijus*radijus*3.14;
   return p;
}

float povrsina(float a, float b, float c){
   float p;
   p=a*b*c;
   return p;
}

int main(){
  int brojac=0;
  
	struct trokuti{
		float a;
		float b;
		float c;
	};
	
	trokuti vise_trokuta[100];
	
	int izbor;
	float sirina,visina,radijus,a,b,c;
	do{
	  cout<<"Izbornik\n";
  	cout<<"1. Povrsina pravokutnika\n";
	  cout<<"2. Povrsina kruga\n3. Povrsina trokuta ( po Heronovoj formuli )\n4. Ispis polja trokuta\n9. Izlaz\n";
  	cout<<"izbor: ";
  	cin >>izbor;
  	switch(izbor){
	  		case 1: 
		  	          vrijeme_pocetak();
		  	          cout<<"Sirina= ";
 		  	          cin>>sirina;
     	  		      cout<<"Visina= ";
     	  		      cin>>visina;
      		  	    if(sirina<=0){
    	  		          cout<<"Sirina je manja od nula!\n";
          		  	    break;
          		  	    }
    	  		      if(visina<=0){
      		  	       cout<<"Visina je manja od nula!\n";
       	  		       break;
       	  		      }
      		  	    cout<<"Povrsina pravokutnika je: "<<povrsina(sirina,visina)<<endl;
    	  		      vrijeme_kraj();
      		  	    cout<<"Vrijeme potrebno za unos stranica i izracun povrsine pravokutnika je: "<<vrijeme_proteklo()/1000<<" sekundi\n";
						 break;
 				case 2:
				     vrijeme_pocetak();
				     cout<<"Unesite radijus: ";
     				 cin>>radijus;
 				     if(radijus<=0){
     				    cout<<"Radijus je manji od nula!\n";
    				     break;
 				     }
     				 cout<<"Povrsina kruga je: "<<povrsina(radijus)<<endl;
 				     vrijeme_kraj();
     				 cout<<"Vrijeme potrebno za unos stranica i izracun povrsine pravokutnika je: "<<vrijeme_proteklo()/1000<<" sekundi\n";
				     break;
     	  case 3:
  	         vrijeme_pocetak();
         	   cout<<"a: ";
  	         cin>>a;
  	         cout<<"b :";
         	   cin>>b;
         	   cout<<"c: ";
   	         cin>>c;
         	   
   	         if(a<=0 || b<=0 || c<=0){
         	   		cout<<"Jedna od stranica je krivo unesena. ";
		   	        break;		
         	   }
   	         
         	   if(a>b)
   	         	if(a>c){
	         	      if(a<(b+c)){
      	         	   cout<<"Stranice ne cine trokut!\n";
   	         	       break;
	         	      }
   	         	}
         	   
   	         if(b>a)
         	   	if(b>c){
	   	           if(b<(a+c)){
           	   	    cout<<"Stranice ne cine trokut!\n";
    	   	           break;
	   	           }
         	   	}
   	         
         	   if(c>a)
   	          if(c>b){
          	      if(c<(a+b)){
      	             cout<<"Stranice ne cine trokut!\n";
             	      break;
          	      }
   	          }
  	         vise_trokuta[brojac].a=a;
         	   vise_trokuta[brojac].b=b;
   	         vise_trokuta[brojac].c=c;
         	   brojac++;
         	   cout<<"Povrsina trokuta je: "<<povrsina(a,b,c)<<endl;
   	         vrijeme_kraj();
         	   cout<<"Vrijeme potrebno za unos stranica i izracun povrsine trokuta je: "<<vrijeme_proteklo()/1000<<" sekundi\n";
  	         break;
        case 4:
             for(int i=0;i<brojac;i++){
             	cout<<"Ispisujem podatke za "<<i+1<<". trokut\n----------------\n";
	            cout<<"Stranica a= "<<vise_trokuta[i].a<<endl;
            	cout<<"Stranica b= "<<vise_trokuta[i].b<<endl;
	            cout<<"Stranica c= "<<vise_trokuta[i].c<<endl;
            	cout<<"Povrsina ovog trokuta je: "<<povrsina(vise_trokuta[i].a,vise_trokuta[i].b,vise_trokuta[i].c)<<endl;
             }
             break;
  	}
	  system("pause");
	  system("cls");
	}while(izbor!=9);
	system("pause");
	return 0;
}
