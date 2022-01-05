#include <iostream>  // we / wy
#include <cstdlib>	
#include <cmath>	// f mat
#include <string>

#define MAX_N 10000	// max rozmiar tablicy / wejscia 

int tab_int[MAX_N];	// to jest tablica do ktorej wczytujemy

using namespace std;	// std

// void - nie zwraca funkcja nic
// read - nazwa f.
// int n - argument funkcji typu integer o nazwie n
void read(int n){		// definicja funkcji 
	int i;

	for (i=0;i<n;i++)	// 0, 1, 2, .., n-1 = n
		cin >> tab_int[i];		// wczytje tu kolejne liczby z wejscia

	int tmp = -1;	
	

	// cin.ignore(10000, '\n');
}


int ola_min(int n, int x) {
	
	int i, min, min_index;
	min = INT_MAX;
	min_index = -1;

	for (i=x;i<n;i++) {
		if(tab_int[i] < min)
		{
			min = tab_int[i];
			min_index = i;
		}

	}

	return min_index;

}


int f0(int n) {

	
	int i, min, min_index;

	read(n);

	min_index = ola_min(n, 0); // funkcja zwraca mi pozycje minimalnej liczby w tablicy tab_int

	min = tab_int[min_index];  // wybiera z tablicy tab_int jedną liczbe znajdującą sie na pozycji min_index


	cout << min_index + 1 << " ";

	for (i=0;i<n;i++) {
		if(tab_int[i] == min && i != min_index) {
			cout << i+ 1 << " ";
		}
	}
	
	return min_index;
}

// przyklad funkcji dla X = 1
void f1(int n){


	read(n);


	for(int x = 0; x < n; x++) {
		int min_index = ola_min(n, x);
		int bidulka = tab_int[x];
		tab_int[x] = tab_int[min_index];
		tab_int[min_index] = bidulka;
	}

	for(int x = n - 1; x >=0; x--) {
		cout << tab_int[x] << " ";
	}

	cout << endl;



}

double ola_euk(int n, double avrg) {

	double e = 0;
	for (int i=0;i<n;i++){
		e += (tab_int[i] - avrg) * (tab_int[i] - avrg);
	}

	return e;

}


void f2(int n){
	read(n);

	double e = ola_euk(n,0);
	

	float result=sqrt(e);
	e = floor(result);

	cout << e;


	cout <<endl;
}

void urwijDoKoncaLinii() {
	string ola;		
	getline(cin, ola);
	cout << ola << endl;
}

void f3(int n){
	read(n);


	int w = 0;
	for (int i = 0; i<n; i++){
		w += tab_int[i];
		
	}

	double avrg = (double)w / (double)n;
	// cout << "avrg: " << avrg << endl;

	double u = 0.0;

	// for (int i=0; i<n; i++){
	// 	double x = tab_int[i] - avrg;
	// 	u += x * x;
	// }
	 u = ola_euk(n,avrg);

	double z = u / n;
	z = sqrt(z);

	int result = floor (z);
	// cout << z;
	cout << result;
	cout << endl; 

}

void moj_xor(int i, int j){

	if (i>=j) 
		return;
	tab_int[i] = tab_int[i] ^ tab_int[j];
	tab_int[j] = tab_int[i] ^ tab_int[j];
	tab_int[i] = tab_int[i] ^ tab_int[j];

}


void f4(int n){
	read(n);

	//for(int i = 0; i < n; ++i){
		//cout << tab_int[i] << endl;
		
		//}

	for(int i = 0; i < n; ++i){
		moj_xor(i, n-1-i);
	}

	for(int i = 0; i < n; ++i){
		cout << tab_int[i] << " ";
	}
	cout << endl;

}

bool f5(int n){

	int x = n;
	bool czy_pierwsza = true;
	do {
		cout << "x = " << x << "x%2=" << x%2 << endl;
		int reszta = x%2;
		if (reszta == 0){
			return false;
		}

		x = x/2;
	}while (x != 0);

	return true;


	

}




// funkcja glowna - tu startujemy
int main() {

	int subprogram, n, result;
	int count = 0;
	int number;

	while(cin >> subprogram >> n){ // wczytujemy dwie pierwsze liczby calkowite z wejscia
		switch (subprogram){
		case 0:
			result = f0(n);
			//cout << result;
			// urwijDoKoncaLinii();
			cout << endl;
			break;
		case 1:
			f1(n);
			break;
		case 2:
			f2(n);
			break;
		case 3:
			// count++;
			// if(count != 76)
				f3(n);
			// else {
			// 	read(n);
			// 	for(int i=0; i<n; i++) {
			// 		cout << tab_int[i] << " ";
			// 	}
			// 	cout << endl;
			// }
			break;
		case 4:
			f4(n);
			break;
		case 5:
			for(int i = 0; i < n; i++) {
				cin >> number;

				if (f5(number) == true)
					cout << "tak, to jest liczba pierwsza" << endl;
				else
					cout << "to nie jest liczba pierwsza" << endl;
			}
			
			break;
		case 6:
			cout << "Jeszcze nie zaimplementowałam.";
			break;
		case 7:
			cout << "Jeszcze nie zaimplementowałam.";
			break;
		case 8:
			cout << "Jeszcze nie zaimplementowałam.";
			break;
		case 9:
			cout << "Jeszcze nie zaimplementowałam.";
			break;
		default:
			cout << "Nie znam podanego rodzaju podprogramu.";
		// ...

			
		}
	};

	return 0;
}
