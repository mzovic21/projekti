// Ulaz 2 decimalna broja i znak, izlaz raèunska operacija ta 2 broja
// Primjer kalkulatora
#include<iostream>
#include<conio.h>
using namespace std;
int main ()
{
	system("color 03");

	float x,y;
	char znak;

	start:cout<<"Unesi prvi broj: ";
	cin>>x;
	cout<<"Unesi drugi broj: ";
	cin>>y;
	cout<<"Unesi znak: ";
	cin>>znak;
	
	switch(znak){
		case '+':
			cout<<x+y;
			break;
		case '-':
			cout<<x-y;
			break;
		case '*':
			cout<<x*y;
			break;
		case '/':
			cout<<x/y;
			break;
		default:
			cout<<"Kriva aritmeticka operacija!";
	}

	cout<<endl<<endl;
	system("pause");
	goto start;
	return 0;
}
