// Potrebno je sortirati brojeve od najmanjeg prema najvecem
// 2. SKORO  NAJBRZEEE
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
		int max=0;
		
		for(int j=1; j<=i; j++){
			if(polje[j] > polje[max]){    // promijeniti znak < za sortirati od max do min
				max=j;
			}
		}
		
		if(max==i) continue;
		
		int pom=polje[i];
		polje[i]=polje[max];
		polje[max]=pom;
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

