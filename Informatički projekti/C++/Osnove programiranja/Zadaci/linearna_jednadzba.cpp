// Ulaz 3 decimalna broja, izlaz korijen jednadžbe a*x na kv +b*x+c=0
// Linearna jednadzba 
#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;

int main ()
{
	system("color 03");

	float a,b,c;

	start:cout<<"Unesi prvi broj: ";
	cin>>a;
	cout<<"Unesi drugi broj: ";
	cin>>b;
	cout<<"Unesi treci broj: ";
	cin>>c;

	if(a==0){
		if(b!=0){
			cout<<"Rjesenje iznosi: "<<-c/b;
		}
		else{
			if(c==0){
				cout<<"Beskonacno mnogo rjesenja!";
			}
			else{
				cout<<"Nema rjesenja  :(";
			}
		}
	}
	else{
		float D=pow(b,2)-4*a*c;
		if(D>=0){
			cout<<"Prvo rjesenje iznosi: "<<(-b+sqrt(D))/(2*a)<<endl
				<<"Drugo rjesenje iznosi: "<<(-b-sqrt(D))/(2*a);
		}
		else{
			cout<<"Prvo rjesenje iznosi: "<<-b/(2*a)<<"+"<<sqrt(-D)/(2*a)<<"*i"<<endl
				<<"Drugo rjesenje iznosi: "<<-b/(2*a)<<"-"<<sqrt(-D)/(2*a)<<"*i";
		}
	}

	cout<<endl<<endl;
	system("pause");
	goto start;
	return 0;
}

