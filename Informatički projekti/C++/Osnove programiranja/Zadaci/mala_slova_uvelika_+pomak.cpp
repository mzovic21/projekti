// Unijeti tekst, pretvoriti mala slova u velika, pomaknuti sva slova za n mjesta, ispisati taj tekst
#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;

int main ()
{
	system("color 03");

	char tekst[1000];
	int pomak;

	cout<<"Unesi tekst: "<<endl;
	//tu ne ide cin.ignore(); jer je ovo prvi ulazni podatak, za sve ostale bi trebalo ici
	cin.getline(tekst, 1000);
	do{
		cout<<"Unesi pomak: ";
		cin>>pomak;
	} while(pomak<1 || pomak>25);
	
	int duljina=strlen(tekst);

	for(int i=0; i<duljina; i++){
		if(tekst[i]>='a' && tekst[i]<='z'){
			tekst[i]-=32;
		}
		if(tekst[i]>='A' && tekst[i]<='Z'){
			tekst[i]+=pomak;
			if(tekst[i]>'Z'){
				tekst[i]-=26;
			}
		}
	}
	
	cout<<tekst;

	cout<<endl<<endl;
	system("pause");
	return 0;
}

