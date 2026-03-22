// Potrebno je izracunati sumu svih pozitivnih parnih unesenih brojeva
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	int n, zbroj=0;

	do{
		cout<<"Unesi broj: ";
		cin>>n;
		
		if(n>1 && n%2==0){
			zbroj+=n;
		}
	} while(n!=0);

	cout<<"Zbroj parnih pozitivnih brojeva iznosi "<<zbroj;

	cout<<endl<<endl;
	system("pause");
	return 0;
}

