// Potrebno je sortirati brojeve od najmanjeg prema najvecem
// 3.  OKEJ JEEE
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

	
	
	for(int i=n-1; i>0; i--){
		for(int c=0; c<i; c++){
			if(polje[c] > polje[i]){   // promijeniti znak < za sortirati od max do min
				int pom=polje[c];
				polje[c]=polje[i];
				polje[i]=pom;
			}
		}
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

