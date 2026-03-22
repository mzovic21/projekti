// Korisnik unosi kodove ASCII koda, ispisati velika slova, dok ostala ne
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	int n;

	do{
		cout<<"Unesi kod: ";
		cin>>n;
		
		if(n>=65 && n<=90){
			cout<<char(n)<<endl;
		}
	} while(n!=0);

	cout<<endl<<endl;
	system("pause");
	return 0;
}

