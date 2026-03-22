// Ulaz -> prirodni broj <1000, Izlaz -> prosti brojevi od 2 do n
#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;

int main ()
{
	system("color 03");

	short int N;
    bool prost[1000];
    
    do {
       cout << "N = ";
       cin >> N;
    } while (N < 2 || N >999);
    
    prost[0] = prost[1] = true;
    
    for (int i = 2; i <= N; i++)
        prost[i] = true;
        
    for (int k = 2; k <= sqrt(N); k++)
        if (prost[k]) {
           int l = 2;
           while (k * l <= N) 
                 prost[k * l++] = false;
        }
        
    for (int i= 2; i <= N; i++)
        if (prost[i])
           cout << i << " ";

	cout<<endl<<endl;
	system("pause");
	return 0;
}

