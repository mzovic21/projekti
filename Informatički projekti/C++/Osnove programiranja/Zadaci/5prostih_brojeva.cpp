// Korisnik unosi broj n veci od 10, ispisuje se prvih 5 prostih brojeva iza n
#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;

int main ()
{
	system("color 03");

	int n;

	do{
		cout<<"Unesi broj: ";
		cin>>n;
	} while(n<=10);

	int brojac=0;
	
	for(int i=n; brojac<5; i++){
		bool prost=true;
		
		for(int j=2; j<=sqrt(i) && prost; j++){
			if(i%j==0){
				prost=false;
			} 
		}
		if(prost){
			cout<<++brojac<<". broj: "<<i<<endl;
		}
	}
		
	cout<<endl<<endl;
	system("pause");
	return 0;
}

