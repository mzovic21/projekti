// Ispisati ACII vrijednost znaka
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	char znak;

	start:cout<<"Unesi slovo/znak: ";
	cin>>znak;

	cout<<int(znak);
	
	cout<<endl<<endl;
	system("pause");
	goto start;
	return 0;
}
