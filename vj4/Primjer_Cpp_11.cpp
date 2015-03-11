//Primjer za C++11
#include <iostream>
#include <chrono>
using namespace std;

int main(){
  char a;
  auto vrijeme1 = chrono::high_resolution_clock::now();
  for (int i=0; i<1000000000; ++i)
  { 
        //milijarda iteracija 
  }
  chrono::nanoseconds trajanje = chrono::high_resolution_clock::now() - vrijeme1;
  cout << "Ukupno vrijeme iznosi: " << trajanje.count() << " nanosekundi.\n"; 
  
  cin >> a;
}
