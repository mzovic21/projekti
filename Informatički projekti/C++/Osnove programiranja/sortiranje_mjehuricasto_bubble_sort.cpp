// Potrebno je sortirati brojeve od najmanjeg prema najvecem
// 4.  NAJSPORIJIIII   ZADNJI
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	int n, polje[100];

	do{
		cout<<"Unesi broj brojeva: ";
		cin>>n;
	} while(n<1 || n>100);

	for(int i=0; i<n; i++){
		cout<<"Novi broj: ";
		cin>>polje[i];
	}

	
	
	while(true){
		bool zamjena=false;
		
		for(int i=0; i<n-1; i++){
			if(polje[i] > polje[i+1]){   // promijeniti znak < za sortirati od max do min
				zamjena=true;
				int pom=polje[i];
				polje[i]=polje[i+1];
				polje[i+1]=pom;
			}
		}
		
		if(!zamjena) break;
	}
	
	
	
	int i;
	for(i=0; i<n-1; i++){
		cout<<polje[i]<<", ";
	}
	cout<<polje[i];

	cout<<endl<<endl;
	system("pause");
	return 0;
}

