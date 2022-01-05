#include <iostream>
using namespace std;

int main() {
	int stopy;
	double metry;
	double przelicznik = 0.3;
	cout << "Podaj wysokoc w stopach:";
	cin >> stopy;
	metry = stopy*przelicznik;
	cout <<stopy<< "stop to jest:" << metry <<"metrow\n";

}