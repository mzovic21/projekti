#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;


int main() {

	int N;
	bool prvi = true;

	do {
		cout << "Broj: ";
		cin >> N;
	} while (N < 1);

	for (int i = 2; i <= sqrt(N); i++)
		while (N % i == 0) {
			N /= i;
			if (!prvi)
				cout << "*";
			prvi = false;
			cout << i;
		}

	if (N > 1) {
		if (!prvi)
			cout << "*";
		cout << N;
	}

	cout << endl;
	system("pause");
	return 0;
}
