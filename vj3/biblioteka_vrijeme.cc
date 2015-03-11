//Mjerenje proteklog vremena u tisuæinkama sekundi
#include<time.h>
clock_t vrijeme1,vrijeme2;
double razlika;
double vrijeme_pocetak(){
  vrijeme1=clock();
	return (double)vrijeme1;
};
double vrijeme_kraj(){
	vrijeme2=clock();
	return (double)vrijeme2;
};
double vrijeme_proteklo(){
	razlika=vrijeme2-vrijeme1;
	return razlika;
};
