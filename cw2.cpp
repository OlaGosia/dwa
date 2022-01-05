#include <iostream>

using namespace std;

char napis[1000];

int przypisywanie ()
{
	int znak;
	int i = 0;

	while ( (znak = getchar()) != 10){	
		napis[i] = (char) znak;

		i++;

	}

	return i;
}

void wypisywanie (int n, bool odwrot)
{

	if (odwrot)
	{
		for (int i = n-1; i >= 0; --i)
		{
			cout << napis[i];
		}

	}
	else{ 
		for (int i = 0; i < n; ++i)
		{
			cout << napis[i];
		}

	}
	
	

}

bool palindrom (int n)
{
	bool czyPalindrom = true;
	for (int i = 0; i < n; ++i){
		if (napis[i] != napis[n-1-i]) {
			return false;
		}

	}
	return czyPalindrom;

}



int main(int argc, char const *argv[])
{
	while (true){
		//bool odwrot;
		int n = przypisywanie ();
		//cout << "W ktora strone?" << endl;
		//cin >> odwrot;
		//wypisywanie (n,odwrot);

		bool wynik = palindrom (n);

		if (wynik == true)
			cout << "tak, to jest palindrom" << endl;
		else
			cout << "to nie jest palindrom" << endl;

	}	

	return 0;
}