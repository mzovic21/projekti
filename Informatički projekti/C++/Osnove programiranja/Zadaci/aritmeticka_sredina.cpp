// Aritmetièka sredina unesenih brojeva
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	int n;
	float x,z=0;

	do{
		cout<<"Unesi broj: ";
		cin>>n;
	} while(n<1);

	for(int i=0; i<n; i++){
		cout<<"Novi broj: ";
		cin>>x;
		z+=x;
	}
	
	cout<<"Aritmeticka sredina iznosi: "<<z/n;

	cout<<endl<<endl;
	system("pause");
	return 0;
}

