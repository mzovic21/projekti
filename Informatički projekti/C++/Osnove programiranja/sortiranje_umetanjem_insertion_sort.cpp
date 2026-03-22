// Potrebno je sortirati brojeve od najmanjeg prema najvecem
// 1.  NAJBRZEEEEE
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

	
	
	for(int i=1; i<n; i++){
		int j=i-1;
		int pom=polje[i];
		
		while(j>=0 && polje[j] > pom){   // promijeniti znak < za sortirati od max do min
			polje[j+1]=polje[j];
			j--;
		}
		polje[j+1]=pom;
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

