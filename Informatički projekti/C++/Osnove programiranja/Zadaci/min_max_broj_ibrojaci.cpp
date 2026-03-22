#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	float n, max=0, min=0;
	int brojac=0, brojacmax, brojacmin;

	do{
		cout<<"Unesi broj: ";
		cin>>n;
		if(n!=0){
			brojac++;
			if(n>max){
				brojacmax=brojac;
				max=n;
			}
			if(n<min){
				brojacmin=brojac;
				min=n;
			}
		}
	} while(n!=0);

	cout<<"Najveci broj je "<<max<<" i on je "<<brojacmax<<" uneseni broj po redu!"<<endl
		<<"Najmanji broj je "<<min<<" i on je "<<brojacmin<<" uneseni broj po redu!";

	cout<<endl<<endl;
	system("pause");
	return 0;
}

