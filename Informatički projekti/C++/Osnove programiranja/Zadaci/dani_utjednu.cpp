// Ispisati dan u tjednu s obzirom na uneseni broj
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	int x;
	
	do{
	cout<<"Unesi broj u rasponu 1-7: ";
	cin>>x;
	} while(x<1 || x>7);

	switch(x){
		case 1:
			cout<<"Ponedjeljak";
			break;
		case 2:
			cout<<"Utorak";
			break;
		case 3:
			cout<<"Srijeda";
			break;
		case 4:
			cout<<"Cetvrtak";
			break;
		case 5:
			cout<<"Petak";
			break;
		case 6:
			cout<<"Subota";
			break;
		case 7:
			cout<<"Nedjelja";
			break;
	}

	cout<<endl<<endl;
	system("pause");
	return 0;
}

