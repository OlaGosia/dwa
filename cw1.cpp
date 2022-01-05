#include <iostream>

using namespace std;

unsigned int buda = 8;
int modyfikatory[9];

void pisanie (float kotek, unsigned int buda, bool uzycModyfikatorow)
{
	for (int i = 0; i < buda; ++i)
	{
		
		if (uzycModyfikatorow)
		{
			cout << i;
			cout << "      " << modyfikatory[i];
			cout << "      " << kotek + modyfikatory[i] << endl;

		} else {
			cout << kotek << endl;
		}


	}	

}

void inicjalizacja (int czekolada);

int main(int argc, char const *argv[])
{
	unsigned int buda = 9;
	float kotek = 1.00;
	int czekolada = 0;
	bool uzycModyfikatorow;
	cout << "Czy mm uzyc modyfikatorow? (1/0)" <<endl;
	cin  >> uzycModyfikatorow;
	cout << "Podaj wartosc dla czekolady"<< endl;
	cin >> czekolada; 
	cout << "Podaj warotsc z kropka dla kotka" << endl;
	cin >> kotek;
	inicjalizacja (czekolada);
	pisanie(kotek, buda, uzycModyfikatorow);
	/* code */
	return 0;
}

void inicjalizacja(int czekolada) 
{
	for (int i = 0; i < 9; ++i)
	{
		modyfikatory[i] = (czekolada + i) * (czekolada + i);
	}

}