// Bitovni operatori ILI, I, negacija (| & ~)
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
  int a = 6545;
  int b = 4453;
  char c[23]; // polje u kojem završavaju binarne znamenke
  cout << "a,b" << endl;
  cout << itoa(a,c,2) << endl; // Pretvaranje broja (a) u niz binarnih znamenki (c)
  cout << itoa(b,c,2) << endl;
  cout << "Bitovni ILI operator a|b" << endl;
  cout << itoa(a|b,c,2) << endl;
  cout << "Bitovni I operator a&b" << endl;
  cout << itoa(a&b,c,2) << endl;
  cout << "Komplement (negacija) ~a" << endl;
  //Komplement je nad sva 32 bita!
  cout << itoa(~a,c,2) << " binarno ili " << ~a << " decimalno" <<endl;
  cin >> a;
}
