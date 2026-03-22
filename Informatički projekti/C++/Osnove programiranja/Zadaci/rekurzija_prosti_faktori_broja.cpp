#include<iostream>

using namespace std;

bool prvi = true;

void prosti_faktori(int N, int M = 2)
{
	if (M > N) return;

	if (N % M == 0)
	{
		if (!prvi) 
			cout << "*";
		prvi = false;
		cout << M;
		N /= M;

		if (N % M == 0)
		{
			prosti_faktori(N, M);
			return;
		}
	}

	prosti_faktori(N, M + 1);
}

int main() {

	int N;
	do {
		cout << "Broj: ";
		cin >> N;
	} while (N < 1);

	prosti_faktori(N);

	cout << endl;
	system("pause");
	return 0;
}
