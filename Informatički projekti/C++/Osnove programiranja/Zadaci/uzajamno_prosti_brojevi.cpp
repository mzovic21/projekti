#include<iostream>

using namespace std;

/*
Ulaz: N i N brojeva. N je prirodni broj.
Izlaz: Za svaki par susjeda potrebno je odrediti radi li se o uzajamno prostim brojevima.
Treba ispisati proste parove
Ulazni podaci : 7 5 7 2 14 17 18 4

Izlaz 5,7
7,2
14,17
17,18
*/

int *polje;

// Da bi 'a' uvijek bio veæi od 'b'!
void zamijeni(int &a, int &b)
{
int c = a;
a = b;
b = c;
}

bool uzajamno_prosti(int a, int b)
{
zamijeni(a, b);
for (int i = 2; i <= a; i++)
{
if (a%i == 0 && b%i == 0)
{
return false;
}
}
return true;
}

int main(){

int N;
do {
cout << "Broj brojeva? >> ";
cin >> N;
} while (N < 1);

polje = new int [N];

for (int i = 0; i < N; i++) cin >> polje[i];

for (int i = 0; i < N-1; i++)
{
if (uzajamno_prosti(polje[i], polje[i+1]))
{
cout << polje[i] << ", " << polje[i+1] << endl;
}
}

cout << endl;
system("pause");
return 0;
}
