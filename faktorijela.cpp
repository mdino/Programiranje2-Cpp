int fakto (int n){
	if (n ==1)			// sidreni uvjet
		return 1;
	else
		return n*fakto (n – 1);       // pojednostavljenje i rekurzivni poziv
}
void main () {
	cout << fakto (5) << endl;
}
