
#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int N;
	do {
		cout << "Unesite broj rijeci: ";
		cin >> N;
	} while (N < 1);
	cin.ignore();

	char(*polje)[20] = new char[N][20]; // Alociramo 20*N bajtova u memoriji za naše polje (dinamièka alokacija).

	for (int i = 0; i < N; i++)
	{
		cout << "Unesite " << i + 1 << ". rijec: ";
		cin.getline(polje[i], 20);
	}

	for (int i = N - 1; i > 0; i--)
	{
		int Max = 0;

		for (int c = 1; c <= i; c++)
			if (strcmp(polje[Max], polje[c]) < 0) Max = c; // ovako ispisuje ispravno rijeèi himne
                                                                                                                      // ispravno je i ovako "== -1"
		if (i != Max)
		{
			char pom[20] = { 0 };
			strcpy(pom, polje[i]);
			strcpy(polje[i], polje[Max]);
			strcpy(polje[Max], pom);
		}
	}

	cout << "_______________________" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << polje[i] << endl;
	}

	delete[] polje; 

	cout << endl;
	system("pause");
	return 0;
}
