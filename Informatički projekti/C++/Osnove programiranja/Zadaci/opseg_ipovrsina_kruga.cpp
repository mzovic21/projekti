// Izracunati opseg i povrsinu kruga bez biblioteke cmath
#include<iostream>
#include<conio.h>
#define pi 3.14
using namespace std;

int main ()
{
	system("color 03");

	int rad;

	do{
		cout<<"Unesi radijus kruga: ";
		cin>>rad;
	} while(rad<1);
	
	cout<<"Opseg kruga iznosi: "<<2*rad*pi<<endl
		<<"Povrsina kruga iznosi: "<<rad*rad*pi;

	cout<<endl<<endl;
	system("pause");
	return 0;
}

